#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Worker
{
private:
	string name;
	double salary;
public:
	Worker(string _name,double _salary):name(_name),salary(_salary){}
	Worker(){}
	void show()
	{
		cout<<name<<":"<<salary<<endl;
	}
	
	bool operator==(const Worker& w)
	{
		return name==w.name;
	}
	friend class FindByName;
	friend class FindBySalaryRange;
	friend bool compare1(const Worker& w1,const Worker& w2 );
	friend bool compare2(const Worker& w1,const Worker& w2 );
};
bool compare1(const Worker& w1,const Worker& w2 )
{
	return w1.salary<w2.salary;
}
bool compare2(const Worker& w1,const Worker& w2 )
{
	return w1.salary>w2.salary;
}


class FindByName
{
public:
	FindByName(string _name):name(_name){}
	bool operator()(const Worker& worker)
	{return worker.name==name;}
private:
	string name;
};

class FindBySalaryRange
{
public:
	FindBySalaryRange(double _llimit,double _hlimit):llimit(_llimit),hlimit(_hlimit){}
	bool operator()(const Worker& worker)
	{return worker.salary<=hlimit && worker.salary>=llimit;}
private:
	double llimit,hlimit;
};

int main()
{
	vector<Worker> vecWorker ;
	vecWorker.push_back(Worker("Chinese book",88.88 ));vecWorker.push_back(Worker("Math book",66.66 ));
	vecWorker.push_back(Worker("English book",33.88 ));vecWorker.push_back(Worker("Physics book",77.66 ));
	
	cout<<"升序："<<endl;
	sort(vecWorker.begin(),vecWorker.end(),compare1);
	for (int i=0;i<vecWorker.size();i++)
		vecWorker[i].show();
	
	cout<<"降序："<<endl;	
	sort(vecWorker.begin(),vecWorker.end(),compare2);
	for (int i=0;i<vecWorker.size();i++)
		vecWorker[i].show();
	
	cout<<"查找一个元素："<<endl;	
	vector<Worker>::iterator iter=find_if(vecWorker.begin(),vecWorker.end(),FindByName("Physics book"));
	if(iter!=vecWorker.end()) 
		iter->show();
	else
		cout<<"找不到！"<<endl;
	
	cout<<"查找多个元素："<<endl;
	iter=vecWorker.begin();
	FindBySalaryRange find1(60,80);
	while((iter=find_if(iter,vecWorker.end(),find1))!=vecWorker.end())
		iter++->show();

	
	cout<<"删除元素:"<<endl;
	iter=remove_if(vecWorker.begin(),vecWorker.end(),FindByName("English book"));
	if(iter!=vecWorker.end()) 
	{
 		vecWorker.erase(iter);
		for (int i=0;i<vecWorker.size();i++)
			vecWorker[i].show();
	}
	else
		cout<<"找不到删除元素！"<<endl;
}
