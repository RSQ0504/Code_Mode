//
//  main.cpp
//  The list
//
//  Created by 钱荣晟 on 2021/2/2.
//

#include <iostream>
#include<cstdlib>
using namespace std;

//定义表结点的数据结构：数据+指针
struct ListNode
{
    int value;
    ListNode* next;
};
int main()
{
    //创建头指针
    ListNode* head = new ListNode;
    //头指针初始化
    head->value=0;
    head->next = NULL;
   
    //链表动态增加元素
    //定义创建新的元素的辅助指针 *p
    ListNode* p = head;
    int n,k;
    cout<<"how many number do you want?"<<endl;
    cin>>n;
    cout<<"enter the number"<<endl;
    for (int i = 0; i < n; i++)
    {
        //动态创建新的链表节点并初始化
        ListNode* newNode = new ListNode;//开辟了链表的存储空间  不能用delete释放
        cin>>k;
        newNode->value = k;
        newNode->next = NULL;
        //辅助指针把新创建的节点接到链表的结尾
        p->next = newNode;
        //辅助指针后移指向最新的节点
        p = newNode;
        //delete newNode;  这里不能释放newNode，因为此时 p = newNode  ，是链表的最后一个节点
    }
   // list = list->next;  //执行这个语句就把头指针指向第一个元素 ：头结点

    //输出元素：
    cout<<"the answer is:"<<endl;
    p = head;
    while (p->next != NULL)
    {
        //先把辅助指针指向头结点在输出节点的值
        p = p->next;
        cout << p->value << " ";
    }

    //别忘了delete
    delete head;
    return 0;
}
