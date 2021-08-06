import java.io.*;
import java.util.*;

public class SWEA3499 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) throws IOException {
    	int tc = Integer.parseInt(br.readLine());
    	for(int i=1; i<=tc; i++) {
    		int n = Integer.parseInt(br.readLine());
    		tk = new StringTokenizer(br.readLine());
    		String[] input = new String[n];
    		for(int j=0; j<n; j++) input[j] = tk.nextToken();

    		sb.append("#").append(i).append(" ");
    		for(int j=0, a=0, b = (n % 2 == 0 ? n/2 : n/2 + 1); j<n; j++) {
    			if(j % 2 == 0) sb.append(input[a++]).append(" ");
    			else sb.append(input[b++]).append(" ");
    		}
    		sb.append("\n");
    	}
    	System.out.println(sb.toString());
    }
}

