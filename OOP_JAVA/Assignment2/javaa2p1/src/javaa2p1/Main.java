/*
 * Main.java
 *
 * Created on March 10, 2016, 3:38 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p1;

/**
 *
 * @author c147241
 */
public class Main {
    
    public static void main(String[] args) {
        Eval e = new Eval();
        String s = "1 + 20 * 2 / 4";
        int a = e.evaluate(s);
        System.out.println("Result: "+a);
    }
    
}
