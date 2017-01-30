// Tic Tac Toe

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package games;
import java.lang.*;
import java.util.*;
/**
 *
 * @author c147241
 */
public class Games {
    public static char a[][] = new char[3][3];
    public static void create(){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)a[i][j]='*';
    }
    public static void print(){
        for(int i=0;i<3;i++){
            System.out.print('\n');
            for(int j=0;j<3;j++)System.out.print(a[i][j]);
        }
    }
    public static int check(int i,int j){
        char comp = 'o';
        char user = 'x';
        //for(int col=0;col<3;col++){
            if(a[i][0]==comp&&a[i][1]==comp&&a[i][2]==comp)return 2;
            if(a[i][0]==user&&a[i][1]==user&&a[i][2]==user)return 1;
            if(a[0][j]==comp&&a[1][j]==comp&&a[2][j]==comp)return 2;
            if(a[0][j]==user&&a[1][j]==user&&a[2][j]==user)return 1;
            if((i==0&&j==0)||(i==2||j==2)||(i==1&&j==1)){
                if(a[0][0]==comp&&a[1][1]==comp&&a[2][2]==comp)return 2;
                if(a[0][0]==user&&a[1][1]==user&&a[2][2]==user)return 1;
            }
            if((i==0&&j==2)||(i==2&&j==0)||(i==1&&j==1)){
                if(a[0][2]==comp&&a[1][1]==comp&&a[2][0]==comp)return 2;
                if(a[0][2]==user&&a[1][1]==user&&a[2][0]==user)return 1;
            }
            return 0;
        //}
    }
    public static int[] intelligence(int p1,int p2){
        //char comp = 'o';
        char user = 'x';
        char comp='o';
        int check=0;
        int win=0;
        int star=0;
        int b[]=new int[2];b[0]=-1;b[1]=-1;
        //for(int col=0;col<3;col++){
            for(int i=0;i<3;i++){
                int j;check=0;star=0;win=0;
                for(j=0;j<3;j++){
                    if(a[i][j]==comp)win++;
                    if(a[i][j]==user)check++;
                    if(a[i][j]=='*'){p1=i;p2=j;star++;}
                }
                 //System.out.print(check+" "+star+" ");
                if((check==2&&star==1)||(win==2&&star==1)){
                    //p1=i;p2=j;
                    b[0]=p1;b[1]=p2;
                    return b;
                }
            }
            for(int j=0;j<3;j++){
                int i;
                check=0;star=0;win = 0;
                for(i=0;i<3;i++){
                    if(a[i][j]==comp)win++;
                    if(a[i][j]==user)check++;
                    if(a[i][j]=='*'){star++;p1=i;p2=j;}
                }
                //System.out.print(check+" "+star+" ");
                if((check==2&&star==1)||(win==2&&star==1)){
                    //p1=i;p2=j;
                    b[0]=p1;b[1]=p2;
                    return b;
                    //return b;
                }
            }
            check=0;star=0;win=0;
            for(int i=0;i<3;i++){
                if(a[i][i]==user)check++;
                if(a[i][i]==comp)win++;
                if(a[i][i]=='*'){star++;p1=i;p2=i;}
            }
            if((check==2&&star==1)||(win==0&&star==1)){
                b[0]=p1;b[1]=p2;
                    return b;
            }
            check=0;star=0;win=0;
            for(int i=0;i<3;i++){
                if(a[i][2-i]==user)check++;
                if(a[i][2-i]==comp)win++;
                if(a[i][2-i]=='*'){star++;p1=i;p2=2-i;}
            }
            if((check==2&&star==1)||(win==2&&star==1)){
                b[0]=p1;b[1]=p2;
                    return b;
            }
            b[0]=-1;b[1]=-1;
            return b;
    }
    public static void Tictactoe_1player(){
         create();
        print();
        Scanner obj1=new Scanner(System.in);
        Scanner obj2= new Scanner(System.in);
        int count=0;
        Random r= new Random();
        int i1=r.nextInt(3);
        //i1=i1%3;
        int i2 = r.nextInt(3);
        //i2 = i2%3;
        int result=0;
        while(result==0&&count<9){
            System.out.print("Player 1, enter your position");
            int take=0;
            while(take==0){
                int pos1=obj1.nextInt();
                int pos2=obj2.nextInt();
                if(a[pos1][pos2]=='*'){take=1;a[pos1][pos2]='x';result=check(pos1,pos2);count++;}
                else System.out.append("Bad move. Enter again ");
                System.out.print("\n");
                print();
            }
            System.out.print("\n");
            print();
            if(result==0&&count<9){
                take=0;
            while(take==0){
               
                int pos1=r.nextInt(3);
                int pos2=r.nextInt(3);
                int intelligence[] = new int[2];
                        intelligence=intelligence(pos1,pos2);
                if(intelligence[0]==-1){
                    pos1=r.nextInt(3);
                    pos2=r.nextInt(3);
                }else{
                    pos1=intelligence[0];
                    pos2=intelligence[1];
                }
                //pos1=pos1%3;
                //pos2=pos2%3;
                if(a[pos1][pos2]=='*'){take=1;a[pos1][pos2]='o';result=check(pos1,pos2);count++;}
                //else System.out.append("Bad move. Enter again ");
                //System.out.print("\n");
                //print();
                
            }
            System.out.print("\n");
            print();
            }
        }
        if(result==1)System.out.print("Player 1 has won");
        else if(result==2)System.out.print("Player two has won");
        else{
            System.out.print(count + " It's a tie ");
             }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int wish=3;
        
        if(wish==1){
        create();
        print();
        Scanner obj1=new Scanner(System.in);
        Scanner obj2= new Scanner(System.in);
        int count=0;
        
        int result=0;
        while(result==0&&count<9){
            System.out.print("Player 1, enter your position");
            int take=0;
            while(take==0){
                int pos1=obj1.nextInt();
                int pos2=obj2.nextInt();
                if(a[pos1][pos2]=='*'){take=1;a[pos1][pos2]='x';result=check(pos1,pos2);count++;}
                else System.out.append("Bad move. Enter again ");
            }
            print();
            if(result==0&&count<9){
                take=0;
            while(take==0){
                System.out.print("Player 2, enter your position");
                int pos1=obj1.nextInt();
                int pos2=obj2.nextInt();
                if(a[pos1][pos2]=='*'){take=1;a[pos1][pos2]='o';result=check(pos1,pos2);count++;}
                else System.out.append("Bad move. Enter again ");
            }
            print();
            }
        }
        if(result==1)System.out.print("Player 1 has won");
        else if(result==2)System.out.print("Player two has won");
        else{
            System.out.print(count + " It's a tie ");
             }
        }
        if(wish==2){Guesstheword.initialise();;
        Guesstheword.start();}
        if(wish==3){
            Tictactoe_1player();
        }
    }
}
