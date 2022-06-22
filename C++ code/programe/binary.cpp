#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Book
{
private:
	string name;
	double price;
public:
	Book(string _name,double _price):name(_name),price(_price){}
	Book(){}
	friend ostream & operator<<(ostream & os,const Book& b);
	friend istream & operator>>(istream & is,Book & b);
	void Show()
	{
		cout<<name<<":"<<price<<endl;
	}
};
ostream & operator<<( ostream & os,const Book & c)
{
	int len=c.name.size();
	os.write((const char *)&len, sizeof(len));
	os.write(c.name.data(),len);
	double price=c.price;
	os.write((const char *)&price,sizeof(price));
 
	return os;
}
istream &operator>>( istream & is,Book& c)
{
	int len=0;
	is.read((char *)&len, sizeof(len));
	c.name.resize(len);
	is.read((char*)c.name.data(),len);
	is.read((char*)&c.price,sizeof(c.price));
   return is;
}


int main()
{
	vector<Book> vecBook ;
	
	Book book1("Chinese book",88.88 ),book2("math book",12);
	vecBook.push_back(book1);vecBook.push_back(book2);
	
	ofstream fout("a.dat", ios::binary);
	int len=vecBook.size();
	fout.write((const char *)&len, sizeof(len));
	for (int i=0;i<len;i++)
		fout<<vecBook[i];
	fout.close();
	
	vecBook.clear();
	len=0;
	ifstream fin("a.dat", ios::binary);
 	fin.read((char *)&len, sizeof(len));
 
 	for (int i=0;i<len;i++)
 	{
 		Book book;
 		fin>>book;
 		vecBook.push_back(book);
	}
	
	for (int i=0;i<vecBook.size();i++)
		vecBook[i].Show();
}
