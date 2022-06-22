//
//  computer.hpp
//  charge
//
//  Created by 钱荣晟 on 2020/6/29.
//  Copyright © 2020 钱荣晟. All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;
class computer{
private:
    int number;
    string peizhi;
    string location;
    string state;
    string name;
    string studentid;
    string usingtime;
public:
    computer(int i=0,string j="0",string l="0",string s="0",string n="0",string st="0",string u="0"){
        number=i;
        peizhi=j;
        location=l;
        state=s;
        name=n;
        studentid=st;
        usingtime=u;
    }
    int getnumber(){return number;}
    string getpeizhi(){return peizhi;}
    string getlocation(){return location;}
    string getstate(){return state;}
    string getname(){return name;}
    string getstudentid(){return studentid;}
    string getusingtime(){return usingtime;}
    void display(){
        cout<<"使用时间段"<<usingtime<<endl;
        cout<<"使用者姓名"<<name<<endl;
        cout<<"使用者学号"<<studentid<<endl;
        cout<<"所在位置（教室/排/列）:"<<location<<endl;
        cout<<"电脑编号："<<number<<endl;
        cout<<"电脑配置"<<peizhi<<endl;
        cout<<"电脑状态"<<state<<endl;
    }
    ~computer();
    computer *next;
    
};
