package com.hackerearth.august.circuits;

import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.concurrent.ConcurrentLinkedQueue;

public class CyclicShift {

    public static void main(String[] args) throws Exception{

        long t,r=0;
        Scanner sc = new Scanner(System.in);
        t = sc.nextLong();
        while(t-- != 0){
            long n,k;
            n = sc.nextLong();
            k = sc.nextLong();
            sc.nextLine();
            Deque<Long> nextLook = new LinkedList<>();
            char[] bin = sc.nextLine().toCharArray();

            for(long i=0;i<bin.length;i++){
                if(bin[(int)i] == '1'){
                    nextLook.add(i);
                }
            }

            long patternLen = 0;

            while( nextLook.size() > 1 && patternLen * nextLook.size() < n){
                Deque<Long> thisLook = nextLook;
                nextLook = new LinkedList<>();
                boolean foundOne = false;

                patternLen += 1;
                long lastSeen = thisLook.peekLast() - n;
                while(thisLook.size() > 0){
                    long pos = thisLook.pollFirst();
                    if((pos - lastSeen) < patternLen){
                        lastSeen = pos;
                        continue;
                    }
                    lastSeen = pos;
                    int index = ((int)pos + (int)patternLen) % (int)n;
                    if(bin[index] == '1'){
                        if(!foundOne){
                            foundOne = true;
                            nextLook = new LinkedList<>();
                        }
                        nextLook.addLast(pos);
                    }else if(!foundOne){
                        nextLook.addLast(pos);
                    }
                }

            }
            if(nextLook.size() == 0){
                System.out.println(k-1);
                continue;
            }
            if( nextLook.size() == 1){
                patternLen = n;
            }

            long first = Collections.min(nextLook);
            System.out.println(first + (k - 1) * patternLen);
        }
    }
}
