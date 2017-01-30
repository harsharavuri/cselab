/*
 * Operations.java
 *
 * Created on March 10, 2016, 2:19 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package arithmeticoperation;

/**
 *
 * @author c147241
 */

public class Operations{
    public int add(int a, int b){
        return a+b;
    }
    public int subtract(int a, int b){
        return a-b;
    }
    public int multiply(int a, int b){
        return a*b;
    }
    public int divide(int a, int b){
        if(b==0)return -1;
        return a/b;
    }
}

