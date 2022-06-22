//
//  main.cpp
//  Vector/Fstream
//
//  Created by David Qian on 2021/7/3.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Vehicle{
   string make;
   int year;
   double hp;
};

int main(){
   vector<Vehicle> a;
   vector<Vehicle>::iterator it;
   ifstream fin
("/Users/qianrongsheng/Desktop/C++ code/basic code/Vector/Vector/File.txt");
    //传出文件到main
   if(fin.fail()){
       cout<<"There are some things error"<<endl;
   }
   
   string m;
   int y;
   double hp;
   Vehicle tempt;
   int i=1;
   while(!fin.eof()){
       fin>>m;
       tempt.make=m;
       fin>>y;
       tempt.year=y;
       fin>>hp;
       tempt.hp=hp;
       cout<<i<<" "<<m<<" "<<y<<" "<<hp<<endl;
       i++;
       a.push_back(tempt);
   }
   fin.close();
   for(it=a.begin();it<a.end();it++){
       cout<<(*it).make<<"\t"<<"\t"<<"\t"<<(*it).year<<"\t"<<"\t"<<"\t"<<(*it).hp<<endl;
   }
   
   int index=0;
   vector<Vehicle>::iterator t;
   for(it=a.begin();it<a.end();it++){
       t=it+1;
       index=0;
       while(t<a.end()){
           if((*it).make==(*t).make){
               index++;
               a.insert(it, (*t));
               a.erase(t+1);
           }
           t++;
       }
       it=it+index;
   }
   
    ofstream fout
("/Users/qianrongsheng/Desktop/C++ code/basic code/Vector/Vector/File.txt");
    //从main传出文件，并删除原文件中所有内容
   string M;
   int Y;
   double Hp;
   for(it=a.begin();it<a.end();it++){
       M=(*it).make;
       Y=(*it).year;
       Hp=(*it).hp;
       fout<<M<<"\t"<<"\t"<<"\t"<<Y<<"\t"<<"\t"<<"\t"<<Hp<<endl;
   }
   fout.close();
   system("Pause");
   return 0;
}
