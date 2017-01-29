#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <limits>
using namespace std;


/*
 |    Question: find if a tree is a sum tree. A sum tree is a type
 |              of tree such that a node is the total sum of the nodes
 |              below it: all its family: children and gran grand children
 |
 |  Approach#1: You have to run through all the elements in the tree once.
 |              Thus, the overall run-time performance of this is O(n)
 |
 */

int negative_infinity = -INFINITY;


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





void printInOrder(node * root){
    if (!root) return;
    
    printInOrder(root->left);
    cout<<root->data<<", ";
    printInOrder(root->right);
}

int isSumTree(node * root){
    
    if(!root) return 0;
    int sum_left = isSumTree(root->left);
    int sum_right = isSumTree(root->right);
    
    if(sum_left + sum_right != root->data){
        return negative_infinity;
    }
    
    return sum_left + sum_right + root->data;
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
    
    
    
    
    
    
    return 0;
}