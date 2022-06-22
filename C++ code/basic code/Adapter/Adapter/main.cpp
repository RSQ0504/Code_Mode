//
//  main.cpp
//  Adapter
//
//  Created by David Qian on 2021-10-14.
//
/*
 目标（Target）角色：这是客户所期待的接口。因为C#不支持多继承，所以Target必须是接口，不可以是类。
 源（Adaptee）角色：需要适配的类。
 适配器（Adapter）角色：把源接口转换成目标接口。这一角色必须是类
 */

#include <iostream>
using namespace std;
 
class Target
{
public:
    virtual void Request(){};
};
 
class Adaptee
{
public:
    void SpecificRequest()
    {
        cout<<"Called SpecificRequest()"<<endl;
    }
};
 
class Adapter_B : public Target
{
public:
    Adapter_B(Adaptee *pAdaptee)
    {
        this->pAdaptee = pAdaptee;
    }
    virtual void Request()
    {
        pAdaptee->SpecificRequest();
    }
private:
    Adaptee *pAdaptee;
};
 
int main(int argc, char **argv)
{
    Adaptee *pAdaptee = new Adaptee();
    Target *tt = new Adapter_B(pAdaptee);
    tt->Request();
    system("pause");
    return 0;
}

/*
 class Target
 {
 public:
     virtual void Request(){};
 };
  
 class Adaptee
 {
 public:
     void SpecificRequest()
     {
         cout<<"Called SpecificRequest()"<<endl;
     }
 };
  
 class Adapter_A : public Target, private Adaptee
 {
 public:
     virtual void Request()
     {
         this->SpecificRequest();
     }
 };
  
 int main(int argc, char **argv)
 {
     Target *t = new Adapter_A();
     t->Request();
     
     system("pause");
     return 0;
 }
*/


/*
 省缺适配器
 
 
 class Target {
 public:
     virtual void f1(){};
     virtual void f2(){};
     virtual void f3(){};
 };
  
 class DefaultAdapter : public Target
 {
 public:
     void f1() {
     }
     void f2() {
     }
     void f3() {
     }
 };
  
 class MyInteresting :public DefaultAdapter
 {
 public:
      void f3(){
         cout<<"呵呵，我就对f3()方法感兴趣，别的不管了！"<<endl;
     }
 };
  
 int main()
 {
     // Create adapter and place a request
     Target *t = new MyInteresting();
     t->f3();
  
     return 0;
 }
 */
