#include <iostream>
#include <string>
using namespace std;

/*
 Question: Reverse a string words
 
 example:  The house blue
 result:  blue house The
 
 
 Lessons learned:  Always check for edge cases, in this question, at first I didn't check when
 the loop gets to the end my condition if (str[m] ==' ') fails and you
 don't reverse the last word
 
 */


void reverseString(string &str){
    
    int len = str.length();
    int limit = len / 2;
    
    // --> Reversing the characters in the whole string
    for(int i = 0; i < limit; i++){
        char holder = str[i];
        str[i] = str[len - i -1];
        str[len-i-1] = holder;
    }
    
    //--> start of the word to be reversed
    int start = 0;
    
    for (int i =0; i < len; i++){
        if(str[i] == ' ' || i+1 == len){ //--> when you hit a white space or end of string
            if(i+1 == len) i++;
            int length = i - start;
            int limit = length / 2;
            
            for(int m = 0; m < limit; m++){ // --> reverse just the word
                char holder = str [start + m];
                str[start + m] = str[i-1-m];
                str[i-1-m] = holder;
            }
            start = i+1;
        }
    }
    
    
}

int main() {
    cout<<"Hello"<<endl;
    
    string str = "the house blue";
    cout<<"String: "<<str<<endl;
    reverseString(str);
    cout<<"String outside: "<<str<<endl;
    
    
    return 0;
}