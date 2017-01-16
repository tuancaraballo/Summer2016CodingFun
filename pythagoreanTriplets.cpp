#include <stdio.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <math.h>

using namespace std;


/*
 |  Question: Given an array, find if it contains a pythagorean triplet
 |
 |  Approach: Sort the array. Use two for loops to run through the array.
 |            from the inner-most loop, run forward and backwards using
 |            two iterators to find the possible numbers
 |
 |   Example: {3, 1, 4, 6, 5}   -> Return true bc {3,4,5}
 |  
 |   Time complexity: O(n^2),
 |
 |
 |
 */

const int SIZE = 6;

// Purpose: to find whether there is a pythagorean triplet or not.
bool pythagoras(int array [], int len){
    
    sort(array, array + len);
    
    for(int i = 0; i < len -2; i++){
        int next = i + 1;
        int last = len -1;
        
        for(int j = 0; j <= len; j++){
             //--> run forward from next to the end, keep last intact
            if((pow(array[i],2) + pow(array[i+j],2)) ==  pow(array[last],2)){
                return true;
            }
            //--> run backwards from end to next, keep next intact
            if((pow(array[i],2) + pow(array[next],2)) ==  pow(array[last - j],2)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    
    
    int array[SIZE] = {3,1,4, 6, 5};
    int len = sizeof(array)/sizeof(int);
    
    if(pythagoras(array, len)){
        cout<<"YES!"<<endl;
    }else{
        cout<<"NOPE"<<endl;
    }
    return 0;
}





