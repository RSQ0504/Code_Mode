//
//  main.cpp
//  Stack
//
//  Created by David Qian on 2021-10-07.
//

#include <iostream>
#include <stack>
/*
 stack<int> S;//声明一个对象
 S.empty();//栈空返回true 否则false
 int x=S.size();//返回栈中元素个数于x
 S.pop();//移除栈顶元素
 S.push(x);将x置于栈顶
 x=S.top();返回栈顶元素
 */
#include <ctime>
using namespace std;

class HanoiTower
{
    public:
        stack<int>* rods;
        HanoiTower(int numberOfDisks); //Creates 3 rods and puts all the disk on the first rod in descending order
        bool moveDisk(int firstRod, int secondRod); //Moves the top disk from firstRod to secondRod. Throws an exception if it cannot be moved.
        void print();
        void Solve();
        virtual ~HanoiTower();

    protected:

    private:


};
HanoiTower::HanoiTower(int numberOfDisks) // Constructor: Make the rod stacks based on the number of disks
{
    stack<int> rod1;
    stack<int> rod2;
    stack<int> rod3;
    rods = new stack<int>[3] {rod1, rod2, rod3};
    for(int n = numberOfDisks; n > 0; n--){
        rods[0].push(n);
    }
}

bool HanoiTower::moveDisk(int firstRod, int secondRod) {
    if(firstRod<1||firstRod>3||secondRod<1||secondRod>3)
        return 0;
    if(rods[firstRod-1].empty())
        return 0;
    if(rods[secondRod-1].empty()==false){
    if(rods[firstRod-1].top()>rods[secondRod-1].top())
        return 0;
    }
    int x=rods[firstRod-1].top();
    rods[firstRod-1].pop();
    rods[secondRod-1].push(x);
    cout<<"move rod "<<firstRod<<" to rod "<<secondRod<<" sucessfully"<<endl;
    return 1;
}

void HanoiTower::print(){
    for(int i=0;i<3;i++){
        cout<<i+1<<": ";
        int size=rods[i].size();
        int *p=new int[size];
        for(int j=size-1;j>=0;j--){
            p[j]=rods[i].top();
            rods[i].pop();
        }
        for(int j=0;j<size;j++){
            cout<<p[j]<<" ";
        }
        for(int j=0;j<size;j++){
            rods[i].push(p[j]);
        }
        cout<<endl;
    }
}


HanoiTower::~HanoiTower(){
    delete [] rods;
}

void HanoiTower::Solve(){
    
}

int main()
{
    srand(time(nullptr));
    int n;
    cout<<"cin the number"<<endl;
    cin>>n;
    HanoiTower P(n);
    cout<<"original is :"<<endl;
    P.print();
    int x,y;
    A:cout<<"enter x and y"<<endl;
    cin>>x>>y;
    cout<<"move rod "<<x<<" to rod "<<y<<endl;
    if(P.moveDisk(x, y)){
        P.print();
    }else{
        cout<<"can not be moved."<<endl;
    }
    cout<<"Do you want to continue?"<<endl<<"1.Yes 0.No"<<endl;
    int a;
    cin>>a;
    if(a)
        goto A;
    return 0;
}
