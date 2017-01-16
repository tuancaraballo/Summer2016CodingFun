#include <stdio.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <math.h>
#include <ctype.h>
#include <string>

using namespace std;


/*
 |  Question: Reverse a string without affecting special characters
 |
 |   Example:  
 |              input:  "Ab,c,de!$"
 |             output:  "ed,c,bA!$"
 |
 |
 |  Approach: Run a loop and use two iterators, whenever one of them
 |            doesn't point to a character, ++ or -- the corresponding
 |            iterator.Otherwise, swap the characters Loop breaks when 
 |            iteratorA >= iteratorB
 |
 |  Complexity: O(n), only need to run through loop once.
 */


// Purpose: to swap two characters
void swap(char & first, char & second){
    char temp = first;
    first = second;
    second = temp;
}

// Purpose: to reverse a string withou affecting special characters
void reverseString(string & str){
    
    int length = str.size();
    int iteratorA = 0;
    int iteratorB = length -1;
    
    
    while(iteratorA < iteratorB){
        
        if(!isalpha(str[iteratorA])){
            iteratorA++;
        }else if(!isalpha(str[iteratorB])){
            iteratorB--;
        }else{
            swap(str[iteratorA], str[iteratorB]);
            iteratorA++;
            iteratorB--;
        }
    }
    
}


int main(){
    
    string str = "Ab,c,de!$";
    reverseString(str);
    cout<<"Solution: "<<"ed,c,bA!$"<<endl;
    cout<<"  Answer: "<<str<<endl;
    return 0;
}





