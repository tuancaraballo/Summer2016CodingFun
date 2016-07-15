#include <iostream>
#include <string>
#include "stdbool.h"
#include <set>
using namespace std;


/*
    Question: Implement an algorithm to determine if a string has all unique characters. 
              What if you cannnot use additinal data structures?
    Approach: I used a set data structure. I iterate through each character and check
              if it's contained in the data structure, if it it's a return false, 
              meaning that it's contained it's repeated. If it's not contained, I added
              to the set. 
  Complexity: O(n) b/c you still have to iterate thorugh the entire string. Set is O(1)
  
 No data structure: Use two for loop. Complexity: O(n^2)
 

 */

// 1- Check if a string has unique characters using a data structure

bool checkIfUnique(string temp){
    int len = temp.length();
    set<char> myset;
    for(int i = 0; i<len; i++){
        if(myset.find('l') == myset.end()){
            myset.insert(temp[i]);
        }else{
            return false;
        }
    }
    return true;
}

//2- Check if a string has unique characters not using a data structure:

bool checkWitoutDataStructure(string temp){
    int len_outterLoop = temp.length() -1;
    int len_innerLoop = len_outterLoop + 1;
    
    for(int i =i; i < len_outterLoop; i++){
        // cout<<"i: " <<temp[i]<<endl;
        for(int m= i +1; m < len_innerLoop;  m++){
            //   cout<<"m: "<<temp[m]<<endl;
            if(temp[i]==temp[m]){
                return false;
            }
        }
    }
    return true;
    
}


int main() {
    
    string test1 = "hello";
    string test2 = "hzyxwutsrqponml";
    cout<<"String 1: " <<test1<<endl;
    cout<<"String 2: " <<test2<<endl;
    cout<<endl;
    
    
    // ------ Checking without using a data structure
    cout<< "Checking without using a data structure ..."<<endl;
    if(checkWitoutDataStructure(test1)){
        cout<< "Test1 contains unique characters" <<endl;
    } else{
        cout<< "Test1 doesn't contain unique characters" <<endl;
    }
    if(checkWitoutDataStructure(test2)){
        cout<< "Test2 contains unique characters" <<endl;
    } else{
        cout<< "Test2 doesn't contain unique characters" <<endl;
    }
    cout<<endl;
    
    
    //------- Checking using a data structure
    cout<< "Checking using a set data structure ..."<<endl;
    if(checkIfUnique(test1)){
        cout<< "Test1 contains unique characters" <<endl;
    } else{
        cout<< "Test1 doesn't contain unique characters"<<endl;
    }
    
    if(checkIfUnique(test2)){
        cout<< "Test2 contains unique characters" <<endl;
    } else{
        cout<< "Test2 doesn't contain unique characters" <<endl;
    }
    
    return 0;
}
