#include <iostream>
#include <vector>

using namespace std;



/*
 |  Question #4.7: Given two nodes in a binary tree that is not a BST, find the lowest common
 |                 ancestor
 |  
 |  Question #4.8: Given two trees T1 with a million nodes and T2 with hundred of thousands 
 |                 nodes. Design an algorithm to determine if T2 is a subtree of T1
 |
 |
 */
struct node{
    int data;
    node * left;
    node * right;
    
    node(int data, node * left, node * right){
        this->data = data;
        this->left =left;
        this->right = right;
    }
    
};

// Purpose: find lowest common ancestor of two nodes
node * lca(node * root, int A, int B){
    if(root == NULL) return NULL;
    cout<<root->data<<endl;
    if(root->data == A || root->data == B) return root;
    
    
    node * temp1 = lca(root->left,A,B);
    node * temp2 = lca(root->right,A,B);
    
    
    if(temp1 != NULL && temp2!= NULL) return root; // it means that you got to the ancestor
    
    if(temp1 == NULL && temp2 == NULL) return NULL;
    
    
    if(temp1) return temp1;  //temp1 != NULL ? temp1:temp2;
    return temp2;
    
}



bool isSubtree = false;


// Purpose: it will iterate through both tree making sure they both match
bool checkSameNodes(node * root1, node * root2){
    if(!root1 && !root2) return true;
    
    if(  (!root1 && root2) ||  (root1 && !root2)) return false;
    
    //  cout<<"ROOt1: "<<root1->data<<"   "<<"ROOT2: "<<root2->data<<endl;
    
    bool left = checkSameNodes(root1->left, root2->left);
    bool right = checkSameNodes(root1->right, root2->right);
    
    if(left && right && root1->data == root2->data) return true;
    
    return false;
    
}


// Purpose: it will iterate through the entire  T1 tree.

void iterate(node * root1, node * root2){
    if(!root1) return;
    
    iterate(root1->left,root2);
    
    if(root1->data == root2->data && !isSubtree){ // --> If this is is only the first match
        // proceed, otherwise if a match has already been found, it will set isSubtree to false
        cout<<"MATCH HERE:  "<<root1->data<<endl;
        isSubtree = checkSameNodes(root1,root2);
    }
    
    iterate(root1->right,root2);
}

int main() {
    
    /*                    TREE T1
                             10
                          /       \
                       5             4
                     /   \             \
                  10       5             1
                 /   \
                8      3
               /         \
              7            2
     
     
     */
    
    // --> Building T1 tree, which looks like the above diagram.
    node * two = new node(2,NULL,NULL);
    node * three = new node(3,NULL,two);
    
    
    node * seven = new node(7,NULL,NULL);
    node * eight = new node(8,seven,NULL);
    node * ten_1 = new node(10,eight,three);
    
    
    node * five_3 = new node (5,NULL,NULL);
    node * five_2 = new node (5,NULL,five_3);
    node * five_1 = new node (5,ten_1,five_2);
    
    
    node * fourteen =  new node(14, NULL, NULL);
    node * fifteen =  new node(15, NULL,NULL);
    node * one = new node(1, fourteen,fifteen);
    
    node * four = new node(4, NULL,one);
    
    node * root1 = new node(20, five_1,four);
    
    ///   -------- T2
   /*
                    10     
                  /   \
                 8      3
                /         \
               7            2
    
    */
    node * sevenB =  new node(7,NULL,NULL);
    node * eightB = new node(8, sevenB,NULL);
    
    node * twoB = new node(2,NULL,NULL);
    node * threeB = new node(3,NULL,twoB);
    node * root2 =   new node(10,eightB,threeB);
    
    
    
    iterate(root1,root2);
    
    if(isSubtree){
        cout<<"Yes, it's a subtree"<<endl;
    }else{
        cout<<"Nope, it's not a subtree"<<endl;
    }
    
    
    
    return 0;
}


