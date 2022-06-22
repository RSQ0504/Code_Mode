//
//  main.cpp
//  Insertion Sort
//
//  Created by David Qian on 2021/3/30.
//

#include <iostream>
using namespace std;
void print(const int *a,const int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insertionsort(int *A,const int size)
{
    for(int i=0;i<size;i++){
        int tempt=A[i];//pick the element at index i and find its right palce among A[0],...A[i-1]
        int j;
        for(j=i-1;j>=0;j--){
            if(A[j]>tempt)
                A[j+1]=A[j];
            else
                break;
        }
        A[j+1]=tempt;//Hpw insert the element that was at index i,in its right location;whcih is at index j+1
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
    int A[] = {6,9,2,7,5,4,8,2,4,1};
    cout<<"orginal array";
    print(A,10);
    insertionsort(A, 10);
    cout<<"Sorted array";
    print(A, 10);
    int b;
    cin>>b;
    cout<<binarySearch(A,10,b)<<endl;
    system("pause");
    return 0;
    
}
