/*
 * Main.java
 *
 * Created on March 17, 2016, 2:51 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p5;

/**
 *
 * @author c147241
 */
public class Main {
    
    /** Creates a new instance of Main */
   
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        StackTest s = new StackTest();
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.print_while_pop();
    }
    
}
