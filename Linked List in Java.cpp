/* package whatever; // don't place package name! */

import java.io.*;




class myCode

{
    public static class LinkedList {
        private LinkedList next;
        private int data;
        
        // constructor
        public LinkedList(int data, LinkedList next) {
            this.data = data;
            this.next = next;
        }
    }
    
    public static int findNth(LinkedList current, int count, int target){
        if(current == null)return -1;
        if(count == target) return current.data;
        count++;
        return findNth(current.next, count, target);
    }
    
    public static void printList(LinkedList current){
        while(current != null){
            System.out.println(current.data);
            current = current.next;
        }
    }
    
    public static void removeMiddle(LinkedList  the_node){
        LinkedList current = the_node;
        
        while(current.next.next != null){
            current.data =  current.next.data;
            current = current.next;
        }
        current.data =  current.next.data;
        current.next = null;
    }
    
    public static void partition(LinkedList bigHead, LinkedList smallHead, int target){
        
        LinkedList current = bigHead;
        LinkedList previous = current;
        
        
        
        
    }
    
    
    public static void main (String[] args) throws java.lang.Exception
    {
        
        
        
        
        // ---------  build the linked list:   ------------------------------
        LinkedList eight = new LinkedList(8, null);
        LinkedList seventh = new LinkedList(7, eight);
        LinkedList sixth = new LinkedList(6, seventh);
        LinkedList fifth = new LinkedList(5, sixth);
        LinkedList fourth = new LinkedList(4, fifth);
        LinkedList third = new LinkedList(3, fourth);
        LinkedList second = new LinkedList(2, third);
        LinkedList first = new LinkedList(1, second);
        
        printList(first);
        // ------------------- Access nth to last element --------------------
        System.out.println("Access nth to last element" );
        
        int nth = 3;
        int target = 8 -3;
        int count = 0;
        
        
        int data = findNth(first,count,target);
        
        if(data == -1){
            System.out.println("Whoops some error happened");
        }else{
            System.out.println("Data is  : " + data);
        }
        System.out.println("\n" );
        // -------------------  Remove element in the middle -----------------
        System.out.println("Remvoe element in the middlet" );
        LinkedList current = fourth;
        removeMiddle(current);
        printList(first);
        System.out.println("\n" );
        // ------------------- Partition a LinkedList around a value x ------
        
        LinkedList mainHead = first;
        LinkedList newHead = null;
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
}
