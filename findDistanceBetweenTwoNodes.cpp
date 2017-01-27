#include <iostream>
#include <queue>
#include <vector>

using namespace std;


/*
 |    Question: Find the distance between two nodes in a tree
 |
 |  Approach#1: Get the parent node for both, where they both split
 |              then calculate the distance between parent node and
 |              the children, and add them both together
 |  
 |Time complexity:  This is a binary search tree, thus findig the parent
 |                  node takes log(n), calculting the distance between
 |                  parent nodes and children is also log(n)
 |                  Thus, total time complexity is log(n) + log(n) + log(n)
 }                  which reduces to just log(n)
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




node * getAncestor(node * root, int A, int B){
    if(!root) return NULL;
    
    if(A < root->data && B < root->data){
        return getAncestor(root->left, A, B);
    }
    if(A > root->data && B > root->data){
        return getAncestor(root->right, A, B);
    }
    
    return root;
}

int findDistance(node * root, int num){
    if(!root || root->data == num) return 0;
    
    if(num < root->data){
        return  1 + findDistance(root->left, num);
    }
    
    return 1 + findDistance(root->right, num);
}


int findDistanceBetweenTwoNodes(node * root, int num1, int num2){
    node * parent = getAncestor(root,num1, num2);
    
    if(!parent) return -1;
    
    return findDistance(parent,num1) + findDistance(parent, num2);
    
}

void printInOrder(node * root){
    if (!root) return;
    
    printInOrder(root->left);
    cout<<root->data<<", ";
    printInOrder(root->right);
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
    
    
    printInOrder(fifty);
    cout<<endl;
    
    int num1 = 35;
    int num2 = 80;
    
    int num3 = 20;
    int num4 = 35;
    
    cout<<"Distance between 35 and 80 = 4 --->  "<<findDistanceBetweenTwoNodes(fifty,num1,num2)<<endl;
    cout<<"Distance between 25 and 35 = 3 --->  "<<findDistanceBetweenTwoNodes(fifty,num3,num4)<<endl;
    
    
    return 0;
}