import java.io.*;
import java.util.*;

public class SWEA1208 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	
	static int getDiff(int dump, int[] boxes) {
		Arrays.sort(boxes);

		while(dump-- > 0 ) {
			boxes[0]++;
			boxes[99]--;
			Arrays.sort(boxes);
		}
		return boxes[99] - boxes[0];
	}
	
	public static void main(String[] args) throws IOException{
		for(int tc = 1; tc <= 10; tc++) {
			int dump = Integer.parseInt(br.readLine());
			
			int[] boxes = new int[100];
			tk = new StringTokenizer(br.readLine());
			for(int i=0; i<100; i++) boxes[i] = Integer.parseInt(tk.nextToken());
			
			System.out.println("#" + tc + " " + getDiff(dump, boxes));
		}
	}

}

