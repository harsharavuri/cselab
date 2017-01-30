/*
 * Reverse.java
 *
 * Created on March 10, 2016, 3:12 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p10;
import java.lang.*;
import java.util.*;
/**
 *
 * @author c147241
 */
public class Reverse {
    
    private static Integer n=512;
    /** Creates a new instance of Reverse */
    public int reverse(int sum){
        if(n==0){n=512;return sum;}
        sum = sum*10 + n%10;
        n=n/10;
        return reverse(sum);
    }
    
    String s1 = "dasdasdasdas";
    char a[] = s1.toCharArray();
   
    StringBuffer s = new StringBuffer(a.toString());
    //s = a;
    
    public String toString(){
        int sum=0;
        String s="";
        int a = reverse(sum);
        while(a!=0){
            int num = a%10;
            switch(num){
                case 0:System.out.print("Zero");s=s+"Zero";break;
                case 1:System.out.print("One");s=s+"One";break;
                case 2:System.out.print("Two");s=s+"Two";break;
                case 3:System.out.print("Three");s=s+"Three";break;
                case 4:System.out.print("Four");s=s+"Four";break;
                case 5:System.out.print("Five");s=s+"Five";break;
                case 6:System.out.print("Six");s=s+"Six";break;
                case 7:System.out.print("Seven");s=s+"Seven";break;
                case 8:System.out.print("Eight");s=s+"Eight";break;
                case 9:System.out.print("Nine");s=s+"Nine";break;
                
            }
            a=a/10;
        }
        return s;
    }
    public int get(){
        return n;
    }
    public void set(int a){
        n=a;
    }
    
}
