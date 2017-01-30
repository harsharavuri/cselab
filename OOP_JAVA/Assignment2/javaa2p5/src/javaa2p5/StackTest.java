/*
 * StackTest.java
 *
 * Created on March 17, 2016, 2:51 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p5;
interface Stack{
    public void push(int a);
    public int pop();
    public int isempty();
}

/**
 *
 * @author c147241
 */
public class StackTest implements Stack {
    int size;
    int top;
    int[] A;
    /** Creates a new instance of StackTest */
    public StackTest() {
        
        top=-1;
        size=2;
        A = new int[size];
        // System.out.print("asdas");
    }
    public void push(int a){
        if(top==size-1){
            int[]b = new int[2*size];
            for(int i=0;i<size;i++){
                b[i]=A[i];
            }
            A = new int[2*size];
            for(int i=0;i<size;i++){
                A[i]=b[i];
            }
            size = 2*size;
        }
        //if(a==3)System.out.print("asdas");
        A[++top]=a;
       
    }
    public int pop(){
        if(top==-1){
            System.out.println("Invalid");return -1;
        }
        return A[top--];
    }
    public int isempty(){
        if(top==-1)return 1;
        return 0;
    }
    public void print_while_pop(){
        while(top!=-1){
            System.out.println(A[top--]);
        }
    }
    
}
