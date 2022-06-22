#include<string.h>
#include<iostream>
using namespace std;
class buyer{                                                    //基类
protected:
    string name;                                                //姓名
    int buyerID;                                                //购书人编号
    string adress;                                              //地址
    double pay;                                                 // 购书费用
public:
    buyer(string n="",int b=0,string a="",double p=0);
    string getbuyname();                                        //输出姓名
    string getaddress();                                        //输出地址
    double getpay();                                           //输出应付费用
    int getid();                                                //输出购书人编号
    virtual void display()=0;                                   //显示对象
    virtual void setpay(double=0)=0;                            //计算购书的费用
};
class member:public buyer{                                      //会员
private:
    int leaguer_grade;                                          //会员等级
public:
    member(string n="",int b=0,int l=0,string a="",double p=0):buyer(n,b,a,p){
        leaguer_grade=1;                                        //构造函数
    }
    void display();                                             //显示
    void setpay(double p);
    member *next;
};
class honoured_guest:public buyer{                               //贵宾
    double discount_rate;                                        //折扣
public:
    honoured_guest(string n="",int b=0,double r=10,string a="",double p=0):buyer(n,b,a,p){
        discount_rate=r;                                         //构造函数
    }
    void display();                                              //显示
    void setpay(double p);                                       //计算购书费用
    honoured_guest *next;
};
class layfolk:public buyer{
public:
    layfolk(string n="",int b=0,string a="",double p=0):buyer(n,b,a,p){};
    void display();
    void setpay(double p);
    layfolk *next;
};
