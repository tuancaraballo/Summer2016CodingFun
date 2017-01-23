#include <iostream>
#include <queue>
#include <vector>

using namespace std;


/*
 |    Question: Check if a a binary tree is a full binary tree
 |
 |  Approach#1: Traverse the array, if one of the nodes contains
 |              only one child return false, else continue the
 |              the traversal.
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


bool checkIfFullTree(node * root){
    if(!root) return true;
    
    if((root->left && root->right) || (!root->left && !root->right)){
        return checkIfFullTree(root->left)&&checkIfFullTree(root->right);
    }
    return false;
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
    if(checkIfFullTree(second)){
        cout<<"YES!"<<endl;
    }else{
        cout<<"NOPE"<<endl;
    }
    
    if(checkIfFullTree(fifty)){
        cout<<"YES!"<<endl;
    }else{
        cout<<"NOPE"<<endl;
    }
    
    
    
    
    
    
    return 0;
}