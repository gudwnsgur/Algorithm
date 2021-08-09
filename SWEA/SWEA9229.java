import java.io.*;
import java.util.*;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    
	public static void main(String[] args) throws IOException{
		int tc = Integer.parseInt(br.readLine());
		for(int t = 1; t <= tc; t ++) {
			sb.append("#").append(t).append(" ");
			
			tk = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(tk.nextToken());
			int M = Integer.parseInt(tk.nextToken());
			
			int[] arr = new int[N];
			tk = new StringTokenizer(br.readLine());
			for(int i=0; i<N; i++) arr[i] = Integer.parseInt(tk.nextToken());
			Arrays.sort(arr);
			
			if(arr[0] + arr[1] > M) {
				sb.append("-1\n");
				continue;
			}
			
			int left = 0, right = N-1;
			int result = arr[0] + arr[1];
			while(left < right) {
				int cur = arr[left] + arr[right];
				if(cur > M) right--;
				else {
					result = Math.max(result, cur);
					if(cur == M) break;
					left++;
				}
			}
			sb.append(result).append("\n");
		}
		System.out.println(sb.toString());
	}
}

