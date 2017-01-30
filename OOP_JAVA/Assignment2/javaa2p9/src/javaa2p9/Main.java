/*
 * Main.java
 *
 * Created on March 17, 2016, 3:44 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package javaa2p9;

/**
 *
 * @author c147241
 */
class print{
    static int a;
    
    public int reverse(int sum){
        if(a==0){a=512;return sum;}
        sum = sum*10 + a%10;
        a=a/10;
        return reverse(sum);
    }
      public static String toWords(int b){
        String s="";
        String s1="";
        //print ex = new print();
        //int c = ex.reverse(a);
        a=b;
        int count=0;
        while(a!=0){
            int num = a%10;
            if(count==2){
                s1="Hundred";
                s=s1+s;
            }else if(count==3){
                s =  "Thousand "+s;
            }
            switch(num){
                case 0:s="Zero"+s;break;
                case 1:s="One"+s;break;
                case 2:s="Two"+s;break;
                case 3:s="Three"+s;break;
                case 4:s="Four"+s;break;
                case 5:s="Five"+s;break;
                case 6:s="Six"+s;break;
                case 7:s="Seven"+s;break;
                case 8:s="Eight"+s;break;
                case 9:s="Nine"+s;break;
                
                }
            
           if(count==1){
               if(num==1){
                    switch(num){
                case 0:s="Ten";break;
                case 1:s="Eleven";break;
                case 2:s="Twelve";break;
                case 3:s="Thirteen";break;
                case 4:s="Fourteen";break;
                case 5:s="Fifteen";break;
                case 6:s="Sixteen";break;
                case 7:s="Seventeen";break;
                case 8:s="Eightteen";break;
                case 9:s="Nineteen";break;
                
                }
                }
           }
            
            a=a/10;
            count++;
        }
        return s;
    }
}
public class Main {
    
    /** Creates a new instance of Main */
    public Main() {
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        print ex = new print();
        String s = ex.toWords(214);
        System.out.print(s);
    }
    
}
