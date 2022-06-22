#include<iostream>
#include"class.h"
#include<string.h>
using namespace std;
buyer::buyer(string n,int b,string a,double p){
    name=n;                                                //姓名
    buyerID=b;                                                //购书人编号
    adress=a;                                              //地址
    pay=p;
}
string buyer::getbuyname(){return name;}
string buyer::getaddress(){return adress;}
double buyer::getpay(){return pay;}
int buyer::getid(){return buyerID;}
void member::display(){
    cout<<"购书者姓名"<<name<<endl;
    cout<<"购书者编号"<<buyerID<<endl;
    cout<<"VIP等级"<<leaguer_grade<<endl;
    cout<<"地址"<<adress<<endl;
}
void member::setpay(double p){
    if(leaguer_grade==1){
        pay=pay+p*0.9;
    }else if(leaguer_grade==2){
        pay=pay+p*0.8;
    }else if(leaguer_grade==3){
        pay=pay+p*0.7;
    }else if(leaguer_grade==4){
        pay=pay+p*0.6;
    }else{
        pay=pay+p*0.5;
    }
}
void honoured_guest::display(){
    cout<<"购书者姓名"<<name<<endl;
    cout<<"购书者编号"<<buyerID<<endl;
    cout<<"贵宾折扣"<<discount_rate<<"折"<<endl;
    cout<<"地址"<<adress<<endl;
}
void honoured_guest::setpay(double p){
    pay=pay+discount_rate*0.1*pay;
}
void layfolk::display(){
    cout<<"购书者姓名"<<name<<endl;
    cout<<"购书者编号"<<buyerID<<endl;
    cout<<"普通客户"<<endl;
    cout<<"地址"<<adress<<endl;
}
void layfolk::setpay(double p){
    pay=pay+p;
}
