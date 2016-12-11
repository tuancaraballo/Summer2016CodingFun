#include <iostream>
#include <vector>
using namespace std;


/*
*   Question: You are given an array containing the prices for a given
*             stock, each index represents a day. Print the min and max
*             value that will yield tha max profit
*
*       ex: {5,7,8,13,3,6,14,4}  --> should print 3 and 14, they wil
*/
 



void printBestDeal(vector<int> dates){
    int len = dates.size();
    
    if(len > 1){
        int min = dates[0];
        int min_holder = min;
        int max = dates[1];
        int difference = 0;
        
        for(int i = 0; i < len; i ++){
            int temp_diff = dates[i] - min_holder;
            
            if(temp_diff > difference){
                min = min_holder;
                max = dates[i];
                difference = temp_diff;
            } else if( dates[i] < min_holder){
                min_holder = dates[i];
            }
        }
        
        cout<<"You should buy: " <<min<<endl;
        cout<<"You should sell: "<<max<<endl<<endl;
    }
}
int main() {
    
    
    
    vector<int> test1 = {0,1,2,3,4}; //--> should print 0 and 4
    vector<int> test2 = {0,4,7,1,5}; //--> should print 0 and 7
    vector<int> test3 = {10, 4, 8, 11, 10}; // --> should print 4 and 11;
    vector<int> test4 = {4, 4, 8, 11, 3, 11}; // --> should print 3 and 11;
    
    
    printBestDeal(test1);
    printBestDeal(test2);
    printBestDeal(test3);
    printBestDeal(test4);
    return 0;
}