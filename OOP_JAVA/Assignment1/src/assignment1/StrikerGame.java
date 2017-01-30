/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment1;
import java.lang.*;
import java.util.*;
/**
 *
 * @author c147241
 */
public class StrikerGame {
    public static void playgame(){
        Random a= new Random();
        int []b=new int[3];
        for(int i=0;i<3;i++){
            b[i] = a.nextInt(10);
        }
        int striker=0,ball=0,score=100;
        while(striker!=3&&score>0){
            striker=0;ball=0;
            Scanner sc = new Scanner(System.in);
            int input_number;
            int local_counter=0;
            while(local_counter<3){
                input_number = sc.nextInt();
                if(input_number==b[local_counter])striker++;
                else if(input_number==b[0]||input_number==b[1]||input_number==b[2])ball++;
                local_counter++;
            }
            System.out.println(" \nStrikes: "+striker+" \n Balls: "+ ball);
            if(striker!=3)score=score-5;
        }
        System.out.println("\n Score: "+score);
    }
}
