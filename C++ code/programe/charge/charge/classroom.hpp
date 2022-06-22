//
//  classroom.hpp
//  charge
//
//  Created by 钱荣晟 on 2020/6/29.
//  Copyright © 2020 钱荣晟. All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;
class classroom{
private:
    int day;
    int cnumber;
    int time;
    string teacher;
    string classname;
public:
    classroom(int d=0,int n=0,int ti=0,string t="0",string c="0"){
        day=d;
        cnumber=n;
        teacher=t;
        classname=c;
        time=ti;
    }
    ~classroom();
    int getnumber(){return cnumber;}
    int gettime(){return time;}
    int getday(){return day;}
    string getteacher(){return teacher;}
    string getclassname(){return classname;}
    void display(){
        cout<<"教室编号："<<cnumber<<endl;
        cout<<"周几上课："<<day<<endl;
        cout<<"第几节大课"<<time<<endl;
        cout<<"教师姓名："<<teacher<<endl;
        cout<<"教授课程："<<classname<<endl;
    }
    classroom *next;
};


