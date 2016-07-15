#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cassert>
#include <set>

using namespace std;


/*
 |  QUESTION 1.6: Rotate a matrix 90 degrees.
 | 
 |      APPROACH: While and for loop combined, rotate one cell from each side at a time. At first, I tried
 |                rotating the entire row and column, but it didn't work out and the code was much much
 |                longer than this. I tried a total of 3 approaches and I found this one to be the easiest
 |                to understand and the most efficient one as well.
 */




const int SIZE = 5;

void printMatrix(int array[][SIZE]){
    // --> prints the matrix
    for(int i =0; i<SIZE; i++){
        for(int m =0; m<SIZE; m++){
            cout<< array[i][m]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
}


void initializeMatrix(int array[][SIZE]){
    
    // --> set the whole matrix equal to 1
    
    int index = 10;
    for(int i =0; i<SIZE; i++){
        for(int m =0; m<SIZE; m++){
            array[i][m] = index;
            index++;
        }
    }
}

void printArray(int * array, int limit){
    for(int i=0; i<limit; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}




int main() {
    
    int matrix[SIZE][SIZE];
    
    
    initializeMatrix(matrix);
    cout<<"Original Matrix:"<<endl;
    printMatrix(matrix);
    
    
    int array[SIZE-1]; //--> array of 4
    
    int start_bound = 0;
    int end_bound = SIZE-1;
    cout<<endl;
    
    
    int cycle = 0;
    
    while(start_bound < end_bound){
        
        cout<<"--- Cycle: "<<cycle<<" ---"<<endl;
        int limit = end_bound - start_bound;
        
        for(int i =0; i< limit; i++){
            
            int temp = matrix[start_bound + i][start_bound]; //--> saving  left column
            
            matrix[start_bound + i][start_bound] = matrix[start_bound][end_bound -i]; // top -> left
            
            matrix[start_bound][end_bound -i] = matrix[end_bound -i][end_bound];// right->top
            
            matrix[end_bound -i ][end_bound] = matrix[end_bound][start_bound + i]; // bottom->right
            
            matrix[end_bound][start_bound + i] = temp;   // left/temp -> bottom
            
        }
        cycle++;
        printMatrix(matrix);
        start_bound++;
        end_bound--;
        
        
    }    
    return 0;
}