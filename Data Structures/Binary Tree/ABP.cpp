#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

void printVector(vector<int> a){
    for(int i =0;i<a.size()-1;i++)cout<<a[i]<<" ";
    cout<<a.back()<<"\n";
}


class node{
    public:
    int value;
    node* left, *right, *parent;
    node(int v) : value(v), left(nullptr), right(nullptr), parent(nullptr){}
};

class binaryTree{
    private:
    node* root;
    node* nullnode;

    node* getMaxNode(node* current){
        if(current->right)return getMaxNode(current->right);
        return current;
    }

    void recursiveAdd(node* current, int v){
        if(v<current->value && current->left)return recursiveAdd(current->left, v);
        if(v>=current->value && current->right)return recursiveAdd(current->right, v);
        if(v<current->value){
            current->left = new node(v);
            current->left->parent=current;
        }
        else{
            current->right = new node(v);
            current->right->parent=current;
        }
    };

    node* recursiveFind(node* current, int v){
        if(current->value == v)return current;
        if(v<current->value && !current->left)return nullnode;
        if(v>=current->value && !current->right)return nullnode;
        if(v<current->value)return recursiveFind(current->left, v);
        else return recursiveFind(current->right, v);
    }

    void Remove(node* current, node* parent, int v){
        if (!current || current->value == -1) return;

        if (!current->left && !current->right) { 
            if (current == this->root) {
                this->root->value = -1;
            }
            else if (v < parent->value) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
            return;
        }

        if (current->left && !current->right) { 
            if (current == this->root) {
                this->root = current->left;
                this->root->parent = nullptr;
            }
            else if (v < parent->value) {
                parent->left = current->left;
            }
            else {
                parent->right = current->left;
            }
            current->left->parent = parent;
            return;
        }

        if (!current->left && current->right) { 
            if (current == this->root) {
                this->root = current->right;
                this->root->parent = NULL;
            }
            else if(v < parent->value) {
                parent->left = current->right;
            }
            else {
                parent->right = current->right;
            }
            current->right->parent = parent;
            return;
        }

        node* maxNode = getMaxNode(current->left);
        swap(current->value, maxNode->value);
    
        node* maxParent = maxNode->parent;
        if (maxParent->right == maxNode) {
            maxParent->right = maxNode->left;
            if(maxNode->right)maxNode->right->parent = maxParent;
        }
        else{
            maxParent->left = maxNode->left;
        }
        
        if (maxNode->left)maxNode->left->parent = maxParent;


    }

    void recursivePrefix(vector<int>& a, node* current){
        if(root->value == -1)return;
        a.push_back(current->value);
        if(current->left)recursivePrefix(a, current->left);
        if(current->right)recursivePrefix(a, current->right);
    }
    void recursiveInfix(vector<int>& a, node* current){
        if(root->value == -1)return;
        if(current->left)recursiveInfix(a, current->left);
        a.push_back(current->value);
        if(current->right)recursiveInfix(a, current->right);
    }
    void recursivePosfix(vector<int>& a, node* current){
        if(root->value == -1)return;
        if(current->left)recursivePosfix(a, current->left);
        if(current->right)recursivePosfix(a, current->right);
        a.push_back(current->value);
    }


    public:
    binaryTree(int r): root(new node(r)), nullnode(new node(-1)) {}

    int getRootValue(){return this->root->value;}
    
    void AddToTree(int v){
        recursiveAdd(this->root, v);
    }
    bool InTree(int v){
        return recursiveFind(this->root, v)->value != -1;
    }

    void RemoveToTree(int v){
        node* pos = recursiveFind(this->root, v);
        if(pos->value == -1)return;
        Remove(pos, pos->parent, v);
    }
    
    void prefix(){
        vector<int> ans;
        recursivePrefix(ans, this->root);
        printVector(ans);
    }
    void posfix(){
        vector<int> ans;
        recursivePosfix(ans, this->root);
        printVector(ans);
    }
    void infix(){
        vector<int> ans;
        recursiveInfix(ans, this->root);
        printVector(ans);
    }

};

int main(){
    int val;
    string command;
    binaryTree bt(-1);
    while(cin>>command){
        if(command == "I"){
            cin>>val;
            if(bt.getRootValue() == -1)bt = binaryTree(val);
            else bt.AddToTree(val);
        }
        if(command == "P"){
            cin>>val;
            if(bt.InTree(val))cout<<val<<" existe\n";
            else cout<<val<<" nao existe\n";
        }
        if(command == "R"){
            cin>>val;
            bt.RemoveToTree(val);
        }
        if(command == "INFIXA"){
            bt.infix();
        }
        if(command == "POSFIXA"){
            bt.posfix();
        }
        if(command == "PREFIXA"){
            bt.prefix();
        }
    }

    return 0;
}