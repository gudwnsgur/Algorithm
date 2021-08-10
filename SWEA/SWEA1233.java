import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    static char[] tree;
    static int n;
    
    static boolean isVaild() {
    	for(int i=1; i<=n/2; i++) if(tree[i] >= '0' && tree[i] <= '9') return false;
    	for(int i=n/2+1; i<=n; i++) if(tree[i] < '0' || tree[i] > '9') return false;
    	return true;
    }
    
	public static void main(String[] args) throws IOException {
		for(int tc = 1; tc <= 10; tc++) {
			sb.append("#").append(tc).append(" ");
			tree = new char[201];
			n = Integer.parseInt(br.readLine());
			for(int i=0; i<n; i++) {
				tk = new StringTokenizer(br.readLine());
				tree[Integer.parseInt(tk.nextToken())] = tk.nextToken().charAt(0);
			}
			sb.append(isVaild() ? "1" : "0").append("\n"); 
		}
		System.out.println(sb.toString());
	}
}
