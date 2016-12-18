#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 |  Question: Return the longest subsequence of two strings, the
 |  sequence doesn't need to be contiguous.
 |
 |   example: str1 = "ABHJCDIM"
 |           str2 = "BKHLJDPI"
 |
 |          solution should return 5 from  (BHJDI)
 |
 |
 |  Approach:  I previously solved it without using DP, it took O(2^n), bc
 |              for every ch I called the recursive call twice.
 |
 |              A better approach using DP, we can use tabulation to
 |              build it from ground up.
 |              I built a matrix to keep track of the max and the prev
 |              computation. No recursion is utilized here.
 |
 */

int getLSC(string str1, string str2){
    
    int len1 = str1.size();
    int len2 = str2.size();
    
    int matrix[len1 + 1][len2 +1];
    
    int row = 0; // --> used to iterate through rows and str1
    int col = 0;// --> used to iterate through cols and str2;
    
    for(row = 0; row <= len1; row++){ // --> <= bc the matrix is +1 larger than the word
        for(col = 0; col <= len2; col++){
            
            
            if(row == 0 || col == 0){ // --> the first row and first column will always be zero
                matrix[row][col] = 0;
            }
            
            else if(str1[row-1] == str2[col-1]){ // --> -1 bc the above if statement will start
                matrix[row][col] = 1 + matrix[row-1][col-1]; // row and col @ 1,
            }
            
            else{  // --> there was no match, thus return the max between the above or left cell
                matrix[row][col] = max(matrix[row-1][col], matrix[row][col-1]);
            }
            
        }
    }
    
    return matrix[len1][len2];  // not len1-1 bc remember that row 0 and col 0 are zero, so the
    // actual values start at row=1 and col=1, so it ends at len1 and len2
    
}



// Testing the function
int main() {
    string str1 = "ABCDEF";
    string str2 = "MBCKLETMBF";
    // --> this function should return 4;
    cout<<getLSC(str1,str2);
    return 0;
}