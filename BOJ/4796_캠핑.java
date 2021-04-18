package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        int testCase = 1;
        int L = Integer.parseInt(tk.nextToken());
        int P = Integer.parseInt(tk.nextToken());
        int V = Integer.parseInt(tk.nextToken());

        while(L != 0 || P != 0 || V != 0 ) {
            System.out.println("Case " + testCase++ + ": " + ((V/P)*L + Math.min(L,V%P)) );

            tk = new StringTokenizer(br.readLine());
            L = Integer.parseInt(tk.nextToken());
            P = Integer.parseInt(tk.nextToken());
            V = Integer.parseInt(tk.nextToken());
        }
    }
}
