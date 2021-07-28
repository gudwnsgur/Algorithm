import java.util.*;
import java.io.*;

public class SWEA2056 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static final int[] days = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
	public static void main(String[] args) throws IOException {
        
		int tc = Integer.parseInt(br.readLine());
		
		for(int i=1 ; i<=tc ; i++) {
			String date = br.readLine();
			String y = date.substring(0, 4), 
					month = date.substring(4,6),
					day = date.substring(6,8);
			
			if(Integer.parseInt(month) < 1 || Integer.parseInt(month) > 12) {
				System.out.println("#" + i + " " +-1);
				continue;
			}
			
			if(days[Integer.parseInt(month)] < Integer.parseInt(day)) {
				System.out.println("#" + i + " " +-1);
				continue;
			}
			
			System.out.println("#" + i + " " + y + "/" + month + "/" + day);
		}
	}
}

