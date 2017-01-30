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
public class BinaryTree {
    int data;
    BinaryTree left;
    BinaryTree right;
    BinaryTree(){
        data=0;
        left=null;
        right=null;
    }
    static BinaryTree insert(int a,BinaryTree T){
        if(T==null){
            T=new BinaryTree();
            T.data=a;
            T.left=null;
            T.right=null;
            return T;
        }
        else{
            if(a>T.data)T.left = BinaryTree.insert(a, T.left);
                    else T.right = BinaryTree.insert(a, T.right);
        }
       return T;
    }
    static void print(BinaryTree T){
        if(T==null)return;
        print(T.left);
        System.out.println(T.data);
        print(T.right);
    }
}
