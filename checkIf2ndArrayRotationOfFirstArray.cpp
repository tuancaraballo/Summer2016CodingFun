#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;


/*
 |    Question: Given two arrays of numbers,which could contain duplicate nums
 |              find if the second array is a rotation of the first
 |
 |          ex:  [5, 3, 5, 2, 7, 7, 8, 5, 4]
 |               [7, 8, 5, 4, 5, 3, 5, 2, 7]
 |
 |               should return true:
 |
 |   Approach:  Iterate through first array, until you find the last overlap
 |              [7,8,5,4], then calculate the difference length - overlap
 |              Iterate through another for loop and compare characters
 |              that did not contribute towards overlap
 |              arr1[i] == arr2[difference + i] if they are not the same return false
 |              else return true
 */


bool isRotation(vector<int> vec1, vector<int> vec2){
    
    int count = 0; // --> rotation length
    
    int len1 = vec1.size();
    int len2 = vec2.size();
    
    if(len1 != len2) return false; // --> if they are not the same length
    
    
    for(int i = 0; i < len1; i++){
        
        if(vec1[i] == vec2[count]){
            count++;
        }else{
            count = 0;
            if(vec1[i] == vec2[0]){ // --> this line gurantees that although the sequence
                count = 1;            //     has broken, it might have started where it broke
            }
        }
    }
    
    if(count == 0) return false; // --> there was not even an overlap.
    
    // cout<<"COUNT: "<<count<<endl;
    
    
    
    int start_vec2 = count;
    
    int len = len1 - count;
    
    for(int i = 0; i < len; i++){
        // cout<<vec1[i]<<" "<<vec2[start_vec2 + i]<<endl;
        if(vec1[i] != vec2[start_vec2 + i]) return false;
    }
    
    
    return true;
    
    
    
    
}

//testing cases
/*
 
 
 1- Different lengths
 2- Different elements
 3- They are rotations
 4- Edge cases:
 
 - overlap is only on the last element, although there is overlap in the middle
 
 [1,2,3,4,5,6]
 [6,1,2,3,4,5]
 
 - if they are the same array, it should return true = full rotation
 
 */
int main() {
    
    
    // --> Should return false, contains different elements
    vector<int> vec1 = {4,5,7,6,5,7,7};
    vector<int> vec2 = {5,7,3,4,5,7,6};
    
    if(isRotation(vec1,vec2)){
        cout<<"YES!"<<endl;
    }else{
        cout<<"NOPE"<<endl;
    }
    
    //--> Should return false, lengths are different
    vector<int> vec3 = {4,5,7};
    vector<int> vec4 = {5,7};
    
    if(isRotation(vec3,vec4)){
        cout<<"YES!"<<endl;
    }else{
        cout<<"NOPE"<<endl;
    }
    
    //--> Should return YES, partial rotation
    vector<int> vec5 = {4,5,7,6,5,7,3};
    vector<int> vec6 = {5,7,3,4,5,7,6};
    
    if(isRotation(vec5,vec6)){
        cout<<"YES!"<<endl;
    }else{
        cout<<"NOPE"<<endl;
    }
    
    //---> Should return YES!, only one element rotation
    vector<int> vec7 = {1,2,3,4,5,7};
    vector<int> vec8 = {2,3,4,5,7,1};
    
    if(isRotation(vec7,vec8)){
        cout<<"YES!"<<endl;
    }else{
        cout<<"NOPE"<<endl;
    }
    
    //--> should return YES!, full rotation
    vector<int> vec9 = {1,2,3,4,5,7};
    vector<int> vec10 = {1,2,3,4,5,7};
    
    if(isRotation(vec9,vec10)){
        cout<<"YES!"<<endl;
    }else{
        cout<<"NOPE"<<endl;
    }
    
    
    
    return 0;
}