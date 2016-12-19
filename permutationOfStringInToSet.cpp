#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;


/*
 |    Question:  Return a set containing all the permutations
 |               of a string
 |
 |
 */


void swap(char & first, char & second){
    char temp = first;
    first = second;
    second = temp;
}

void printPermutations(string str, int iterator, int length, unordered_set<string> &myset){
    
    if(iterator == length){
        myset.insert(str);
        return;
    }
    
    for(int i = iterator; i < length; i ++){
        swap(str[iterator],str[i]);
        printPermutations(str,iterator+1, length, myset);
        swap(str[i], str[iterator]);
    }
}


/**************   Test cases  *******************
 
 ABC
 ABCD
 
 */
int main() {
    
    string str = "ABMN";
    unordered_set<string> myset;
    printPermutations(str,0,str.size(),myset);
    
    
    // --> print the set
    for(string m : myset){
        cout<<m<<endl;
    }
    
    
    return 0;   
}