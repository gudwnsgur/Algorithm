import java.util.*;

class Node {
	int idx, height;
	Node(int idx, int height) {
		this.idx = idx;
		this.height = height;
	}
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    
	public static void main(String[] args) throws IOException{
		int n = Integer.parseInt(br.readLine());
		tk = new StringTokenizer(br.readLine());

		int[] tower = new int[n+1];
		for(int i=1; i<=n; i++) tower[i] = Integer.parseInt(tk.nextToken());
		
		Stack<Node> s = new Stack<>();
		s.add(new Node(1, tower[1]));
		sb.append("0 ");

		for(int i=2; i<=n; i++) {
			while(!s.isEmpty() && tower[i] >= s.peek().height) s.pop();
			
			sb.append(s.isEmpty() ? "0 " : (s.peek().idx + " "));
			s.add(new Node(i, tower[i]));
		}
		System.out.println(sb.toString());
	}
}

