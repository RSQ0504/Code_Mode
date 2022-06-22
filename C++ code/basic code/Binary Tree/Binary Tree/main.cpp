//
//  main.cpp
//  Binary Tree
//
//  Created by David Qian on 2021-10-27.
//

#include <iostream>
#include <cstddef>
using namespace std;

class Node
{
    public:
        Node(int val);
        Node* right;
        Node* left;
        int value;
        virtual ~Node();

    protected:

    private:
};
Node::Node(int val)
{
    value = val;
    left = 0;
    right = 0;

}


Node::~Node()
{
}

class Tree
{
    public:
        Node* root;
        Tree(int rootValue);
        void addNode(int nodeValue);
        void printTreeInorder(Node* node);
        void printTreePreorder(Node* node);
        void printTreePostorder(Node* node);

        virtual ~Tree();

    protected:

    private:
};

Tree::Tree(int rootValue)
{
    root = new Node(rootValue);
    //ctor
}

Tree::~Tree()
{
    //dtor
}

void Tree::addNode(int nodeValue){
    if(this->root==NULL){
        Tree a(nodeValue);
    }else{
        Node *p=this->root;
        while(1){
        if(nodeValue<p->value){
            if(p->left==NULL){
                Node *q= new Node(nodeValue);
                p->left=q;
                break;
            }
            p=p->left;
        }else{
            if(p->right==NULL){
                Node *q= new Node(nodeValue);
                p->right=q;
                break;
            }
            p=p->right;
        }
        }
}
}

void Tree::printTreeInorder(Node* node){
    if(node->left!=NULL)
        printTreeInorder(node->left);
    cout<<node->value<<" ";
    if(node->right!=NULL)
        printTreeInorder(node->right);
}

void Tree::printTreePreorder(Node* node){
    cout<<node->value<<" ";
     if(node->left!=NULL)
      printTreePreorder(node->left);
     if(node->right!=NULL)
         printTreePreorder(node->right);
}

void Tree::printTreePostorder(Node* node){
    if(node->left!=NULL)
      printTreePostorder(node->left);
     if(node->right!=NULL)
      printTreePostorder(node->right);
    cout<<node->value<<" ";
}


int main()
{
    int a;
    cout<<"enter the root"<<endl;
    cin>>a;
    Tree *p=new Tree(a);
    cout<<"how many numbers do you want enter"<<endl;
    int n;
    cin>>n;
    int b;
    for(int i=0;i<n;i++){
        cout<<"enter :";
        cin>>b;
        cout<<endl;
        p->addNode(b);
    }
    cout<<"Inorder ;"<<endl;
    p->printTreeInorder(p->root);
    cout<<endl;
    cout<<"Preorder ;"<<endl;
    p->printTreePreorder(p->root);
    cout<<endl;
    cout<<"Postorder ;"<<endl;
    p->printTreePostorder(p->root);
    cout<<endl;
    return 0;
}
