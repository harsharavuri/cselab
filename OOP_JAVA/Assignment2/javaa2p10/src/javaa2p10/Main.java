/*
 * Main.java
 *
 * Created on March 10, 2016, 3:11 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p10;
import java.util.*;
import java.lang.*;
/**
 *
 * @author c147241
 */
public class Main {
    
    /** Creates a new instance of Main */

    public static void main(String[] args) {
        int a =6;
        Reverse r = new Reverse();
        int sum=0;
        int s = r.reverse(sum);
        r.set(s);
        String result = r.toString();
        System.out.println(result);
        // TODO code application logic here
    }
    
}
