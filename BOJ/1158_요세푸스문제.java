import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    
	public static void main(String[] args) throws IOException {
		tk = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(tk.nextToken());
		int K = Integer.parseInt(tk.nextToken());
		ArrayList<Integer> arr= new ArrayList<>();
		for(int i=1; i<=N; i++) arr.add(i);
		
		sb.append("<");
		int idx = 0;
		while(arr.size() != 1) {
			idx = (idx + K - 1) % arr.size();
			sb.append(arr.get(idx)).append(", ");
			arr.remove(idx);
		}
		sb.append(arr.get(0)).append(">\n");
		
		System.out.println(sb.toString());
	}

}

