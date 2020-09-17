package com.hackerearth.august.circuits;

import java.util.Arrays;
import java.util.Scanner;

public class MinimumANDxorOR {

    static int maxAndXor(int arr[], int n)
    {
        int ans = 9999999;

        Arrays.sort(arr);

        for (int i = 0; i < n - 1; i++)
        {
            ans = Math.min(ans,
                    arr[i] ^ arr[i + 1]);
        }

        return ans;
    }

    public static void main(String[] args){
        long t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextLong();
        while(t-- != 0){
            int n;
            n = sc.nextInt();
            sc.nextLine();
            int[] A = Arrays.asList(sc.nextLine().split(" ")).stream().mapToInt(Integer::parseInt).toArray();

            System.out.println(maxAndXor(A,n));
        }
    }
}
