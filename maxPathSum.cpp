#include <iostream>
#include <queue>

using namespace std;


/*
 |    Question: Find the Maximum Pat Sum in a Binary Tree
 |
 |  Approach#1: Perform a traversal(similar to the way you cal)
 |              calculate the height) and pick the largest number
 |              Add the current value to the sum and return in.
 |
 |
 */




// Structure of a node
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


// Purpose: To calculate the max sum of a path in a tree
int findMaxSum(node * root){
    if(!root) return 0;
    
    return root->data + max(findMaxSum(root->left), findMaxSum(root->right));
}

// Purpose: to print the tree
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




using namespace std;

int main() {
    
    queue<node*> myq;
    node * twnt = new node(NULL,NULL,20);
    node * thir5 = new node(NULL,NULL, 35);
    
    node * fourty = new node(thir5,NULL,40);
    node * thirty = new node(twnt,fourty,30);
    
    node * eighty = new node(NULL,NULL,80);
    node * fifty = new node(thirty,eighty,50);
    
    myq.push(fifty);
    //printByLevel(myq);
    
    cout<<findMaxSum(fifty)<<endl;

    
    
    return 0;
}