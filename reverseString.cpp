#include <iostream>
#include <string.h>
#include <stdio.h>
#include "stdbool.h"
#include <set>
using namespace std;



/*
 Question 1.2 : Reverse a char * array
 
 Solution: for loop
 
 */

char * reverse(char * str){
    int length = strlen(str);
    int middle = length/2;
    int limit = length -1;
    
    char temp;
    
    for(int i=0; i < middle; i++){
        temp = str[i];
        str[i] = str[limit -i];
        str[limit -i] = temp;
    }
    return str;
    
}


int main() {
    
    string test1 = "hello";
    string test2 = "hzyxwutsrqponml";
    
    char temp[] = "hello";
    cout<<reverse(temp)<<endl;
    cout<<reverse((char*)test1.c_str());
    
    
    
    
    return 0;
}
