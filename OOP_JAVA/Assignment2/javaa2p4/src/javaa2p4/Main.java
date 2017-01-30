/*
 * Main.java
 *
 * Created on March 17, 2016, 4:14 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p4;
import java.util.*;
import java.lang.*;
/**
 *
 * @author c147241
 */
public class Main {
    
    /** Creates a new instance of Main */
    public Main() {
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Maze a = new Maze();
        //a.print_map();
        a.create_map();
        a.print_map();
        Scanner sc = new Scanner(System.in);
        String ch;
        int check=0;
        do{
            System.out.println("Enter input");
            ch = sc.nextLine();
            check = a.playgame(ch.charAt(0));
            a.print_map();
        }while(check!=1);
        System.out.println("Congratulations, You have finished the game");
        // TODO code application logic here
    }
    
}
