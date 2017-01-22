#include <iostream>
#include <queue>

using namespace std;


/*
 |    Question: Find the minimum height of a tree
 |
 |  Approach#1: Using Depth First Search O(n)
 |
 |
 |  Approach#2: Using Breadth First Search O(n)
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


// Purpose: To find the minimum search of a tree using DFS
int findMinDepth(node* root){
    if(!root) return 0;
    
    return (1 + min(findMinDepth(root->left),findMinDepth(root->right)));
}

// Purpose: To find the minimum search of a tree Using BFS
int findminDepth(queue<node*> myqueue, int level){
    if(myqueue.empty()) return 0;
    queue<node*> next;
    while(!myqueue.empty()){
        node * temp = myqueue.front();
        myqueue.pop();
        
        if(!temp->left && !temp->right) return level;
        
        if(temp->left) next.push(temp->left);
        if(temp->right) next.push(temp->right);
    }
    
    return findminDepth(next,level+1);
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
    cout<<findMinDepth(fifty)<<endl;
    cout<<findminDepth(myq, 1)<<endl;
    
    
    return 0;
}