package javaapplication1;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author c147241
 */
public class stack {
    private static int []elements = new int[25];
    private static int size;
    private static int top;
    public stack(){
        size=25;
        top=-1;
    }
    public static void push(int a){
        top++;
        if(top==size){
            System.out.println("Size limit reached");
        }else{
            elements[top] = a;
        }
    }
    public static int pop(){
        if(top==-1){
            System.out.print("No element available to output");
            return -1;
        }else
            return elements[top--];
    }
    public static int isempty(){
        if(top==-1)return 1;
        return 0;
    }
    public static void print(){
        while(top!=-1){
            System.out.println(elements[top--]);
        }
    }
};
