/*
 * QueueTest.java
 *
 * Created on March 17, 2016, 3:17 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p6;

class que implements queue{
    int front;
    int rear;
    int size;
    int A[];
    que(){
       front = -1;
       rear = -1;
       size=3;
       A = new int[size];
    }
    
   
    
    public void enqueue(int a){
         if(front==size-1){
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
         if(front==-1){
             rear++;
             front++;
         }
        A[front++]=a; 
    }
    public int dequeue(){
        if(rear==front && front == -1){
            System.out.println("No elements left");
            return -1;
        }
       int a = A[rear++];
       if(front==rear){
            front=-1;
            rear=-1;
            //System.out.print("adss");
        }
       return a;
    }
    public int isempty(){
        if(front==rear && front==-1){
            return 1;
        }
        return 0;
    }
}

/**
 *
 * @author c147241
 */
public class QueueTest extends que{
    
    /** Creates a new instance of QueueTest */
      public void print_while_pop(){
        while(rear!=front){
            System.out.println(A[rear++]);
        }
        rear=front=-1;
    }
    
}
