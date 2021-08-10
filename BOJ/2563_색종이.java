import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    
	public static void main(String[] args) throws IOException {
		int N = Integer.parseInt(br.readLine());
		boolean [][] paper = new boolean[100][100];
		int result =0;
		for(int n=0; n<N; n++) {
			tk = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(tk.nextToken());
			int y = Integer.parseInt(tk.nextToken());
			
			for(int i=x; i<x+10; i++) {
				for(int j=y; j<y+10; j++) {
					paper[i][j] = true;
				}
			}
		}
		
		for(int i=0; i<100; i++) {
			for(int j=0; j<100; j++) {
				if(paper[i][j]) result++;
			}
		}
		System.out.println(result);

	}
}

