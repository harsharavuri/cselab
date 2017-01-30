/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package havefun;

/**
 *
 * @author c147241
 */
import java.lang.*;
import java.util.*;
class check{
    public static void binarytree(){
        BinaryTree T=new BinaryTree();
        T=null;
        Scanner sc=new Scanner(System.in);
        int d;
        System.out.println("Enter the values to be inserted,-1 to exit");
        d=sc.nextInt();
        while(d!=-1){
            T=BinaryTree.insert(d,T);
            d=sc.nextInt();
        }
        BinaryTree.print(T);
    }
    public static void sample(int a,int b){
        int temp=a;
        a=b;
        b=temp;
    }
}
public class HaveFun {

    
    public static void main(String[] args) {
       //check.binarytree();
        int c=1;
        int d=2;
        check.sample(c, d);
        System.out.println(c+" "+d+" ");
    }
    
}
