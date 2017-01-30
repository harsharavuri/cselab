/*
 * Eval.java
 *
 * Created on March 10, 2016, 3:39 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p1;
import java.util.*;
import java.lang.*;
/**
 *
 * @author c147241
 */
public class Eval {
    
    /** Creates a new instance of Eval */
   public int evaluate(String a){
       StringTokenizer s = new StringTokenizer(a," ");
       int result=0;
        String v1 = s.nextToken();
        int val1 = Integer.parseInt(v1);
       while(s.hasMoreTokens()){
          
           String ch = s.nextToken();
           String v2 = s.nextToken();
           char c = ch.charAt(0);
            
               int val2 = Integer.parseInt(v2);
           switch(c){
              
               case '+':val1=val1+val2;break;
               case '-':val1=val1-val2;break;
               case '*':val1=val1*val2;break;
               case '/':val1=val1/val2;break;
               default:val1=-1;break;
           }
        
       }
       return val1;
   }
    
}
