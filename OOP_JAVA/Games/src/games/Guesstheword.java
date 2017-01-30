/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package games;
import java.util.*;
import java.lang.*;
/**
 *
 * @author c147241
 */
public class Guesstheword {
    public static String str[] = new String[5];
    public static void initialise(){
        str[0]="excellent";
        str[1]="perfectshot";
        str[2]="acquaintance";
        str[3]="deservance";
        str[4]="rocknroll";

    }
    public static void start(){
        int check=1;
        Scanner sc= new Scanner(System.in);
        Random r = new Random();
        
        while(check==1){
            char misses[] = new char[26];
            int trackmisses=0;
            for(int i=0;i<26;i++)misses[i]='*';
            int game=r.nextInt(5);
            //game = game%4;
            int result=0;
            int a=str[game].length();
            char word[]=new char[a+1];
            word[a]='\0';
            char captured[] = new char[a+1];
            for(int i=0;i<a;i++)captured[i]='*';
            captured[a]='\0';
            int trackcaptured=0;
            for(int i=0;i<a;i++){
                word[i]='*';
            }
            char main[]=new char[a];
            main=str[game].toCharArray();
            int count=0;
            while(result==0&&count<a){
                System.out.print("\n");
                String s = sc.nextLine();
                char st[] = new char[3];
                st= s.toCharArray();
                int get = 0;
                for(int i=0;i<a;i++){
                    if(st[0]==main[i]){
                        if(word[i]=='*'){word[i]=st[0];count++;get=1;}
                        else get=2;
                    }
                }
                if(get==0){
                    misses[trackmisses]=st[0];trackmisses++;
                }else if(get==1){
                    captured[trackcaptured]=st[0];
                    trackcaptured++;
                }
                else{
                    System.out.println(" Already present ");
                }
                System.out.println(word);
                System.out.print("Misses: ");
                for(int i=0;i<trackmisses;i++)System.out.print(misses[i]);
                System.out.print("\n"+ " Captured: ");
                for(int i=0;i<trackcaptured;i++)System.out.print(captured[i]);
            }
            if(count==a){
                System.out.print("\n"+ " You did it .");
            }
            
            check=0;
        }
    }
}
