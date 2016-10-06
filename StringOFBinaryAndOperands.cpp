#include <iostream>
#include <string>
using namespace std;



/*
 
    Question: Given a string ex:  ((0&1)|0)&(1&1)) Find if the result is true or false
 
 --> I stumbled upon this question the other day on internet. Found it interesting, so decided
 to solve it. didn't add error checking for the string since it's not that interestingI honestly don't think this is the most optimal solution. I will try
 to solve it using stack.
 
 */

char answer(string str){
    char first = str [1];
    char sec = str[3];
    char operand = str[2];
    
    if(operand == '|'){
        if(first == '1' || sec == '1'){
            return '1';
        }
        return '0';
    } else if (operand == '&' &&
               first =='1' && sec == '1'){
        return '1';
    }
    
    return '0';
}



bool findAnswer(string str){
    int len = str.length();
    
    char ans;
    
    
    if(len == 5){
        
        ans = answer(str);
        
        if(ans == '1') return true;
        
        return false;
    }
    
    for(int i=0; i <len; i++){
        if(str[i] == ')'){
            string temp = str.substr(i-4,5);
            cout<<"Temp is: "<<temp<<endl;
            ans = answer(temp);
            str.replace(i-4,i, string(1,ans));
            cout<<"After replace: "<<str<<endl;
            return findAnswer(str);
        }
    }
    
    return false;
}
int main() {
    
    string str = "((1|0)&1)";
    
    
    
    cout << findAnswer(str)<<endl;
    
    
    
    return 0;
}