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
public class prob2 {
    static void least_dist(){
        
        double[][] points = {{-1, 2, 3}, {-1, -1, -1}, {5, 2, 1}, 
           {3, 0.5, 9}, {3.5, 2, -1.5}, {8, 1.5, - 3}, {-4, 4, 2}, {-7, 4, -0.5}};
        double min=100000;
        int i=0;int point1=-1,point2=-1;
        for(i=0;i<8;i++){
            for(int j=i+1;j<8;j++){
                double dist = (points[i][0]-points[j][0])*(points[i][0]-points[j][0])+
                                (points[i][1]-points[j][1])*(points[i][1]-points[j][1])+
                                (points[i][2]-points[j][2])*(points[i][2]-points[j][2]);
                dist = Math.sqrt(dist);
                if(dist<min){min=dist;point1=i;point2=j;}
            }
        }
        System.out.println("Points are: "+(point1+1)+" "+(point2+1)+" Distance: "+min);
    System.out.println("Sample output:\n Among eight points ");
            for(i=0;i<8;i++){
                System.out.println("("+points[i][0]+","+points[i][1]+","+points[i][2]+")");
            }
            System.out.println("Closest pair: ");
            System.out.println("("+points[point1][0]+","+points[point1][1]+","+points[point1][2]+")");
            System.out.println("("+points[point2][0]+","+points[point2][1]+","+points[point2][2]+")");
            System.out.println("With distance: "+min);
    }
}
