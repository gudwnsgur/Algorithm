import java.io.*;
import java.util.*;

class Meeting {
	int startTime, endTime;
	Meeting(int startTime, int endTime) {
		this.startTime = startTime;
		this.endTime = endTime;
	}
}
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	public static void main(String[] args) throws IOException{
		int n = Integer.parseInt(br.readLine());
		ArrayList<Meeting> meetings = new ArrayList<>();
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			meetings.add(new Meeting(Integer.parseInt(tk.nextToken()), 
					Integer.parseInt(tk.nextToken())));
		}
		
		Collections.sort(meetings, new Comparator<Meeting>() {
			@Override
			public int compare(Meeting o1, Meeting o2) {
				if(o1.endTime < o2.endTime) return -1;
				else if(o1.endTime > o2.endTime) return 1;
				
				if(o1.startTime < o2.startTime) return -1;
				else if(o1.startTime > o2.startTime) return 1;
				return 0;
			}
		});
		
		int time = 0, cnt = 0;
		for(int i=0; i<meetings.size(); i++) {
			Meeting cur = meetings.get(i);
			if(time <= cur.startTime) {
				cnt++;
				time = cur.endTime;
			}
		}
		System.out.println(cnt);
	}

}
