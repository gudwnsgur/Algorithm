import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n, m; // 입력받을 N 과 M
	static Map<String, Integer> map = new HashMap<>(); // 문자열에 해당하는 숫자 저장
	static String[] number = {"zero", "one", "two", "three", "four",
							"five", "six", "seven", "eight", "nine"};
	static ArrayList<String> result = new ArrayList<>(); // 결과값을 List에 저장
	
	
	// 숫자를 숫자 하나 단위의 String으로 변환하는 함수
	static String getStringNumber(int num) {
		String str = Integer.toString(num); // 숫자를 문자열로 변환  ex) "123"
		String res = ""; // 결과값을 저장할 변수   ex) "onetwothree"
		
		for(int i=0; i<str.length(); i++) {
			res += number[str.charAt(i) - 48]; // 각 숫자에 해당하는 영어를 res에 합친다.
		}
		return res; // 결과 반환
	}
	
	public static void main(String[] args) throws Exception {
		tk = new StringTokenizer(br.readLine());
		m = Integer.parseInt(tk.nextToken()); // m 입력
		n = Integer.parseInt(tk.nextToken()); // n 입력
		
		for(int i=m; i<=n; i++) {
			String str = getStringNumber(i); // str : 숫자에 해당하는 영문 
			map.put(str, i); // 영문과 일치하는 숫자를 빠르게 찾기 위해 map 사용
			result.add(str); // result list에 영문 저장
		}
		
		Collections.sort(result); // 문자열을 사전순으로 정렬
		
		// 각 영문에 맞는 숫자 출력
		for(int i=0; i<result.size(); i++) {
			System.out.print(map.get(result.get(i)) + " ");
			if((i+1) % 10 == 0) System.out.println();
		}
	}
}

