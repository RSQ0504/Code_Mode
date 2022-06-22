#include<iostream>
#include<string.h>
#include"book.h"
using namespace std;
book::book(int b_id,string b_name,string au,string pu,double pr){
       book_ID=b_id;
       book_name=b_name;
       author=au;
       publishing=pu;
       price=pr;
}
void book::display(){
    cout<<"书籍编号"<<book_ID<<endl;
    cout<<"书籍名称"<<book_name<<endl;
    cout<<"作者"<<author<<endl;
    cout<<"出版日期"<<publishing<<endl;
    cout<<"价格"<<price<<endl;
}
int book::getbook_ID(){return book_ID;}
string book::getbook_name(){return book_name;}
string book::getauthor(){return author;}
string book::getpublishing(){return publishing;}
double book::getprice(){return price;}
