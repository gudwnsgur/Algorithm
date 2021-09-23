import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n;	// 화학 물질의 개수
	static ArrayList<int[]> chemicals = new ArrayList<>(); // 화학 물질
	
	public static void main(String[] args) throws IOException {
		n = Integer.parseInt(br.readLine());
		
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			chemicals.add(new int[] {Integer.parseInt(tk.nextToken()),
					Integer.parseInt(tk.nextToken())});
		}

		
		// 화학물질을 최고온도 오름차순으로 정렬
		Collections.sort(chemicals, (o1, o2) -> Integer.compare(o1[1], o2[1]));	
		
		int curTemp = chemicals.get(0)[1]; // 현재 사용할 냉장고의 최고 온도
		int refrigerator = 1;	// 냉장고 수
		
		for(int i=1; i<chemicals.size(); i++) {
			if(curTemp < chemicals.get(i)[0]) {
				// 현재 사용할 냉장고의 최고 온도보다 높기 때문에
				refrigerator++;
				curTemp = chemicals.get(i)[1]; 
				// 다음 냉장고의 온도를 현재 화학물질의 최고온도로 설정
			}
		}
		System.out.println(refrigerator);
	}
}
