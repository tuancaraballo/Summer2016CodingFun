#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cassert>
#include <set>
#include <stdlib.h>
#include <cstddef>
#include <math.h>

using namespace std;



struct node {
    int data;
    node * next;
    
    node(int d, node * n){
        data = d;
        next= n;
    }
};


void printList(node * current){
    //int count = 1;
    while(current != NULL){
        cout<<current->data<<endl;
        current = current->next;
        // count++;
    }
}



void partition(node * head, int target){
    
    node * current = head;
    node * previous = current;
    
    cout<<"It got here"<<endl;
    if(head){
        
        while(current != NULL){
            
            cout<<"Current is: "<<current->data<<endl;
            if(current->data <= target){
                node * holder = current;
                previous->next = current->next;
                current = current->next;
                holder->next = head;
                head = holder;
                // current = previous->next;
            }else{
                previous = current;
                current= current->next;
            }
        }
        cout<<"BOOM finish!"<<endl;
    }
    
    
}


node * sumLinkLists(node * first, node * second){
    int count = 0;
    int first_number = 0;
    int second_number = 0;
    
    node * current = first;
    
    while(current){
        first_number += current->data * pow(10,count);
        count++;
        current = current->next;
    }
    
    current = second;
    count = 0;
    
    while(current){
        second_number += current->data * pow(10,count);
        count++;
        current = current->next;
    }
    cout<<"First number: "<<first_number<<endl;
    
    cout<<"Second number: "<<second_number<<endl;
    
    int total = first_number+second_number;
    
    cout<<"Result is: "<<total<<endl;
    
    node * result_head = NULL;
    node * tail = NULL;
    
    while(total !=0){
        
        int data = total %10;
        total = total/10;
        
        node * new_node = new node(data, NULL);
        
        if(!result_head){ //--> if it's the first element in the list
            result_head = new_node;
        }else{
            tail->next = new_node;
        }
        
        tail = new_node;
        
    }
    
    return result_head;
    
    
}


node * checkIfLoop(node * head){
    set<node*> myset;
    
    node * current = head;
    
    while(current){
        if(myset.find(current) == myset.end()){
            myset.insert(current);
        }else{
            return current;
        }
        current = current->next;
    }
    return NULL;
}

node * checkifLoopUsingRunners(node * head){
    
    if(head && head->next){
        //   cout<<"Inside if"<<endl;
        node * slowRunner = head;
        node * fastRunner = head;
        
        while(fastRunner && fastRunner->next){
            slowRunner = slowRunner->next;
            fastRunner = fastRunner->next->next;
            if(slowRunner == fastRunner){
                break;
            }
        }
        cout<<"Collision happened at: "<<slowRunner->data<<endl;
        cout<<"Collision happened at: "<<fastRunner->data<<endl;
        
        if(!fastRunner || !(fastRunner->next)){
            return NULL;
        }
        
        slowRunner = head;
        while(slowRunner != fastRunner){
            slowRunner = slowRunner->next;
            fastRunner = fastRunner->next;
        }
        
        return slowRunner;
        
    }
}

int main() {
    
    
    //------------- Building the list --------------------------
    /*  node * eight = new node(8,NULL);
     node * seven = new node(7,eight);
     node * six = new node(6,seven);
     node * five = new node(5, six );
     node * four = new node(4,five);
     node * three = new node(3,four);
     node * two = new node(2,three);
     node * one = new node(1,two);
     */
    
    // ------------- 2.4 Parittion at a value ----------------------
    
    /*    node * eight = new node(8,NULL);
     node * one = new node(1,eight);
     node * six = new node(6,one);
     node * seven = new node(7,six);
     node * two = new node(2,seven);
     node * three = new node(3,two);
     node * five = new node(5, three);
     node * four = new node(4,five);
     
     
     node * head = four;
     printList(head);
     
     cout<<endl;
     
     int target = 5;
     
     partition(head,target);
     
     printList(head);
     */
    
    
    // -------------2.5  Link List additions----------------------
    
    /*   node * six = new node(6,NULL);
     node * one = new node(1,six);
     node * seven = new node(7,one);
     node* first = seven;
     cout<<"First List: "<<endl;
     printList(first);
     
     
     node * two = new node(2,NULL);
     node * nine = new node(9,two);
     node * five = new node(5, nine);
     node * second = five;
     cout<<"Second List: "<<endl;
     printList(second);
     
     
     printList(sumLinkLists(first,second));
     
     */
    // -------------2.6 Check if Loop in the LL ----------------------
    
    
    /*
     
     node * eight = new node(8,NULL);
     node * seven = new node(7,eight);
     node * six = new node(6,seven);
     node * five = new node(5, six );
     node * four = new node(4,five);
     node * three = new node(3,four);
     node * two = new node(2,three);
     node * one = new node(1,two);
     
     
     eight->next = two;
     node * head = one;
     
     //     node * cur = checkIfLoop(head);
     //      if(cur){
     //          cout<<"A loop was found at: "<<cur->data<<endl;
     //      }else{
     //          cout<<"No loop! "<<endl;
     //      }
     
     printList(head);
     
     node * sol = checkifLoopUsingRunners(head);
     
     if(sol){
     cout<<"A loop was found at: "<<sol->data<<endl;
     }else{
     cout<<"No loop! "<<endl;
     }
     */
    
    // -------------2.7 Check if a LL is palindrome ----------------------
    
    
    node * oneb = new node(1,NULL);
    node * twob = new node(2, oneb);
    node * threeb = new node(3,twob);
    node * four = new node(4, oneb);
    node * three = new node(3,four);
    node * two = new node(2,three);
    node * one = new node(1,two);
    
    
    
    return 0;
}