#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cassert>
#include <set>

using namespace std;



/*
 Question 1.8: check if one string is the rotation of another string:
 ex:   erbottlewat  of  waterbottle
 pamamapa  of  mamapapa
 erismycomput  of  computerismy
 
 This question was a misinterpretation of the original question. It's in fact,
 much harder than the original question becasue the original question allows
 you to use the built in function:  isSubstring
 
 */


bool isSubstring(string s1, string s2){
    
    int len = s1.length();
    
    int matches = 0;
    
    int cycle =0;
    
    int i = 0;
    int limit = len;
    for(i= 0; i < limit; i++){
        if(s1[i] == s2[matches]){
            
            matches++;
            cout<<"Match: "<<s1[i]<<"  --- Total matches: "<<matches<<endl;
        } else if(s1[i] == s2[0]){
            matches = 1;
        }else{
            cout<<"Set to zero: "<<s1[i]<<endl;
            matches = 0;
        }
        if(i+1 == len && matches != 0){
            cout<<"Got to the end"<<endl;
            i =-1;
            limit = len - matches;
        }
        
        if(matches == len){
            cout<<"True"<<endl;
            return true;
        }
        
        
    }
    
    cout<<"False"<<endl;
    return false;
    
    
    
}




int main() {
    
    string first = "waterbottle";
    string second = "erbottlewat";
    
    string third = "mycomputeris";
    string fourth = "erismycomput";
    
    string s1 = "mamapapa";
    string s2 = "pamamapa";
    
    // cout<<isSubstring(third,fourth)<<endl;
    // cout<<isSubstring(first,second)<<endl;
    cout<<isSubstring(s1,s2)<<endl;
    
    
    
    
    return 0;
}