import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	
	static boolean isEven(long num) {return num%2 == 0;}
	static boolean isPossible(long result, long sum, long num) {
		if(sum < num) return false;
		
		if(isEven(num)) return (result%4 == 3 || result%4 == 0);
		else return (result%4 == 1 || result%4 == 2);
	}
	
	static long solve(int n) throws Exception {
		long[] loc = new long[n];
		long maxNum = Long.MIN_VALUE;
		boolean isFalse = false;
		
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			loc[i] = Math.abs(Integer.parseInt(tk.nextToken())) + 
					Math.abs(Integer.parseInt(tk.nextToken())); 
			if(i != 0 && 
					((isEven(loc[i]) && !isEven(loc[i-1])) || 
					(!isEven(loc[i]) && isEven(loc[i-1])))
			)	isFalse = true;
			maxNum = Math.max(maxNum, loc[i]);
		}
		if(isFalse) return -1;
		if(maxNum == 0) return 0;
		
		long result = 1, sum = 1;
		while(true) {
//			System.out.println(result + " " + sum + " " + maxNum);
			if(maxNum <= sum && isPossible(result, sum, maxNum)) return result;
			result++;
			sum += result;
		}
	}
	public static void main(String[] args) throws Exception {
		int tc = Integer.parseInt(br.readLine());
		for(int t=1; t<=tc; t++) {
			int n = Integer.parseInt(br.readLine());
			
			System.out.println("#" + t + " " + solve(n));
		}
	}

}

