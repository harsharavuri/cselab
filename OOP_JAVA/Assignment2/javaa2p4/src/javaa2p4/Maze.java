/*
 * Maze.java
 *
 * Created on March 17, 2016, 4:15 PM
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
public class Maze {
    
    /** Creates a new instance of Maze */
    char a[][] = new char[8][8];
    int destinyx=7;
    int destinyy=7;
    Random r = new Random();
    int posx = r.nextInt(3);
    int posy = r.nextInt(6);
    public Maze(){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                a[i][j]='*';
            }
        }
        
    }
    public void create_map(){
        Random r = new Random();
        int check = 0;
        int curx=posx;
        int cury=posy;
        a[curx][cury]='@';
        int buff=0;
        while(check==0){
            //while(buff==0){
            int p = r.nextInt(3);
            int inx=curx;
            int iny = cury;
            if(p==0){
                curx++;
            }else if(p==1){
                cury--;
            }else{
                cury++;
            }
           /* if(a[curx][cury]!='@'){buff=1;
            }else{
                curx=inx;
                cury=iny;
            }*/
           //}
        a[curx][cury]='@';
        if(curx==7 && cury==7)check=1;
        else if(curx==7){
            while(cury!=8){
                a[curx][cury++]='@';
            }
            check=1;
        }else if(cury==7){
            while(curx!=8){
                a[curx++][cury]='@';
            }
            check=1;
        }else if(cury==0){
            a[++curx][cury]='@';
            a[curx][++cury]='@';
        }
       }
        a[posx][posy]='#';
    }
    
    public int playgame(char ch){
        int inx=posx;
        int iny=posy;
        if(ch=='d'){
            posy++;
        }
        if(ch=='l'){
            posx--;
        }
        if(ch=='r'){
            posx++;
        }
        if(ch=='u'){
            posy--;
        }
        if(a[posx][posy]!='@'){
            posx=inx;
            posy=iny;
        }else{
            a[inx][iny]='.';
        }
        if(posx==destinyx && posy == destinyy)return 1;
        a[posx][posy]='#';
        return 0;
    }
    
    public void print_map(){
        for(int i=0;i<8;i++){
            for(int y=0;y<8;y++){
                System.out.print(a[i][y]+"  ");
            }
            System.out.println("\n");
        }
    }
}
