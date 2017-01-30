package javaapplication1;
import java.util.*;

class sample{
    public static void samp(int a){
        System.out.print(a);
    }
}

public class input_scanner{
    
    public static void main(String args[]){
        Scanner b = new Scanner(System.in);
        int []a= new int[10];
        for(int i=0;i<4;i++){
            a[i]=b.nextInt();
        }
        firstclass.selection_Sort(a, 4);
        for(int i=0;i<4;i++)sample.samp(a[i]);
        
    }
}