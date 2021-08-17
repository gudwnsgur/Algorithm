import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws IOException{
		int n = Integer.parseInt(br.readLine());
		
		for(int i=n; i>=0; i--) {
			if(i % 5 == 0 && (n-i) % 3 == 0) {
				System.out.println(((i/5) + (n-i)/3));
				return;
			}
		}
		System.out.println(-1);
	}
}

