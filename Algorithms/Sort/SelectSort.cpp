#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAXN 1e9
using namespace std;

int Min(int i, int array[], int size){
    int MIN = MAXN;
    int ans = i;
    for(int j = i; j<size; j++){
        if(MIN>array[j]){
            MIN = array[j];
            ans = j;
        }
    }
    return ans;

}

void selectSort(int array[], int size){
    for(int i =0;i<size;++i){
        swap(array[i], array[Min(i, array, size)]);
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
    selectSort(array, 5);
    printArray(array, 5);
}