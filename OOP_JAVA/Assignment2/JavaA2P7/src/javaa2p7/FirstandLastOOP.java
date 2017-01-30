/*
 * FirstandLastOOP.java
 *
 * Created on March 10, 2016, 2:40 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */
package javaa2p7;
import java.util.*;
import java.lang.*;

public class FirstandLastOOP {
    
    /** Creates a new instance of FirstandLastOOP */
    public String FirstandLastOOPP(String a) {
            int first=-1;
            int last=1;
            String result="";
            int length=a.length();
            int i=0;
            while(i<length){
                if(a.charAt(i)=='o'){
                    i++;
                    if(i<length && a.charAt(i)=='o'){
                        i++;
                        if(i<length && a.charAt(i)=='p'){
                            if(first==-1){first=i-2;}
                            else{last=i-2;}
                        }
                    }
                }
                i++;
            }
            
            for(int j=first+2;j<=last;j++){
                result = result+a.charAt(j);
            }
            return result;
    }
    
}
