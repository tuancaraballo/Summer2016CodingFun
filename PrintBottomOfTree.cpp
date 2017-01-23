#include <iostream>
#include <queue>
#include <vector>

using namespace std;


/*
 |    Question: Print the bottom view of a Binary tree
 |
 |  Approach#1: Print those nodes that don't have both children
 |              or don't have one of the children.
 |
 */





struct node{
    node * left = NULL;
    node * right = NULL;
    node(node * l, node * r, int dat){
        left = l;
        right = r;
        data = dat;
    }
    int data;
};


void printByLevel(queue <node*> myq){
    if(myq.empty()) return;
    queue<node*> next;
    
    while(!myq.empty()){
        node * temp = myq.front();
        myq.pop();
        cout<<temp->data<<" ";
        if(temp->left) next.push(temp->left);
        if(temp->right) next.push(temp->right);
    }
    cout<<endl;
    printByLevel(next);
    
}

void printInOrder(node * root){
    if (!root) return;
    
    printInOrder(root->left);
    cout<<root->data<<", ";
    printInOrder(root->right);
}


void getBottom(node * root, vector<int> & vec){
    
    if(!root) return;
    
    
    
    getBottom(root->left,vec);
    if(!root->left || !root->right){
        vec.push_back(root->data);
    }
    getBottom(root->right,vec);
}


void printVector(vector<int> & vec){
    for(int temp : vec){
        cout<<temp<<" ";
    }
}
int main() {
    
    
    node * first = new node(NULL,NULL,1);
    
    node * third = new node(NULL,NULL,3);
    node * second= new node(first,third,2);
    
    
    node * twnt = new node(NULL,NULL,20);
    node * thir5 = new node(NULL,NULL, 35);
    
    node * fourty = new node(thir5,NULL,40);
    node * thirty = new node(twnt,fourty,30);
    
    node * eighty = new node(NULL,NULL,80);
    node * fifty = new node(thirty,eighty,50);
    
    
    printInOrder(second);
    cout<<endl;
    
    vector<int> vec = {20,30,35,40,55,80};
    vector<int> vec1 = {1,2,3};
    
    
    vector<int> myvec;
    getBottom(fifty,myvec);
    printVector(myvec);
    
    
    
    
    
    return 0;
}