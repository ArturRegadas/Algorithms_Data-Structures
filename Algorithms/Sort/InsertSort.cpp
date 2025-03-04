#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAXN 1e9
using namespace std;


void insertSort(int array[], int size){
    for(int i =0;i<size;++i){
        int j = i - 1;
        int value = array[i];
        while(j>=0 && value<array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = value;
    }
}
void printArray(int array[], int size){
    for(int i =0;i<size;++i){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[] = {5,3,4,1,2};
    insertSort(array, 5);
    printArray(array, 5);
}