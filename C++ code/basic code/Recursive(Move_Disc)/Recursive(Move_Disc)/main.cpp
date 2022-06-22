//
//  main.cpp
//  Recursive(Move_Disc)
//
//  Created by David Qian on 2021-10-07.
//

#include <iostream>
using namespace std;

void move(const int& n,const char& a,const char& c,const char& b){
    if(n==1){
        cout<<"Move top disc from peg "<<a<<" to peg "<<c<<endl;
    }
    else{
        move(n-1,a,b,c);
        move(1,a,c,b);
        move(n-1,b,c,a);
    }
}

int main(){
    cout<<"How many discs would you like to move?"<<endl;
    int n;
    cin>>n;
    move(n,'A','C','B');
    return 0;
}
