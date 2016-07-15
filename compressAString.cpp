#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cassert>
using namespace std;


/*
|    Question:  Input: aabcccccaaa
|              Output: a2b1c5a3
|
|    Approach: Check if the current character is equal to the previous one, if so
|              increment count by one, otherwise append the temp_character to the
|              compressed string as well as count, and reset temp character to current
|              and count to 1
|
*/

string compress(string sentence, int len){
    assert(len >0); //--> do some error checking here.
    string compressed;
    char temp_char = sentence[0]; //-->store a character, until the current changes
    int count = 1;  //--> store the number of consecutive occurances of temp_char
    
    for(int i =1; i < len; i++){
        if(sentence[i] == temp_char){
            count++;
            
        }
        if (sentence[i] != temp_char || i +1 == len){ //--> if the character is different or you have reached the end of the string
            compressed += temp_char + to_string(count);
            temp_char = sentence[i];
            count =1;
        }
    }
    return compressed;
}

int main() {
    
    
    string sentence = "aabcccccaaa";
    cout<<"Original String: "<<sentence<<endl;
    cout<<"Compressed string: "<<compress(sentence, sentence.length())<<endl;
    
    return 0;
}
