/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment1;

/**
 *
 * @author c147241
 */
public class prob1 {
    public static int average(int[] array ){
        int sum=0;
        for(int i=0;i<10;i++){
            sum = sum+array[i];
        }
        sum = sum/10;
        return sum;
    }
    public static double average(double[] array){
        double sum=0;
        for(int i=0;i<10;i++){
            sum = sum+array[i];
        }
        sum = sum/10;
        return sum;
    }
}
