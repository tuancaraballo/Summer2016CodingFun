#include <iostream>
#include <queue>
#include <vector>

using namespace std;


/*
 |    Question: Check if a given array can represent Preorder Traversl
 |              of Binary Search
 |  Approach#1: Pass an index variable and the array, if the
 |              root data doesn't match the value of array[index]
 |              return false, otherwise increment the index by 1.
 |               if it's !root return true
 |
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



void test(int &index){
    index += 2;
    cout<<"Inside: "<<index<<endl;
}

bool checkArrayMatchTree(node * root, int & index, vector<int> & array){
    
    if(!root) return true;
    
    bool left = checkArrayMatchTree(root->left,index,array);
    
    if(root->data != array[index]){
        return false;
    }else{
        index++;
    }
    bool right = checkArrayMatchTree(root->right, index, array);
    
    return left&&right;
    
}



using namespace std;

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
    
    
    int index = 0;
    if(checkArrayMatchTree(fifty,index,vec)){
        cout<<"YES!"<<endl;
    }else{
        cout<<"NOPE"<<endl;
    }
    
    
    
    
    
    return 0;
}