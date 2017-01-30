/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author c147241
 */
public class firstclass {
    public static void selection_Sort(int a[],int n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(a[i]<a[j]){
                    int temp=a[i];a[i]=a[j];a[j]=temp;
                }
            }
        System.out.println("Selection Sort done");
    }
}
