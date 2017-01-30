/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment1;
import java.util.*;
import java.lang.*;
/**
 *
 * @author c147241
 */
public class prob5 {
   static int present=0;
   static int size=16;
   static String N[]=new String[16];
   static String C[]=new String[16];
    
   public static void add(String n,String c){
       if(present<size){
           N[present]=n;
           C[present]=c;
           present++;
       }else{
           String tempn[]=new String[2*size];
           String tempc[]=new String[2*size];
           for(int i=0;i<size;i++){
               tempn[i]=N[i];
               tempc[i]=C[i];        
           }tempn[present]=n;tempc[present]=c;
           N=new String[2*size];C=new String[2*size];
           for(int i=0;i<=size;i++){
               N[i]=tempn[i];C[i]=tempc[i];
           }
           present++;
           size=size*2;
       }
   }
   public static void drop(String n){
       int i;
       for(i=0;i<present;i++){
           if(N[i].equals(n))break;
       }
       if(i==present)System.out.println("No student with the given name");
       else
           for(int j=i;j<size-1;j++){
               N[j]=N[j+1];
               C[j]=C[j+1];
           }
       present--;
       if(present<16&&size>16)size=16;
   }
   public static String getCourse(String n){
       for(int i=0;i<present;i++){
           if(N[i].equals(n))return C[i];
       }
       System.out.println("No student with the given name");
       return "";
   }
   public static void clear(){
       present=0;
       size=16;
   }
}
