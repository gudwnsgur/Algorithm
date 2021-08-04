import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		int tc = Integer.parseInt(br.readLine());
		for (int i = 1; i <= tc; i++) {
			int N = Integer.parseInt(br.readLine());
			int len = 0, result = 0, mid = N/2;
			
			for(int j=0; j<N; j++) {
				String s = br.readLine();
				for(int k=0; k<N; k++) {
					if(mid-len <= k && k <= mid+len) result += s.charAt(k) - 48;
				}
				len = j < mid ? len + 1 : len - 1;
			}
			sb.append("#").append(i).append(" ").append(result).append("\n");
		}
		System.out.println(sb.toString());
	}
}
