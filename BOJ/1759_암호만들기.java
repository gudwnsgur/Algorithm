import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static StringBuilder sb = new StringBuilder();
	static int l, c;
	static char[] ch;
	static char[] arr;
	static boolean[] visited;
	
	static void dfs(int len, int vowels, int consonants) {
		if(len == l) {
			if(vowels >= 1 && consonants >= 2) {
				for(int i=0; i<len; i++) sb.append(arr[i]);
				sb.append("\n");
			}
			return;
		}
		
		for(int i=0; i<c; i++) {
			if(!visited[i] && (len == 0 || arr[len-1] < ch[i])) {
				visited[i] = true;
				arr[len] = ch[i];
				if(ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u') 
					dfs(len+1, vowels+1, consonants);
				else dfs(len+1, vowels, consonants+1);
				visited[i] = false;
			}
		}
	}
	
	public static void main(String[] args) throws IOException{
		tk = new StringTokenizer(br.readLine());
		l = Integer.parseInt(tk.nextToken());
		c = Integer.parseInt(tk.nextToken());

		ch = new char[c];
		arr = new char[l];
		visited = new boolean[c];
		
		tk = new StringTokenizer(br.readLine());
		for(int i=0; i<c; i++) ch[i] = tk.nextToken().charAt(0);
		Arrays.sort(ch);
		
		dfs(0, 0, 0);
		System.out.println(sb.toString());
	}

}

