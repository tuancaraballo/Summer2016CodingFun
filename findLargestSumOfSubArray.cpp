#include <iostream>
#include <vector>

using namespace std;

/*
 |       Question: Find maximum sum stricttly increasing subarray
 |    Description: Given an array of positive integers. Find the
 |                 max sum of strictly increasing subaarays
 |
 |        ex: [1,2,3,2,5,1,7] // --> return 8  (from adding 1+7)
 */

int findLargestSum(vector<int> &vec){ //--> I slightly changed my intial solution to this
    int len = vec.size();               // so that it can take negative numbers too
    if(len > 1){                        //  it returns 0 by deault
        int max = vec[0];
        int sum = vec[0];
        for(int i = 1; i < len; i++){
            
            if(vec[i] > vec[i-1]){
                sum+=vec[i];
            }
            if(sum > max){
                max = sum;
            }
            if(vec[i] <= vec[i-1]){
                sum = vec[i];
            }
        }
        return max;
    }else if(len == 1){
        return vec[0];
    }
    
    return 0;
    
}

int main() {
    
    
    vector<int> vec = {5,20,1,2,3,7,4,6,100};
    vector<int> vec1 = {-20,-30,1,-2,-3};
    cout<<findLargestSum(vec)<<endl;
    cout<<findLargestSum(vec1)<<endl;
    
    return 0;
}