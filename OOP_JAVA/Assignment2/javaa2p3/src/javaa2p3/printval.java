/*
 * printval.java
 *
 * Created on March 10, 2016, 4:48 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p3;
import java.util.*;
import java.lang.*;
/**
 *
 * @author c147241
 */
public class printval {
        int[] arand = new int[5];
        int[] brand = new int[5];
        int[] A = new int[1000];
        int[] B = new int[1000];
        int[][] result = new int[5][5];
       
    /** Creates a new instance of printval */
    public void printval_in() {
         Random r = new Random();
        for(int i=0;i<5;i++){
            int a=r.nextInt();
            //System.out.print(a);
            arand[i] = a;
            r.nextInt();
            brand[i]=a;
        }
        for(int i=0;i<1000;i++){
            int a=r.nextInt(5);
            A[i] = arand[a];
            a = r.nextInt(5);
            B[i] = brand[a];
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                result[i][j]=0;
            }
        }
        for(int i=0;i<1000;i++){
            int first=0;int second=0;
            for(int y=0;y<5;y++){
                if(arand[y]==A[i]){
                    first=y;break;
                }
            }
            for(int y=0;y<5;y++){
                if(brand[y]==B[i]){
                    second=y;break;
                }
            }
            result[first][second]++;
        }
    }
    public void printresult(int threshold){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(result[i][j]>threshold){
                    System.out.println("A"+(i+1)+" B"+(j+1)+" "+result[i][j]);
                }
            }
        }
    }
    public void bitmap(){
        System.out.println("A1 A2 A3 A4 A5");
        for(int i=0;i<1000;i++){
            int first=0;
            for(int y=0;y<5;y++){
                if(arand[y]==A[i]){
                    System.out.print("1 ");
                }else{
                    System.out.print("0 ");
                }
            }
            System.out.println("\n");
        }
        System.out.println("B1 B2 B3 B4 B5");
        for(int i=0;i<1000;i++){
            int first=0;
            for(int y=0;y<5;y++){
                if(brand[y]==B[i]){
                    System.out.print("1 ");
                }else{
                    System.out.print("0 ");
                }
            }
            System.out.println("\n");
        }
    }
   
    
}
