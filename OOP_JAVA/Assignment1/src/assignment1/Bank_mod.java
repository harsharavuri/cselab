/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment1;
import java.lang.*;
import java.util.*;
/**
 *
 * @author c147241
 */
public class Bank_mod extends Account_prob3 {
    private static int duration;
    private static double CDannualinterestrate;
    public Bank_mod(){
        id=0;
        balance=0;
        initialbalance=0;
        annualInterestRate=0;
        duration=0;
        CDannualinterestrate=0;
        date = new Date().toString();
    }
    public Bank_mod(int id_input, double initial_balance,double interest,int duration){
        id=id_input;
        balance = initial_balance;
        initial_balance=balance;
        date = new Date().toString();
        this.duration=duration;
        annualInterestRate=interest;
        int x=duration/3;
        CDannualinterestrate=interest+0.5*(x);
    }
    public static double get_cdmonthlyInterest(int i){balance=balance+balance*i*CDannualinterestrate/1200;return balance;}
    public static int get_duration(){return duration;}
    public static void set_duration(int dur){duration=dur;}
    public static double get_CDannualinterestrate(){return CDannualinterestrate;}
    public static void set_CDannualinterestrate(int CDAI){CDannualinterestrate=CDAI;}
    public static void printcd(){
        System.out.println("Account number: "+id);
        System.out.println("Date Created: "+date.toString());
        System.out.println("CDA Created: "+CDannualinterestrate);
        for(int i=1;i<=duration;i++){
            System.out.println("Balance: "+get_cdmonthlyInterest(i));
        }
    }
}
