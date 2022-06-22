//
//  main.cpp
//  Bubble sort
//
//  Created by 钱荣晟 on 2021/2/2.
//

#include <iostream>
using namespace std;

void bubblesort(int *A,const int size){
    for(int i=0;i<size;i++){
        int count=0;
        //Bubble the largest element among A[0],....A[size-1-i]up to its position at A[size-1-i]
        for(int j=0;j<size-1-i;j++){
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                count++;
            }
        }
        if(count==0) break;
        //If there was no any swapping then the array is already
    }
}

int binarySearch(const int A[],const int size,const int searchValue){
    /*
     This function will search the array A for the searchValue.
     We assume the elements of A are already sorted in increasing order.
     Because the elements of A are sorted,we can just check the middle element and than
     eliminate half of the array and search only the half that may contain the search value
     */
    int startIndex=0,lastIndex=size-1;
    while(startIndex<=lastIndex){
        int middleIndex=(startIndex+lastIndex)/2;
        if(A[middleIndex]==searchValue) return middleIndex;
        else if(A[middleIndex]>searchValue) lastIndex=middleIndex-1;
        else startIndex=middleIndex+1;
    }
    return -1;
}
int main(){
    int a[]={6,9,2,7,5,4,8,2,4,1};
    cout<<"orginal array";
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    bubblesort(a,10);
    cout<<"answer is";
    for(int b=0;b<10;b++){
        cout<<a[b]<<" ";
    }
    cout<<"the max is="<<a[9]<<endl;
    int b;
    cin>>b;
    cout<<binarySearch(a,10,b)<<endl;;
    return 0;
}
