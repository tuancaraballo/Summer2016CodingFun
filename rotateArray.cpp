#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
 |   Question: Given a vector of numbers, rotate the vector by x number of times.
 |    
 |    example:
 |
 |          input: [1, 2, 3, 4, 5]  rotate it by 2
 |         output: [3, 4, 5, 1, 2]
 */


//  Purpose: To print a vector
void printVector(vector<int> &vec, string message){
    cout<<message<<endl;
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}


//  Purpose: To rotate the vector given the displacement
void rotateVector(vector<int> &vec, int displacement){
    
    printVector(vec, "Before displacement");
    int len = displacement%vec.size();
    for(int i = 0; i < len; i++){
        vec.push_back(vec[0]);
        vec.erase(vec.begin(),vec.begin()+1);
    }
    printVector(vec, "After displacement");
}


// Purpose: It takes a vector by reference and the numbers of elements you want to
//          add to it.
void initializeVector(vector<int> & vec, int size){
    for(int i = 1; i <= size; i++){
        vec.push_back(i);
    }
    
}
int main() {
    
    vector<int> vec;
    int displacement = 7;
    cout<<"Displacement: "<<displacement<<endl;
    initializeVector(vec, 7);
    rotateVector(vec, displacement);

    return 0;
}

