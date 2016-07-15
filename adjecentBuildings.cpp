#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 
 QUUESTION:  There are  buildings in a certain two-dimensional landscape. Each building has a       
             height given by . If you join  adjacent buildings, they will form a solid 
             rectangle of area .
 
            Given  buildings, find the greatest such solid area formed by consecutive 
            buildings.
 
 ---Input Format---
 The first line contains , the number of buildings altogether.
 The second line contains  space-separated integers, each representing the height of a building.
 
 ---Constraints---
 1<= N <= 10^5
 1<=hi<=  10^6
 
 ---Output Format---
 One integer representing the maximum area of rectangle formed.
 
 --> Sample input:
 5
 1 2 3 4 5
 --> Sample output:
 9   (the buildings are 3,4,5 --> height of 3 multiplied by 3 contiguous buildings = 9)
 
 */


int findLargestRectangle(int numElements){
    int buildings_heights[numElements];
    // 1-->read the array of numbers
    for(int i =0; i<numElements; i++){
        cin>>buildings_heights[i];
    }
    
    int max_area = 0;
    // 2 --> iterate thorugh the array
    for(int i=0; i < numElements; i++){
        int current_height = buildings_heights[i];
        int number_of_buildings = 1;
        for(int m = i+1; m < numElements; m++){ //--> for each element in the array count
            // all buildings to its right with greater height than current
            if(buildings_heights[m] >= current_height){
                number_of_buildings ++;
            }else{
                break;
            }
        }
        for(int n = i-1; n >= 0; n--){//--> for each element in the array count
            // all buildings to its left with greater height
            if(n>=0 && buildings_heights[n] >= current_height){
                number_of_buildings ++;
            }else{
                break;
            }
        }
        int new_area = number_of_buildings * current_height; //-->calculate its area
        
        if(new_area > max_area){
            max_area = new_area;
        }
        
    }
    return max_area;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int numElements =0;
    cin>>numElements;
    cout<<findLargestRectangle(numElements);
    return 0;
}
