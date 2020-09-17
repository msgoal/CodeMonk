package com.fb.problems;

import java.util.Scanner;

public class TravelRestrictions {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Integer N = sc.nextInt();
		sc.nextLine();
		
		String incomming="";
		String outgoing="";
		
		incomming = sc.nextLine();
		outgoing = sc.nextLine();
		for(int m=0;m < N; m++){
			boolean lflag = true;
			boolean rflag = true;
			StringBuilder lres = new StringBuilder();
			StringBuilder rres = new StringBuilder();
			char I = incomming.charAt(m);
			char O = outgoing.charAt(m);
			
			for(int l = m-1; l >= 0; l--){
				if(O == 'Y' && lflag && incomming.charAt(l) == 'Y'){
					lres.append("Y");
					if(!(outgoing.charAt(l) == 'Y'))
						lflag = false;
				}else{
					lres.insert(0,"N");
					lflag=false;
				}
			}
			
			for(int r = m;r < N; r++){
				if(r == m){
					rres.append("Y");
				}else if(O == 'Y' && rflag && incomming.charAt(r) == 'Y'){
					rres.append("Y");
					if(!(outgoing.charAt(r) == 'Y'))
						rflag = false;
				}else{
					rres.append("N");
					rflag = false;
				}
			}
			
			System.out.println(lres.append(rres).toString());
		}
		sc.close();
	}
}

/*
Sample Input
5
2
YY
YY
2
NY
YY
2
NN
YY
5
YNNYY
YYYNY
10
NYYYNNYYYY
YYNYYNYYNY

Sample Output
Case #1:
YY
YY
Case #2:
YY
NY
Case #3:
YN
NY
Case #4:
YNNNN
YYNNN
NNYYN
NNNYN
NNNYY
Case #5:
YYYNNNNNNN
NYYNNNNNNN
NNYNNNNNNN
NNYYNNNNNN
NNYYYNNNNN
NNNNNYNNNN
NNNNNNYYYN
NNNNNNYYYN
NNNNNNNNYN
NNNNNNNNYY


 */
