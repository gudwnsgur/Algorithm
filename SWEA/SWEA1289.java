import java.io.*;

public class SWEA1289 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws IOException{
		int tc = Integer.parseInt(br.readLine());
		
		for(int i=1; i<=tc; i++) {
			int idx = 0;
			String str = br.readLine();
			while( idx < str.length() && str.charAt(idx) == '0') idx++;
			
			if(idx == str.length()) {
				System.out.println("#" + i + " 0");
				continue;
			}
			
			int cnt = 1;
			char cur = '1';
			for(; idx < str.length(); idx++) {
				if(str.charAt(idx) != cur) {
					cur = (cur == '1' ? '0' : '1');
					cnt++;
				}
			}
			System.out.println("#" + i + " " + cnt);
		}
	}
}

