import java.io.*;
import java.math.BigInteger;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	public static void main(String args[]) throws Exception {
		Map<Integer, Integer> map = new HashMap<>();
		int n = Integer.parseInt(br.readLine());
		int[] arr =new int[n];
		int[] res =new int[n];
		
		tk = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
			arr[i] = Integer.parseInt(tk.nextToken());
			res[i] = arr[i];
		}
		Arrays.sort(res);
		int cnt = 0;
		for(int i=0; i<n; i++) {
			if(!map.containsKey(res[i])) {
				map.put(res[i], cnt++);
			}
		}
		 StringBuilder sb = new StringBuilder();
		for(int i=0; i<arr.length; i++) {
			sb.append(map.get(arr[i])).append(" ");
		}
		System.out.println(sb.toString());
  }
}
