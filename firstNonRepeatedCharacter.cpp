#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;


/*
 |    Question: Find first non-repeated character in a String
 |
 |
 */

char findFirstNonRepeated(string str){
    
    int len = str.size();
    
    map<char,int> mymap;
    
    
    for(char c: str){
        if(!mymap[c]){
            mymap[c] = 1;
        }else{
            mymap[c] = mymap[c] +1;
        }
    }
    
    char m;
    
    for(char c: str){
        if(mymap[c] == 1){
            m = c;
            break;
        }
        
    }
    
    return m;
    
}

//testing cases
/*
 
 */
int main() {
    
    string str = "ABMKABMKV";
    
    
    cout<<"The first non-repeated character: "<<findFirstNonRepeated(str)<<endl;
    
    
    
    return 0;
}