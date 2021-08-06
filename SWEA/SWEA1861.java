import java.io.*;
import java.util.*;

class Loc {
	int x, y;
	Loc(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class SWEA1861 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    
    static HashMap<Integer, Loc> map; 
    // 숫자의 위치를 빠르게 찾기 위해 사용   ex) 3 -> (5, 2) 
    static int[] result; // 이동할 수 있는 방의 개수
    static int n;
    
    // 숫자  a와  b가 근접해 있는지
    static boolean isNear(int a, int b) {
    	return Math.abs(map.get(a).x - map.get(b).x) + Math.abs(map.get(a).y - map.get(b).y) == 1;
    }
    
	public static void main(String[] args) throws IOException {
		int tc = Integer.parseInt(br.readLine());
		for(int t=1; t<=tc; t++) {
			n = Integer.parseInt(br.readLine());
			map = new HashMap<>();
			
			result = new int[n*n + 1];
			Arrays.fill(result, 1);	// 모든 방은 자신의 방을 들어갈 수 있으므로
			
			for(int i=0; i<n; i++) {
				tk = new StringTokenizer(br.readLine());
				for(int j=0; j<n; j++) {
					// 숫자 (key) - 위치 (value) 를 map 에 추가
					map.put(Integer.parseInt(tk.nextToken()),  new Loc(i, j));
				}
			}
			
			// n*n 은 자신의 방밖에 들어가지 못한다.
			// n*n-1 부터  자신보다 하나 큰 수와 근접해 있는지를 판단  
			for(int i=n*n-1; i>=1; i--) {
				if(isNear(i, i+1)) result[i] += result[i+1]; 
			}	
			
//			// result 출력
//			for(int i=1; i<=n*n; i++) System.out.print(i + " : " + result[i]);
//			System.out.println();
			
			
			// result의 숫자중 이동할 수 있는 방의 개수가 최대이며 그 중 수가 가장 작은 것을 
			// maxIdx(숫자), maxNum(방의 개수)에 저장
			int maxIdx = 1, maxNum = result[1];
			for(int i=2; i<=n*n; i++) {
				if(result[i] > maxNum) {
					maxIdx = i;
					maxNum = result[i];
				}
			}
			
			sb.append("#").append(t).append(" ").append(maxIdx).append(" ").append(maxNum).append("\n");
			}
		System.out.println(sb.toString());
	}
}
