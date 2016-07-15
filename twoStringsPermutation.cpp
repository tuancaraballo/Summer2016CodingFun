/* package whatever; // don't place package name! */

import java.io.*;
import java.util.*;
import java.lang.Boolean;


/*
 QUESTION 1.3: Given two strings, write a method to decide if one is a permutation of the other
 Approach: I used two maps to store their characters and their counts and then compared the maps
 Another approach could be using an array where you store the counts.
 
 */




class myCode
{
    public static Boolean checkIfPermutation(String one, String two){
        
        Map<Character,Integer> m1 = new HashMap<Character,Integer>();
        Map<Character,Integer> m2 = new HashMap<Character,Integer>();
        
        int len1 = one.length();
        int len2 = two.length();
        
        
        
        if(len1 != len2) return false;
        
        for(int i = 0; i<len1; i++){
            //  ---> check if the character in one is contained in the map
            if(m1.containsKey(one.charAt(i))){
                m1.put(one.charAt(i),m1.get(one.charAt(i) +1));
            } else{  //---> it wasn't found, so just added to the map
                m1.put(one.charAt(i),1);
            }
            
            // --> check second map
            if(m2.containsKey(two.charAt(i))){
                m2.put(two.charAt(i),m2.get(two.charAt(i) +1));
            } else{
                m2.put(two.charAt(i),1);
            }
        }
        
        
        if(m1.equals(m2)) return true;
        
        return false;
        
        
    }
    
    public static void main (String[] args) throws java.lang.Exception{
        
        String one = "DKKBACEL";
        String two = "LABECDKK";
        
        long startTime = System.currentTimeMillis();
        if(checkIfPermutation(one,two)){
            System.out.println("They are permutations of each other");
        } else{
            System.out.println("They are  NOT permutations of each other");
        }
        
        double stopTime = System.currentTimeMillis();
        double elapsedTime = stopTime - startTime;
        System.out.println("Time Taken: " + elapsedTime);
        
    }
}
