#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAXN 1e9
using namespace std;


void bubbleSort(int array[], int size){
    for(int i =0;i<size;++i){
        for(int j = 0;j<size;++j)if(array[i]<array[j])swap(array[i],array[j]);
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
    bubbleSort(array, 5);
    printArray(array, 5);
}