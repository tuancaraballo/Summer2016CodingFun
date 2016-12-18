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

void getLSC(string str1, string str2){
    
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
    
    
    // --> From now on, the following code prints the subsequence.
    
    int overlap =  matrix[len1][len2];
    
    cout<<"Longest sequence length: "<<overlap<<endl;
    string sequence; // --> another approach could have been making a char array and inserting
    // at the specified index, that would have a better performance than inserting
    // into a string, utilized this approach cuz it's easier.
    while(row > 0 && col > 0){
        
        
        if(str1[row-1] == str2[col-1]){
            char c =  str1[row-1];
            sequence.insert(0, &c);
            row--;
            col--;
        }
        else if (matrix[row-1][col] > matrix[row][col-1]){
            row--;
        }else{
            col --;
        }
    }
    cout<<"Sequence:"<<sequence<<endl;
}



// Testing the function
int main() {
    string str1 = "ABCDEF";
    string str2 = "MBCKLETMBF";
    // --> this function should return 4;
    getLSC(str1,str2);
    return 0;
}