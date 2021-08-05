import java.util.*;
import java.io.*;

public class SWEA1225 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    static int[] decrease = {1, 2, 3, 4, 5};
    
    public static void main(String[] args) throws IOException {
    	for(int i=1; i<=10 ; i++) {
    		int tc = Integer.parseInt(br.readLine());
    		
    		tk = new StringTokenizer(br.readLine());
    		Queue<Integer> queue = new LinkedList<>();
    		for(int j=0; j<8; j++) queue.add(Integer.parseInt(tk.nextToken()));
    		
    		int idx = 0, num = i;
    		while(num > 0) {
    			num = (queue.poll() - decrease[idx]);
    			queue.add(num <= 0 ? 0 : num);
    			idx  = (idx+1) % 5;
    		}
    		
    		sb.append("#").append(i).append(" ");
    		while(!queue.isEmpty()) sb.append(queue.poll()).append(" ");
    		sb.append("\n");
    	}
    	System.out.println(sb.toString());
    }

}
