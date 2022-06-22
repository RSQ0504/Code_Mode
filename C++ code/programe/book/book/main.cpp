#include<iostream>
#include<string.h>
#include"book.h"
#include"class.h"
using namespace std;
layfolk *head;member *Head;honoured_guest *HEAD;book *HEad;
int c=0;int bc=0;
void creatputong(){
    layfolk *p1,*p2;string a,b;int y=1;
    if(head==NULL){
    cout<<"您的ID编号为："<<c<<endl;cout<<"请输入姓名";cin>>a;cout<<endl;
    cout<<endl<<"请输入地址";cin>>b;cout<<"1.继续输入 2.退出";cin>>y;
    p1=p2=head=new layfolk(a,c,b);c++;
    while(y==1){
        cout<<"您的ID编号为："<<c<<endl;cout<<"请输入姓名";cin>>a;
        cout<<endl<<"请输入地址";cin>>b;cout<<"1.继续输入 2.退出";cin>>y;
        p1=new layfolk(a,c,b);c++;
        p2->next=p1;
        p2=p1;
    }
      p2->next=NULL;
    }else{
        for(p2=head;p2->next!=NULL;p2=p2->next);
        p1=new layfolk();
        p2->next=p1;p2=p1;
        while(y==1){
            cout<<"您的ID编号为："<<c<<endl;cout<<"请输入姓名";cin>>a;
            cout<<endl<<"请输入地址";cin>>b;cout<<"1.继续输入 2.退出";cin>>y;
            p1=new layfolk(a,c,b);c++;
            p2->next=p1;
            p2=p1;
        }
          p2->next=NULL;
    }
}
void creathuiyuan(){
    member *p1,*p2;string a,b;int d,y=1;
    if(Head==NULL){
    cout<<"您的ID编号为："<<c<<endl;cout<<"请输入姓名";cin>>a;cout<<endl<<"会员等级";cin>>d;
   cout<<endl<<"请输入地址";cin>>b;cout<<endl<<"1.继续输入 2.退出";cin>>y;
    p1=p2=Head=new member(a,c,d,b);c++;
    while(y==1){
        cout<<"您的ID编号为："<<c<<endl;cout<<"请输入姓名";cin>>a;cout<<endl<<"会员等级";cin>>d;
        cout<<endl<<"请输入地址";cin>>b;cout<<"1.继续输入 2.退出";cin>>y;
        p1=new member(a,c,d,b);c++;
        p2->next=p1;
        p2=p1;
    }
      p2->next=NULL;
    }else{
        for(p2=Head;p2->next!=NULL;p2=p2->next);
        p1=new member();
        p2->next=p1;p2=p1;
               while(y==1){
               cout<<"您的ID编号为："<<c<<endl;cout<<"请输入姓名";cin>>a;cout<<endl<<"会员等级";cin>>d;
               cout<<endl<<"请输入地址";cin>>b;cout<<"1.继续输入 2.退出";cin>>y;
               *p1=member(a,c,d,b);c++;
               p2->next=p1;
               p2=p1;
           }
        p2->next=NULL;
    }
}
void creatguibing(){
    honoured_guest *p1,*p2;string a,b;int y=1;double d;
    if(HEAD==NULL){
       cout<<"您的ID编号为："<<c<<endl;cout<<"请输入姓名";cin>>a;cout<<endl<<"折扣";cin>>d;
       cout<<endl<<"请输入地址";cin>>b;cout<<endl<<"1.继续输入 2.退出";cin>>y;
    p1=p2=HEAD=new honoured_guest(a,c,d,b);c++;
       while(y==1){
           cout<<"您的ID编号为："<<c<<endl;cout<<"请输入姓名";cin>>a;cout<<endl<<"折扣";cin>>d;
           cout<<endl<<"请输入地址";cin>>b;cout<<endl<<"1.继续输入 2.退出";cin>>y;
           p1=new honoured_guest(a,c,d,b);c++;
           p2->next=p1;
           p2=p1;
       }
    p2->next=NULL;
    }else{
        for(p2=HEAD;p2->next!=NULL;p2=p2->next);
        p1=new honoured_guest();
        p2->next=p1;p2=p1;
        while(y==1){
               cout<<"您的ID编号为："<<c<<endl;cout<<"请输入姓名";cin>>a;cout<<endl<<"折扣";cin>>d;
               cout<<endl<<"请输入地址";cin>>b;cout<<endl<<"1.继续输入 2.退出";cin>>y;
               p1=new honoured_guest(a,c,d,b);c++;
               p2->next=p1;
               p2=p1;
           }
        p2->next=NULL;
    }
}
void in(){
    int i;
        A: cout<<"办理普通用户请输入：1"<<endl<<"办理本店会员请输入:2"<<endl<<"办理本店贵宾请输入：3"<<endl;
          cin>>i;
          switch (i) {
              case 1:
                  creatputong();
                  break;
              case 2:
                  creathuiyuan();
                  break;
              case 3:
                  creatguibing();
                  break;
              default:
                  cout<<"选择了错的选项"<<endl;
                  goto A;
              break;
          }
}
void out(){
    int i;
    cout<<"请输入你的ID编号：";cin>>i;
    layfolk *p;member *x;honoured_guest*y;
    for(p=head;p!=NULL;p=p->next){
        if(i==p->getid()){
            p->display();
            break;
        }
}
    for(x=Head;x!=NULL;x=x->next){
        if(i==x->getid()){
                x->display();
                break;
            }
    }
    for(y=HEAD;y!=NULL;y=y->next){
            if(i==y->getid()){
                y->display();
                break;
            }
    }
    }
