import java.io.*;
import java.util.*;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    
	public static void main(String[] args) throws IOException{
		for(int tc = 1 ; tc <= 10 ; tc ++) {
			LinkedList<Integer> list = new LinkedList<>();			
			int N = Integer.parseInt(br.readLine());
			
			tk = new StringTokenizer(br.readLine());
			for(int i=0; i<N; i++) list.add(Integer.parseInt(tk.nextToken()));

			int op = Integer.parseInt(br.readLine());
			tk = new StringTokenizer(br.readLine());
			
			for(int i=0; i<op; i++) {
				tk.nextToken();
				int loc = Integer.parseInt(tk.nextToken());
				int size = Integer.parseInt(tk.nextToken());
				for(int j=0; j<size; j++) {
					list.add(loc++, Integer.parseInt(tk.nextToken()));
				}
			}
			sb.append("#").append(tc).append(" ");
			for(int i=0; i<10; i++) sb.append(list.get(i)).append(" ");
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
}

