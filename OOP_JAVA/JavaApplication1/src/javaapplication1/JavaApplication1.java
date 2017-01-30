/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication1;
import java.util.*;
/**
 *
 * @author c147241
 */
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void selection_Sort(int a[],int n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(a[i]<a[j]){
                    int temp=a[i];a[i]=a[j];a[j]=temp;
                }
            }
        System.out.println("Selection Sort done");
    }
    public static void bubble_Sort(int a[],int n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n-i-1;j++){
                if(a[j]<a[j+1]){
                    int temp=a[j];a[j]=a[j+1];a[j+1]=temp;
                }
            }
        System.out.println("Bubble Sort : Done");
    }
    public static void insertion_Sort(int a[],int b[],int n){
        
        for(int i=0;i<n;i++){
            a[i]=b[i];
            int j=i;
            while(j>0&&a[j]>a[j-1]){
                int temp=a[j];a[j]=a[j-1];a[j-1]=temp;
                j--;
            }
        }
        
        System.out.println("Insertion Sort : Done");
    }
        
    public static void main(String[] args) {
        int a[]={1,5,3,4,2,81,4,7,8};
        int n= 9;
        selection_Sort(a,9);
        for(int i=0;i<n;i++)System.out.println(a[i]);
        int b[]={1,5,3,4,2,81,4,7,8};
        bubble_Sort(b,9);
        for(int i=0;i<n;i++)System.out.println(b[i]);
        int c[]={1,5,3,4,2,81,4,7,8};
        insertion_Sort(a,c,9);
        for(int i=0;i<n;i++)System.out.println(a[i]);
        stack s=new stack();
        stack_initialise(s);
        s.print();
    }
    //stack s = new stack();
    public static void stack_initialise(stack s){
        Scanner scan = new Scanner(System.in);
        int hi=1;
        while(hi!=-1){
        hi=scan.nextInt();
        s.push(hi);
       if(hi==-1)break;
        }
    }
    public static void queue_initialise(queue q){
        Scanner scan = new Scanner(System.in);
        int hi=1;
        while(hi!=-1){
        hi=scan.nextInt();
        q.enqueue(hi);
       if(hi==-1)break;
        }
    }
}
