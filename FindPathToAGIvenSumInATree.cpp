#include <iostream>
#include <vector>

using namespace std;



/*
 |  Question: Given a Tree and a number. Print all paths in the tree that
 |            add up to that number.(4.9)
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

// Purpose: To print the vector that contains the path.

void printVector(vector<int> & parents){
    cout<<"The path is: ";
    for(vector<int>::iterator it = parents.begin(); it!= parents.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

// Purpose: It's just a helper function to check the Tree was created succesfully.
void printTree(node * root){
    if(!root) return;
    
    printTree(root->left);
    cout<<root->data<<", ";
    printTree(root->right);
}
/*
 |   Purpose: To find the path.
 | Arguments: the root of the tree, the target sum, the sum of the previous parents and
 |            and a vector passed by reference that contains the previous parents.
 */
void findPath(node * root, int target, int sum, vector<int> & parents){
    if(!root) return;
    
    sum+= root->data;
    cout<<"Sum is: "<<sum<<endl;
    parents.push_back(root->data);
    if(sum == target){
        printVector(parents);
        
    }else{
        printSum(root->left,target,sum,parents);
        printSum(root->right,target,sum,parents);
    }
    
    parents.pop_back();
    
}


int main() {
    
    // Creating a tree
    
    node * three = new node(3,NULL,NULL);
    node * eight = new node(8,NULL,NULL);
    node * five = new node (5,three,eight);
    
    node * twelve = new node(12, NULL, NULL);
    node * eighteen = new node(18,NULL, NULL);
    node * fifteen =  new node(15, twelve, eighteen);
    
    node * root = new node(10,five,fifteen);
    
    printTree(root); //-->prints the tree in order-Traversal
    
    int target = 43;
    int sum = 0;
    vector<int> parents;
    findPath(root,target,sum, parents);
    
    
    return 0;
}


