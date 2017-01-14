#include <iostream>
#include <vector>
using namespace std;


/*
 |   Question: Convert aay into Zig-zag fashion:
 |
 |    Example:  Input:  arr[] = {4, 3, 7, 8, 6, 2, 1}
 |             Output:  arr[] = {3, 7, 4, 8, 2, 6, 1}
 |
 |              Input:  arr[] =  {1, 4, 3, 2}
 |              Output: arr[] =  {1, 4, 2, 3}
 |
 |   Approach: If current index is multiple of two and array[index + 1] > vec[index+1] < 
 |             vec[index] or if index is not a multiple of two, but vec[index+1] > vec[index],
 |             then swap
 |
 | Time complexity: O(n) because we need to run through all elements in the array
 */

// Purpose: Swaps elements of a vector
void swap(vector<int> & vec, int index){
    int value = vec[index];
    vec[index] = vec[index + 1];
    vec[index+1] = value;
}

// Purpose: to Swap elements based on the question's rule
void zigzag(vector<int> & vec){
    int len = vec.size() - 1;
    for(int index = 0; index < len; index++){
        if(index%2 == 0 && vec[index+1] < vec[index]){
            swap(vec,index);
        }else if(index%2 != 0 && vec[index + 1] > vec[index]){
            swap(vec,index);
        }
    }
}

// Purpose: to print elements of a vector
void print(vector<int> & vec){
    int len = vec.size();
    
    cout<<"vector: {";
    for(int i=0; i <len; i++){
        cout<<vec[i]<<" ";
    }
    
    cout<<"}"<<endl;
}

int main() {
    
    vector<int> vec = {3,4,6,1,12,9,7,6};//--> test case
    zigzag(vec);
    print(vec);
    return 0;
}