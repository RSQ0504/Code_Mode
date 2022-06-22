//
//  main.cpp
//  Queue
//
//  Created by David Qian on 2021-10-14.
//

/*

 #include<queue>
 (1)push();就是从已有元素后面增加元素
 (2)front();返回队列的第一个元素的值，这里只是返回，并没有把它剔除队列。
 (3)back();返回队列的最后一个元素的值。
 (4)pop();删除第一个元素
 (5)empty();判断队列是否为空，若为空则返回true。
 (6)size();返回队列元素个数。
 
 #include<deque>
 (1)insertFront();
 (2)insertBack();
 (3)eraseFront();
 (4)eraseBack();
 (5)push_front();
 (6)push_back();
 (7)pop_front();
 (8)pop_back;
 */

#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class City
{
    public:
        City(int number_of_houses);
        virtual ~City();
        void create_city();
        void print_city(int starting_house);
        vector<int>* houses;
    protected:
    
    private:
        int city_size;



};

City::City(int number_of_houses)
{
    city_size = number_of_houses;
    houses = new vector<int>[city_size];
}

City::~City()
{
    city_size=0;
    delete []houses;
    //dtor
}

void City::create_city(){
    int n,index;
    for(int i=0;i<city_size;i++){
        cout<<"This is house "<<i<<endl<<"How many number do you want to have?"<<endl;
        cin>>n;
        cout<<"cin the house number which is neighbourhood"<<endl;
        for(int j=0;j<n;j++){
            cout<<"neighbour "<<j<<": ";
            cin>>index;
            houses[i].push_back(index);
        }
    }
    //write your code here
}

void City::print_city(int starting_house){
    int* visited = new int[city_size];
    for (int i=0; i<city_size; i++)
        visited[i] = false;
    cout<<starting_house<<" ";
    visited[starting_house]=1;
    queue<int>q;
    q.push(starting_house);
    for(int i=0;i<houses[q.front()].size();i++){
        q.push(houses[q.front()][i]);
    }
    while(q.empty()!=true){
        q.pop();
        if(visited[q.front()]==0){
            cout<<q.front()<<" ";
            visited[q.front()]=1;
            for(int i=0;i<houses[q.front()].size();i++){
                q.push(houses[q.front()][i]);
            }
        }
    }
    
    return;
    //write your code here
    
}

int main()
{
    int n;
    cin>>n;
    City city(n);
    city.create_city();
    city.print_city(0);
    return 0;
}

