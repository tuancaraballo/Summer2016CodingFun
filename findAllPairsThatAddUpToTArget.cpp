#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;


/*
 |    Question: Given a number and an array of numbers,which could
 |              possibly contain duplicates,
 |              Find all pairs that add up to the number
 |
 |
 |           ex:  [ 5, 3 , 5, 2, 7, 8, 5, 4]
 |
 |                <5,5> <2,8> <3,7>
 |
 |    first approach: Iterate once, and add it to the hash set
 |                    Iterate once, and for each number find the difference
 |                    that adds up to target sum, check if it's in the hashset
 |                    if so, then add it to the solution set, order it with smaller
 |                    number first, this way we can gurantee that no duplicates
 |                    are added to the set.
 */


// NOTE: I would say that a better style would have been returning a hashset containing
//       the pairs. It's not the job of this function to print the elements

void getPairs(vector<int> vec, int sum){
    
    
    unordered_set<int> myset; //--> set containing all elements in vector
    unordered_set<string> solution;
    
    
    
    for(int i : vec){     // -->adding the numbers to the set
        myset.insert(i);
    }
    
    for(int & i : vec){ // --> iterate through vector again.
        
        int diff = sum - i;
        
        if(myset.find(diff) != myset.end()){
            string answer;
            if(i <= diff){
                answer = "[" + to_string(i) + ", " + to_string(diff) + "]";
            }else{
                answer = "[" + to_string(diff)  + ", " +  to_string(i) + "]";
            }
            solution.insert(answer);
        }
    }
    
    for(string temp : solution){
        cout<<temp<<endl;
    }
    
    
    
}

//testing function
int main() {
    
    vector<int> vec = {4,5,7,6,5,7,3};
    int sum = 10;
    getPairs(vec,sum);
    
    
    return 0;
}