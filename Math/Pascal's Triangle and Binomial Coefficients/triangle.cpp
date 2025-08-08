//Pascal's Triangle with matrix in cpp
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getTriangle(int n){
    vector<vector<int>> ans(n, vector<int>(n, 0));
    ans[0][0] = 1;
    for(int i =1; i<n; i++){
        for(int j =0; j<=i; j++){
            if(j==0)
                ans[i][j] = ans[i-1][j];
            else if(j == i)
                ans[i][j] = ans[i-1][j-1];
            
            else
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> pascalTriangle = getTriangle(7);
    for(int i =0; i<7; i++){
        for(int j =0; j<7; j++){
            cout<<pascalTriangle[i][j]<<" ";
        }
        cout<<endl;
    }
}