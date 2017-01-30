/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment1;
import java.lang.*;
import java.util.*;
/**
 *
 * @author c147241
 */
public class prob4 {
    public static int getNumber(char uppercaseLetter){
        Random r = new Random();
        return r.nextInt(10);
    }
    public static void local_main(){
        String s;
        Scanner sc = new Scanner(System.in);
        s = sc.nextLine();
        s=s.toLowerCase();
        int a;
        int i=0;String c="";
        while(i<s.length()){
            char ch = s.charAt(i);
            if((ch>='a'&&ch<='z')){
                
                int y = ch;
               if(ch>='s')y--;
               if(ch=='z')y--;
                int z='a';
               a = (y-z)/3;
                a=a+2;
               c= c+a;    
            }else c=c+ch;
            i++;
        }
        System.out.println("Required value is: "+c);
    }
}