void person(){
    int i;
    B:cout<<"查找数据请选1"<<endl<<"输入数据请选2"<<endl;
    cin>>i;
    switch (i){
        case 1:
            out();
            break;
        case 2:
            in();
            break;
        default:
            cout<<"请选择正确的选项"<<endl;
            goto B;
            break;
    }
}
void bin(){
    book *p1,*p2;string a,b,d;double pr;int y =1;
    if(HEad==NULL){
    cout<<"书本编号："<<bc<<endl;cout<<"输入书名：";cin>>a;cout<<endl<<"输入作者：";cin>>b;
    cout<<endl<<"输入出版：";cin>>d;cout<<endl<<"定价：";cin>>pr;cout<<"1.继续 2.结束";cin>>y;
    p1=p2=HEad=new book(bc,a,b,d,pr);bc++;
    while(y==1){
        cout<<"书本编号："<<bc<<endl;cout<<"输入书名：";cin>>a;cout<<endl<<"输入作者：";cin>>b;
        cout<<endl<<"输入出版：";cin>>d;cout<<endl<<"定价：";cin>>pr;cout<<"1.继续 2.结束";cin>>y;
        p1=new book(bc,a,b,d,pr);bc++;
        p2->next=p1;
        p2=p1;
    }
    p2->next=NULL;
    }else{
        for(p2=HEad;p2->next!=NULL;p2=p2->next);
        p1=new book();
        p2->next=p1;
        p2=p1;
        while(y==1){
            cout<<"书本编号："<<bc<<endl;cout<<"输入书名：";cin>>a;cout<<endl<<"输入作者：";cin>>b;
            cout<<endl<<"输入出版：";cin>>d;cout<<endl<<"定价：";cin>>pr;cout<<"1.继续 2.结束";cin>>y;
            p1=new book(bc,a,b,d,pr);bc++;
            p2->next=p1;
            p2=p1;
        }
        p2->next=NULL;
    }
};
void bout(){
    int i;
    cout<<"输入需要查询的书籍编号："<<endl;
    cin>>i;book *p;
    for(p=HEad;p!=NULL;p=p->next){
        if(i==p->getbook_ID()){
            p->display();
            break;
        }
    }
};
void book(){
    int i;
   A:cout<<"查找数据请选1"<<endl<<"输入数据请选2"<<endl;
    cin>>i;
    switch (i){
        case 1:
            bout();
            break;
        case 2:
            bin();
            break;
        default:
            cout<<"请选择正确的选项"<<endl;
            goto A;
            break;
    }
    
}
double personprice(){
    int n,i,pan;
    double pp=0,zong=0;
        cout<<"请输入你的ID编号：";cin>>i;
        B:cout<<"输入需要购买的书籍编号："<<endl;cin>>n;
        class book *p;
        for(p=HEad;p!=NULL;p=p->next){
            if(n==p->getbook_ID()){
                pp=p->getprice();
                break;
            }
        }
        layfolk *j;member *x;honoured_guest*y;
        for(j=head;j!=NULL;j=j->next){
            if(i==j->getid()){
                j->setpay(pp);
                zong=j->getpay();
                break;
            }
    }
        for(x=Head;x!=NULL;x=x->next){
                if(i==x->getid()){
                    x->setpay(pp);
                    zong=x->getpay();
                    break;
                }
        }
        for(y=HEAD;y!=NULL;y=y->next){
                if(i==y->getid()){
                    y->setpay(pp);
                    zong=y->getpay();
                    break;
                }
        }
    A:cout<<"1.继续购买 2.结账"<<endl;cin>>pan;
    switch (pan){
        case 1:
            goto B;
            break;
        case 2:
            return zong;
            break;
        default:
            cout<<"请选择正确的选项"<<endl;
            goto A;
            break;
    }
}
int main(){
    int i;
    A:cout<<"1.书籍 2.顾客 3.结账"<<endl;
    cin>>i;
   switch (i){
       case 1:
           book();
           break;
       case 2:
           person();
           break;
       case 3:
           cout<<"需付款："<<personprice()<<endl;
           break;
       default:
           cout<<"请选择正确的选项"<<endl;
           goto A;
           break;
   }
    goto A;
    return 0;
}
