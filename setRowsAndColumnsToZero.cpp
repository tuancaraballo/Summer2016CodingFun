#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cassert>
#include <set>

using namespace std;

/*
 QUESTION 1.7: Write an algorithm such that if an element in an MXN matrix is 0,
 the entire row and oclumn are set to 0;
 
 ex:  1 1 1 1 1             1 0 0 1 0
 1 0 1 1 1             0 0 0 0 0
 1 1 0 1 1      ==>    0 0 0 0 0
 1 1 1 1 0             0 0 0 0 0
 1 1 1 1 1             1 0 0 1 0
 
 Approach: Read the entire matrix, save the coordinates into an int array
 Then go through the entire array of coordinates and call the
 Helper functions updateRow and updateColumn to put zeros in their
 respectives rows and columns, but first, make sure those rows and
 columns have not been set to zero previously. This is why I have
 two sets to store the row and columns that have already been set to 0
 
 
 */

void printArray(int array[][5]){
    // --> prints the matrix
    for(int i =0; i<5; i++){
        for(int m =0; m<5; m++){
            cout<< array[i][m]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
}


void initializeArray(int array[][5]){
    
    // --> set the whole matrix equal to 1
    for(int i =0; i<5; i++){
        for(int m =0; m<5; m++){
            array[i][m] = 1;
        }
    }
}


void updateRow(int array[][5], int row_number){
    
    for(int i=0; i<5; i++){
        array[row_number][i] = 0;
    }
    
    
}

void updateColumn(int array[][5], int column_number){
    
    for(int i=0; i<5; i++){
        array[i][column_number] = 0;
    }
    
}

void readMatrix(int array[][5], int * coordinates, int * index){
    
    for(int row =0; row<5; row++){
        
        for(int col =0; col<5; col++){
            
            if(array[row][col] == 0){
                coordinates[*index] = row;
                coordinates[(*index)+1] = col;
                *index +=2;
            }
        }
    }
}

int main() {
    
    int array[5][5];
    
    int coordinates[50]; //--> in this case there is a total of 25 coordinates 2
    // points for each coordinate
    int index = 0;
    
    
    initializeArray(array);
    // printArray(array);
    
    array[1][1] = 0;
    array[2][2] = 0;
    array[3][4] = 0;
    
    printArray(array);
    cout<<endl;
    
    set<int>row_set;
    set<int>column_set;
    
    readMatrix(array,coordinates, &index);
    
    cout<<"Reading matrix...."<<endl;
    cout<<"Coordinates:"<<endl;
    for(int i=0; i<6; i+=2){
        cout<<"["<<coordinates[i]<<"] "<<"["<<coordinates[i+1]<< "] "<<endl;
    }
    cout<<endl;
    
    
    for(int i = 0; i<6; i +=2){
        
        int row = coordinates[i];
        int col = coordinates[i+1];
        
        cout<<"Row: "<<row<<endl;
        cout<<"Col: "<<col<<endl;
        
        
        if(row_set.find(row) == row_set.end()){//-->if it's not found in the set
            cout<<"It's not in the row_set"<<endl;
            updateRow(array,row);
            row_set.insert(row);
        }
        
        if(column_set.find(col) == column_set.end()){//-->if it's not found in the set
            cout<<"It's not in the col_set"<<endl;
            updateColumn(array,col);
            column_set.insert(col);
        }
        
    }
    
    
    printArray(array);
    
    return 0;
}