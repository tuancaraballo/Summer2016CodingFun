#include <stdio.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort

using namespace std;





/*
 |   Question: Given an array of ints and a number, find the number of triplets
 |             that can be formed such that their sum is smaller or equal than
 |             the number you were passed.
 |
 |    Example: {5, 7, 2, 4, 6}  and 12
 |
 |   Solution: You should return 2, since you can only form two triplets
 |             {2,4,5} && {2,4,6}
 |
 |
 |   Initial approach: I initially used a bottom-up recursion approach,
 |                     where my base case was forming a single number,
 |                     then a duplet and then a triplet.
 |                     The issue with this approach was that it's exponential
 |                     since I call the function recursively on each element
 |                     of  the array.
 |
 |  A better apprach: I referenced geekforgeeks.com, which is a lot more efficient
 |                    consists on:
 |
 |                   - sort array in increasing order
 |                   - loop until length - 2:
 |                       second = i+1
 |                       last = length -1;
 |
 |                       -loop again until second >= last
 |                           - if array[i] + array[second] + array[last] <= sum
 |                               --> then you know that any number between second
 |                               and last will also work since the array is sorted
 |                               and last is the largest element. Then, calculate
 |                               the diff between last -second and add it to the
 |                               total number of possible triplets
 |                           - else decrease last, because it's too big
 |
 | Time complexity: The time complexity of this approach is O(n) since you have
 |                   two loops, and in the worst case scenario you will have to run
 |                  through all the elements twice.
 |
 */

const int SIZE = 5;



int findTriplets(int array [], int sum, int length){
    
    
    int total = 0;
    
    sort(array, array + SIZE);
    
    for (int first = 0; first < length -2; first++) {
        
        int second = first + 1;
        int last = length -1; // --> you always want to reset this because it will
        // be changing in the second loop
        while (second < last) {
            if ((array[first] + array[second] + array[last]) <= sum) {
                total = total + (last - second);
                second ++;
            }else{
                last --;
            }
            
        }
    }
    return total;
}


void print(int array[]){
    for (size_t i = 0; i != SIZE; ++i)
        cout << array[i] << " ";
    cout<<endl;
}

int main(){
    
    
    int array[SIZE] = {5, 7, 2, 4, 6};
    
    int length = sizeof(array)/ sizeof(int);
    int sum = 12;
    print(array);
    cout<<"Number of triplets: "<<findTriplets(array,sum, length)<<endl;
    
   
    return 0;
}










