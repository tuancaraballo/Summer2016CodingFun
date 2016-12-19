#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;


/*
 |    Question: Reverse a string iteratively
 |
 |
 */

string reverse(string str, int len){
    if(len == 0) return "";
    return str[len-1] + reverse(str, len -1);
}

//testing cases
/*
 
 */
int main() {
    
    string str = "CINTHIA";
    int len = str.size();
    
    cout<<reverse(str,len)<<endl;
}