#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 |          Question: Return the longest subsequence of two strings, the
 |                    sequence doesn't need to be contiguous.
 |
 |           example: str1 = "ABHJCDIM"
 |                    str2 = "BKHLJDPI"
 |
 |                    solution should return 5 from  (BHJDI)
 |
 |
 |          Approach: A naive approach would be computing all possible subsequences for
 |                    each string and then comparing them until we find the largest overlap
 |                    This will lead to a ridicuosly large time complexity, so we have to
 |                    try something else
 |
 |              We move backwards: comapre characts of each string
 |              from end to start, if the characters match, we increase the
 |              count by 1 and call function recursively, otherwise we
 |              call recursively the function twice, one on the first string
 |              and another on the second string, and then return whichever
 |              of these calls returned the maximum count.
 |
 |  Time complexity: Every call to my function calls the function recursively twice,
 |                   so this means that for every character we are making 2 recursive calls
 |                   We will need to make 2 recursive calls for the lenght of our shorter
 |                   string (not longest since the base case makes stops the function when len
 |                   becomes 0). Thus we can conclude that time complexity is:
 |
 |
 |                   O (2^n), where n is the length of the shorter string
 |
 |                   Could we do better? I think we can using some DP, will think about this...
 |
 */



int getLSC(string str1, int len1, string str2, int len2){
    
    // --> Base case: if one of their lenghts becomes 0, then there is nothing to compare
    if(len1 == 0 || len2 ==0){
        return 0;
    }
    
    // --> If the characters match, then add one and call
    //     function recursively
    if(str1[len1] == str2[len2]){
        return 1 + getLSC(str1,len1-1,str2,len2-1);
    }
    
    // --> Else return the max of both recursive calls
    return max(getLSC(str1,len1-1, str2,len2),getLSC(str1,len1,str2,len2-1));
}



// Testing the function
int main() {
    string str1 = "ABCDEFGMNA";
    int len1 = str1.size();
    string str2 = "AMNCEHGMNA";
    int len2 = str2.size();
    cout<<getLSC(str1,len1,str2,len2);
    return 0;
}