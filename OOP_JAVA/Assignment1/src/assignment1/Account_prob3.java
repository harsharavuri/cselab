/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment1;
import java.util.*;
import java.lang.*;
/**
 *
 * @author c147241
 */
public class Account_prob3 {
    public static int id;
    public static double balance;
    public static double initialbalance;
    public static double annualInterestRate;
    public static String date;
    public Account_prob3(){
        id=0;
        initialbalance=0;
        balance=0;
        annualInterestRate=0;
        date = new Date().toString();
    }
    public Account_prob3(int id_input, double initial_balance){
        id=id_input;
        initialbalance=initial_balance;
        balance = initial_balance;
        date = new Date().toString();
    }
    public static int get_id(){return id;}
    public static double get_balance(){return balance;}
    public static double get_annualInterestRate(){return annualInterestRate;}
    public static String get_date(){return date;}
    public static double get_monthlyInterestRate(){return annualInterestRate/12;}
    public static double get_monthlyInterest(){return balance*annualInterestRate/1200;}
    public static void mod_id(int id_input){id = id_input;}
    public static void mod_balance(double balance_input){balance = balance_input;}
    public static void mod_annualInterestRate(double annualInterestRate_input){annualInterestRate = annualInterestRate_input;}
    public static void deposit(int amount){balance = balance+amount;}
    public static int withdraw(int amount)
    {   
        if(balance<amount){System.out.println("Low on balance"); return 0;}
        else {balance = balance-amount;return amount;}
    }
    public static void print(){
        System.out.println("Account number: "+id);
        System.out.println("Balance: "+balance+" Monthly Interest: "+get_monthlyInterest());
        System.out.println("Date Created: "+date.toString());
    }
}
