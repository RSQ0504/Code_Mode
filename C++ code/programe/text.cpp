#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class TxtBook
{
private:
	string name;
	double price;
public:
	TxtBook(string _name,double _price):name(_name),price(_price){}
	TxtBook(){}
	friend ostream & operator<<(ostream & os,const TxtBook& b);
	friend istream & operator>>(istream & is,TxtBook & b);
	void Show()
	{
		cout<<name<<":"<<price<<endl;
	}
};
ostream & operator<<( ostream & os,const TxtBook & c)
{
	os<<c.name<<endl;
	os<<c.price<<endl;
 
	return os;
}
istream &operator>>( istream & is,TxtBook& c)
{
	getline(is,c.name);
	is.ignore();//ºöÂÔ»»ÐÐ·û 
	is>>c.price;is.ignore();
   return is;
} 
int main()
{
	vector<TxtBook> vecBook ;
	
	TxtBook book1("Chinese book",88.88 ),book2("math book",12);
	vecBook.push_back(book1);vecBook.push_back(book2);
	
	ofstream fout("a.txt");
	int len=vecBook.size();
	fout<<len<<endl;
	for (int i=0;i<len;i++)
		fout<<vecBook[i];
	fout.close();
	
	vecBook.clear();
	len=0;
	ifstream fin("a.txt");
 	fin>>len;fin.ignore();

 	for (int i=0;i<len;i++)
 	{
 		TxtBook book;
 		fin>>book;
 		vecBook.push_back(book);
	}
	
	for (int i=0;i<vecBook.size();i++)
		vecBook[i].Show();
}
