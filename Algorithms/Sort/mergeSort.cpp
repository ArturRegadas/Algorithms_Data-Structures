#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAXN 1e9
using namespace std;

void merge(int array[], int l, int m, int r){
    int aArray[r-l+1];
    ++m;
    int il = l;
    int im = m;
    int ir = r;
    int i=0;
    while(l <= im && m <=r ){
        if(array[l]<array[m]){
            aArray[i]=array[l];
            l++;
        }
        else{
            aArray[i] = array[m];
            m++;
        }
        i++;
    }
    for(int j =l;j<=im;++j)aArray[i+(j-l)] = array[j];
    for(int j = m;j<=ir;++j)aArray[i+(j-m)] = array[j];

    for(int i =il;i<=ir;i++)array[i] = aArray[i-il];
}


void mergeSort(int array[], int l, int r){
    if(l>=r)return;
    int m = l+(r-l)/2;
    mergeSort(array, l, m);
    mergeSort(array, m+1, r);

    merge(array,l, m, r);


}
void printArray(int array[], int size){
    for(int i =0;i<size;++i){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[] = {5,3,4,1,2};
    mergeSort(array, 0, 5-1);
    printArray(array, 5);
}