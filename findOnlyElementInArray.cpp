#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


/*
 |    Question: Find the only element in an array that only occurs once
 |              if there are more than one element that repeats once, return
 |              the first element
 |
 |           ex:  "ABBACMMNQQ"  --> returns C bc only repeats once,
 |
 |    first approach: create a map that iterates through all elements and keeps a count
 |                      O(n)
 |    second approach: sort the array and iterate checking if prev and next elements are
 |                     different, if so, then there is the unique element
 |                     sort + iteration = O(nlogn) + O(n)
 |
 */



char getUnique(string str){
    
    int len = str.size();
    map<char,int> mymap;
    
    for(char c : str){
        if(!mymap[c]){
            // cout<<c<<" NOT FOUND, adding it... "<<endl;
            mymap[c] = 1;
        }else{
            // cout<<c<<" FOUND, adding +1"<<endl;
            mymap[c] = mymap[c]+1;
        }
    }
    
    
    
    for(pair<char,int> p : mymap){
        if(p.second == 1) return p.first;
    }
    
    return '1';
    
}
int main() {
    
    cout<<getUnique("Hello")<<endl;
    return 0;
}