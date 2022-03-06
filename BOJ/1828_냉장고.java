import java.io.*;
import java.util.*;

class Temp {
	int min, max;
	Temp(int min, int max) {
		this.min = min;
		this.max = max;
	}
}

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n;	// 화학 물질의 개수
	static ArrayList<Temp> chemicals = new ArrayList<>(); // 화학 물질
	
	public static void main(String[] args) throws IOException {
		n = Integer.parseInt(br.readLine());
		
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			chemicals.add(new Temp(Integer.parseInt(tk.nextToken()),
					Integer.parseInt(tk.nextToken())));
		}

		
		// 화학물질을 최고온도 오름차순으로 정렬
		Collections.sort(chemicals, (Temp o1, Temp o2) -> {
			if(o1.max < o2.max) return -1;
			else if(o1.max > o2.max) return 1;
			return 0;
		});	
		
		int curTemp = chemicals.get(0).max; // 현재 사용할 냉장고의 최고 온도
		int refrigerator = 1;	// 냉장고 수
		for(int i=1; i<chemicals.size(); i++) {
			if(curTemp < chemicals.get(i).min) {
				// 현재 사용할 냉장고의 최고 온도보다 높기 때문에
				refrigerator++;
				curTemp = chemicals.get(i).max; 
				// 다음 냉장고의 온도를 현재 화학물질의 최고온도로 설정
			}
		}
		System.out.println(refrigerator);
	}
}
