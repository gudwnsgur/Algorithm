import java.io.*;
import java.util.*;

public class SWEA1204 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static StringTokenizer tk;
	public static void main (String[] args) throws IOException{
		int tc = Integer.parseInt(br.readLine());
		while(tc-- > 0 ) {
			int cur = Integer.parseInt(br.readLine());
			int [] scores = new int[101];
			tk = new StringTokenizer(br.readLine());
			
			while(tk.hasMoreTokens()) {
				scores[Integer.parseInt(tk.nextToken())]++;
			}
			
			int maxNum = 0, maxCnt = 0;
			for(int i=0; i<=100; i++) {
				if(maxCnt <= scores[i]) {
					maxCnt = scores[i];
					maxNum = i;
				}
			}
			
			System.out.println("#" + cur + " " + maxNum);
		}
	}
}

