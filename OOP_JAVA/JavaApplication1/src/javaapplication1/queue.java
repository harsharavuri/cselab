/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

/**
 *
 * @author c147241
 */
public class queue {
    
	private static int []elements = new int[25];
	private static int size;
	private static int front;
	private static int rear;

public static void queue(){
		rear=front=-1;
		size=25;
	}
public static void enqueue(int d){
	if(rear==-1){
		front++;rear++;elements[rear]=d;
	}else if(front==(rear+1)%size)System.out.println("Size limit reached ");
	else{
		rear=(rear+1)%size;
		elements[rear]=d;
	}
}
public static int dequeue(){
	if(front==-1){System.out.println("Queue is empty ");return -1; }
	else if(front==rear){
		int temp=rear;
		rear=front=-1;
		return elements[temp];
	}
	else{
		int temp=rear;
		front=(front+1)%size;
		return elements[temp];
	}
}
public static int isempty(){
	if(front==-1)return 1;
	else
	return 0;
 }
public static void print(){
    while(rear!=front){
        System.out.println(elements[front]);
        front=(front+1)%size;
    }
}
};

