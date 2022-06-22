//
//  main.cpp
//  charge
//
//  Created by 钱荣晟 on 2020/6/29.
//  Copyright © 2020 钱荣晟. All rights reserved.
#include<iostream>
#include<string>
#include"computer.hpp"
#include"classroom.hpp"
#include<fstream>
using namespace std;
computer*head=NULL;
classroom*Head=NULL;                                                       //设定全局变量
int y=1;
void incomputer(){                                                        //输入数据并且存进文件；
    computer *p1,*p2;int a;string b,c,d,e,f,g;
    if(head==NULL){
        cout<<"输入电脑编号：";cin>>a;cout<<"输入电脑配置：";cin>>b;cout<<"输入电脑位置：";cin>>c;cout<<"输入电脑状态：";cin>>d;
        cout<<"学生姓名：";cin>>e;cout<<"学生学号：";cin>>f;cout<<"使用时间：";cin>>g;cout<<"1。继续输入   2.结束";cin>>y;
        ofstream fout("/Users/qianrongsheng/Desktop/程序 /charge/charge/computer.txt",ios::app);
            if ( ! fout)
              {
              cout <<"文件不能打开"<<endl;
              }
              else
              {
              fout << "电脑编号:"<<a<<endl<<"电脑配置："<<b<<endl<<"电脑位置："<<c<<endl<<"电脑状态："<<d<<endl<<"学生姓名："<<e<<endl<<"学生学号："<<f<<endl<<"使用时间："<<g<<endl;
              fout.close();
        }
        head=p1=p2=new computer(a,b,c,d,e,f,g);
        while(y==1){
            cout<<"输入电脑编号：";cin>>a;cout<<"输入电脑配置：";cin>>b;cout<<"输入电脑位置：";cin>>c;cout<<"输入电脑状态：";cin>>d;
                   cout<<"学生姓名：";cin>>e;cout<<"学生学号：";cin>>f;cout<<"使用时间：";cin>>g;cout<<"1。继续输入   2.结束";cin>>y;
            ofstream fout("/Users/qianrongsheng/Desktop/程序 /charge/charge/computer.txt",ios::app);
                if ( ! fout)
                  {
                  cout <<"文件不能打开"<<endl;
                  }
                  else
                  {
                  fout << "电脑编号:"<<a<<endl<<"电脑配置："<<b<<endl<<"电脑位置："<<c<<endl<<"电脑状态："<<d<<endl<<"学生姓名："<<e<<endl<<"学生学号："<<f<<endl<<"使用时间："<<g<<endl;
                  fout.close();
            }
            p1=new computer(a,b,c,d,e,f,g);
            p2->next=p1;
            p2=p1;
        }
        p2->next=NULL;
    }else{
         for(p2=head;p2->next!=NULL;p2=p2->next);
        cout<<"输入电脑编号：";cin>>a;cout<<"输入电脑配置：";cin>>b;cout<<"输入电脑位置：";cin>>c;cout<<"输入电脑状态：";cin>>d;
        cout<<"学生姓名：";cin>>e;cout<<"学生学号：";cin>>f;cout<<"使用时间：";cin>>g;cout<<"1。继续输入   2.结束";cin>>y;
        ofstream fout("/Users/qianrongsheng/Desktop/程序 /charge/charge/computer.txt",ios::app);
            if ( ! fout)
              {
              cout <<"文件不能打开"<<endl;
              }
              else
              {
              fout << "电脑编号:"<<a<<endl<<"电脑配置："<<b<<endl<<"电脑位置："<<c<<endl<<"电脑状态："<<d<<endl<<"学生姓名："<<e<<endl<<"学生学号："<<f<<endl<<"使用时间："<<g<<endl;
              fout.close();
        }
        p1=new computer(a,b,c,d,e,f,g);
        p2->next=p1;
        p2=p1;
        while(y==1){
            cout<<"输入电脑编号：";cin>>a;cout<<"输入电脑配置：";cin>>b;cout<<"输入电脑位置：";cin>>c;cout<<"输入电脑状态：";cin>>d;
                   cout<<"学生姓名：";cin>>e;cout<<"学生学号：";cin>>f;cout<<"使用时间：";cin>>g;cout<<"1。继续输入   2.结束";cin>>y;
            ofstream fout("/Users/qianrongsheng/Desktop/程序 /charge/charge/computer.txt",ios::app);
                if ( ! fout)
                  {
                  cout <<"文件不能打开"<<endl;
                  }
                  else
                  {
                  fout << "电脑编号:"<<a<<endl<<"电脑配置："<<b<<endl<<"电脑位置："<<c<<endl<<"电脑状态："<<d<<endl<<"学生姓名："<<e<<endl<<"学生学号："<<f<<endl<<"使用时间："<<g<<endl;
                  fout.close();
            }
            p1=new computer(a,b,c,d,e,f,g);
            p2->next=p1;
            p2=p1;
        }
        p2->next=NULL;
    }
};
void inclassroom(){                                                       //输入数据并且存进文件；
    classroom *p1,*p2;int a,b,c;string d,e;
    if(Head==NULL){
        cout<<"周几上课：";cin>>a;cout<<"教室号：";cin>>b;cout<<"上课时间段：";cin>>c;cout<<"教室姓名：";cin>>d;
        cout<<"课程名称：";cin>>e;cout<<"1。继续输入   2.结束";cin>>y;
        ofstream out("/Users/qianrongsheng/Desktop/程序 /charge/charge/classroom.txt",ios::app);
            if ( ! out)
              {
              cout <<"文件不能打开"<<endl;
              }
              else
              {
                  out << "周几上课："<<a<<endl<<"教室号："<<b<<endl<<"上课时间段："<<c<<endl<<"教师姓名："<<d<<endl<<"课程名称："<<e<<endl;
              out.close();
        }
        Head=p1=p2=new classroom(a,b,c,d,e);
        while(y==1){
            cout<<"周几上课：";cin>>a;cout<<"教室号：";cin>>b;cout<<"上课时间段：";cin>>c;cout<<"教室姓名：";cin>>d;
            cout<<"课程名称：";cin>>e;cout<<"1。继续输入   2.结束";cin>>y;
            ofstream out("/Users/qianrongsheng/Desktop/程序 /charge/charge/classroom.txt",ios::app);
                if ( ! out)
                  {
                  cout <<"文件不能打开"<<endl;
                  }
                  else
                  {
                   out << "周几上课："<<a<<endl<<"教室号："<<b<<endl<<"上课时间段："<<c<<endl<<"教师姓名："<<d<<endl<<"课程名称："<<e<<endl;
                  out.close();
            }
            p1=new classroom(a,b,c,d,e);
            p2->next=p1;
            p2=p1;
        }
        p2->next=NULL;
    }else{
         for(p2=Head;p2->next!=NULL;p2=p2->next);
       cout<<"周几上课：";cin>>a;cout<<"教室号：";cin>>b;cout<<"上课时间段：";cin>>c;cout<<"教室姓名：";cin>>d;
        cout<<"课程名称：";cin>>e;cout<<"1。继续输入   2.结束";cin>>y;
        ofstream out("/Users/qianrongsheng/Desktop/程序 /charge/charge/classroom.txt",ios::app);
            if ( ! out)
              {
              cout <<"文件不能打开"<<endl;
              }
              else
              {
              out << "周几上课："<<a<<endl<<"教室号："<<b<<endl<<"上课时间段："<<c<<endl<<"教师姓名："<<d<<endl<<"课程名称："<<e<<endl;
              out.close();
        }
        p1=new classroom(a,b,c,d,e);
        p2->next=p1;
        p2=p1;
        while(y==1){
           cout<<"周几上课：";cin>>a;cout<<"教室号：";cin>>b;cout<<"上课时间段：";cin>>c;cout<<"教室姓名：";cin>>d;
            cout<<"课程名称：";cin>>e;cout<<"1。继续输入   2.结束";cin>>y;
            ofstream out("/Users/qianrongsheng/Desktop/程序 /charge/charge/classroom.txt",ios::app);
                if ( ! out)
                  {
                  cout <<"文件不能打开"<<endl;
                  }
                  else
                  {
                  out <<"周几上课："<<a<<endl<<"教室号："<<b<<endl<<"上课时间段："<<c<<endl<<"教师姓名："<<d<<endl<<"课程名称："<<e<<endl;
                  out.close();
            }
            p1=new  classroom(a,b,c,d,e);
            p2->next=p1;
            p2=p1;
        }
        p2->next=NULL;
    }
};
void outclassroombyteacher(){
    string i;
    cout<<"输入教师姓名";
    cin>>i;                                                             //输入查找对象
    classroom *p;
    for(p=Head;p->next!=NULL;p=p->next){
        if(i==p->getteacher()){
            p->display();
        }
    }
}
void outclassroombynumber(){
    int i;
    cout<<"输入教室编号";
    cin>>i;
    classroom *p;
       for(p=Head;p->next!=NULL;p=p->next){
           if(i==p->getnumber()){
               p->display();
           }
       }
}
void outcomputerbystudent(){
    string i;
    cout<<"输入学生学号";
    cin>>i;
    computer *p;
    for(p=head;p->next!=NULL;p=p->next){
        if(i==p->getstudentid()){
            p->display();
        }
    }
}
void outcomputerbynumber(){
    int  i;
    cout<<"电脑编号";
    cin>>i;
    computer *p;
    for(p=head;p->next!=NULL;p=p->next){
        if(i==p->getnumber()){
            p->display();
        }
    }
}
void outclassroom(){
    string i;
    ifstream fin("/Users/qianrongsheng/Desktop/程序 /charge/charge/classroom.txt");
    if(!fin){
        cout <<"文件不能打开"<<endl;
    }else{
        while(getline(fin,i)){
               cout<<i<<endl;
           }
           fin.close();
    }
}
void outcomputer(){
    string i;
    ifstream fi("/Users/qianrongsheng/Desktop/程序 /charge/charge/computer.txt");
    if(!fi){
        cout <<"文件不能打开"<<endl;
    }else{
         while(getline(fi,i)){
                      cout<<i<<endl;
                  }
                  fi.close();
    }
}
void in(){
    int i;
    A:cout<<"1.电脑使用记录。   2.教室排课";
    cin>>i;
    switch (i) {
        case 1:
            incomputer();
            break;
        case 2:
            inclassroom();
            break;
        default:
            cout<<"看题目啊呆瓜"<<endl;
            goto A;
            break;
    }
}
void out(){
    int i;
    A:cout<<"1.通过教师查找排课信息。   2.通过教室号查找排课信息。   3通过学生查找电脑记录。    4通过电脑查找使用记录。   5。导出全部教室信息。     6导出全部电脑信息";
    cin>>i;
    switch (i) {
        case 1:
            outclassroombyteacher();
            break;
        case 2:
            outclassroombynumber();
            break;
        case 3:
            outcomputerbystudent();
            break;
        case 4:
            outcomputerbynumber();
            break;
        case 5:
            outclassroom();
            break;
        case 6:
            outcomputer();
            break;
        default:
            cout<<"看题目啊呆瓜"<<endl;
            goto A;
            break;
    }
}
int main(){
    int i;
    A:cout<<"1.输入数据。   2.输出查找数据";
    cin>>i;
    switch (i) {
        case 1:
            in();
            goto A;
            break;
        case 2:
            out();
            goto A;
            break;
        default:
            cout<<"看题目啊呆瓜"<<endl;
            goto A;
            break;
    }
    return 0;
}
