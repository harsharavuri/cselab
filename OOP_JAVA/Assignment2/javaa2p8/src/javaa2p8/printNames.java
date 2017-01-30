/*
 * printNames.java
 *
 * Created on March 10, 2016, 3:27 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p8;
import java.util.*;
import java.lang.*;
/**
 *
 * @author c147241
 */
public class printNames {
    
    /** Creates a new instance of printNames */
    public void __printNames(String a) {
        StringTokenizer b = new StringTokenizer(a,":");
        int check = 1;
        while(b.hasMoreTokens()){
            String s1 = b.nextToken();
            if(check%2==0){
                System.out.println(s1);
            }
            check++;
        }
    }
    
}
