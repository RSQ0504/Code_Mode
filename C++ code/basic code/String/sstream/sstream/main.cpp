//
//  main.cpp
//  sstream
//
//  Created by David Qian on 2021/6/15.
//

#include <iostream>
#include <sstream>

using namespace std;
int main(){
    string tempt;
    stringstream ss;
    float i=3.14159;
    
    ss.clear();
    ss<<i;
    ss>>tempt;
    //将各种数据类型转化为string
    cout<<tempt;
    return 0;
}
