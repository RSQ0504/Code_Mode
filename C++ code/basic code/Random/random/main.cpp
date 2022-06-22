//
//  main.cpp
//  random
//
//  Created by 钱荣晟 on 2021/1/26.
//

#include <iostream>
#include <cstdlib>
#include <ctime>//library to use time
#include <cmath>

using namespace std;
int main(){
    int i;
    cout<<"how many number do you want?"<<endl;
    cin>>i;
    srand(time(nullptr));//use current time as seed
    for(int j=0;j<i;j++){
    int r=rand()%9+-3;//r [-3,5]
    cout<<r<<endl;
    }
    system("paue");
    return 0;
    
}
