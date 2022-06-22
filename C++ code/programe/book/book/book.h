#include<string.h>
#include<iostream>
using namespace std;
class book{
protected:
    int book_ID;
    string book_name;
    string author;
    string publishing;
    double price;
public:
    book(int b_id=0,string b_name="",string au="",string pu="",double pr=0);
    void display();
    int getbook_ID();
    string getbook_name();
    string getauthor();
    string getpublishing();
    double getprice();
    book *next;
};

