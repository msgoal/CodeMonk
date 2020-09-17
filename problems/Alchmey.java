package com.fb.problems;

import java.util.Scanner;

public class Alchmey {

    public static String lettersCheck(String comb){
        int countA=0,countB=0;
        for(int i=0;i<comb.length();i++){
            if(comb.charAt(i) == 'A')
                countA++;
            else
                countB++;
        }
        return countA > countB ? "A" : "B";
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Integer N = sc.nextInt();
        sc.nextLine();
        String stonesOrder="";
        stonesOrder = sc.nextLine();
        final Integer step = 3;

        StringBuilder inp = new StringBuilder(stonesOrder);
        Integer iter = 0;
        while(inp.length() > 3){
            StringBuilder comb = new StringBuilder();

            comb.append(lettersCheck(inp.substring(iter,iter+step)));

            iter += step;

            if(comb.length() == (inp.length()/3)){
                inp = new StringBuilder(comb.toString()+inp.substring(iter,iter+inp.length()%step));
            }else
                inp = new StringBuilder(comb.toString()+inp.substring(iter,inp.length()));
            iter = 0;
        }
        String computed = inp.toString();
        System.out.println(!((computed.equals("AAA") || computed.equals("BBB")) && computed.length() == step));
    }
}

/*

Sample Input
6
3
BAB
3
BBB
5
AABBA
7
BAAABAA
11
BBBAABAAAAB
11
BABBBABBABB


Sample Output
Case #1: Y
Case #2: N
Case #3: Y
Case #4: N
Case #5: Y
Case #6: N

Submit for Practice
 */
