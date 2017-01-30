/*
 * Main.java
 *
 * Created on March 17, 2016, 2:51 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p6;

interface queue{
    public void enqueue(int a);
    public int dequeue();
    public int isempty();
}

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
        QueueTest s = new QueueTest();
        s.enqueue(1);
        s.enqueue(1);
        s.enqueue(1);
        s.enqueue(1);
        s.enqueue(1);
       s.dequeue();
        s.print_while_pop();
    }
    
}
