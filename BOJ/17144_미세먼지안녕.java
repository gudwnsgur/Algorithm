import java.io.*;
import java.util.*;
class Loc {
	int x, y;
	Loc(int x, int y ) {
		this.x = x;
		this.y = y;
	}
}
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int R, C, T;
	static int[][] map;
	
	public static void main(String[] args) throws IOException {
		  tk = new StringTokenizer(br.readLine());
	      R = Integer.parseInt(tk.nextToken());
	      C = Integer.parseInt(tk.nextToken());
	      T = Integer.parseInt(tk.nextToken());
	      
	      int[][] house = new int[R][C];
	      List<Integer> air = new ArrayList<>();
	      
	      for(int i=0;i<R;i++) {
	         tk = new StringTokenizer(br.readLine()," ");
	         for(int j=0;j<C;j++) {
	            house[i][j] = Integer.parseInt(tk.nextToken());
	            if(house[i][j]==-1)air.add(i);
	         }
	      }
	      
	      int[] di = {0,0,1,-1};
	      int[] dj = {1,-1,0,0};
	      for(int t=0;t<T;t++) {
	         Queue<Loc> q = new LinkedList<Loc>();
	         for(int i=0;i<R;i++) {
	            for(int j=0;j<C;j++) {
	               if(house[i][j]>0) {
	                  q.add(new Loc(i,j));
	               }
	            }
	         }

	         //미세먼지 확산
	         int[][] addDust = new int[R][C];
	         while(!q.isEmpty()) {
	            Loc cur = q.poll();
	            int dust = house[cur.x][cur.y]/5;
	            int spreadCount = 0;
	            
	            for(int d=0 ; d<4 ; d++) {
	            	int nx = cur.x + di[d];
	            	int ny = cur.y + dj[d];
	            	if(nx < 0 || nx >= R || ny < 0 || ny >= C || house[nx][ny] == -1) continue;
	                     addDust[nx][ny] += dust;
	                     spreadCount++;
	               }
	            addDust[cur.x][cur.y] -= dust*spreadCount;
	         }
	         for(int i=0 ; i < R ; i++) {
	            for(int j=0 ; j < C ; j++) {
	               house[i][j] += addDust[i][j];
	            }
	         }
	         
	         
	         //공기청정기 
	         int airI;
	         int airJ;
	         //반시계
	         airI = air.get(0);
	         airJ = 0;
	         
	         for(;airI>=0;airI--) {
	            if(house[airI][airJ]==-1)continue;
	            if(house[airI+1][airJ]==-1)house[airI][airJ]=0;
	            else {
	               house[airI+1][airJ]=house[airI][airJ];
	            }
	         }
	         airI +=1;
	         
	         for(;airJ<C;airJ++) {
	            if(house[airI][airJ]==-1 || airJ==0)continue;
	            if(house[airI][airJ-1]==-1)house[airI][airJ]=0;
	            else {
	               house[airI][airJ-1]=house[airI][airJ];
	            }
	         }
	         
	         airI+=1;
	         airJ-=1;
	         for(;airI<=air.get(0);airI++) {
	            house[airI-1][airJ]=house[airI][airJ];
	         }
	         airI-=1;
	         airJ-=1;
	         for(;airJ>=1;airJ--) {
	            house[airI][airJ+1]=house[airI][airJ];
	            if(airJ==1)house[airI][airJ]=0;
	         }
	         //시계
	         airI = air.get(1);
	         airJ = 0;
	         for(;airI<R;airI++) {
	            if(house[airI][airJ]==-1)continue;
	            if(house[airI-1][airJ]==-1)house[airI][airJ]=0;
	            else {
	               house[airI-1][airJ]=house[airI][airJ];
	            }
	         }
	         
	         airI-=1;
	         for(;airJ<C;airJ++) {
	            if(house[airI][airJ]==-1 || airJ==0)continue;
	            if(house[airI][airJ-1]==-1)house[airI][airJ]=0;
	            else {
	               house[airI][airJ-1]=house[airI][airJ];
	            }
	         }
	         
	         airI-=1;
	         airJ-=1;
	         for(;airI>=air.get(1);airI--) {
	            house[airI+1][airJ]=house[airI][airJ];
	         }
	         
	         airI+=1;
	         airJ-=1;
	         for(;airJ>=1;airJ--) {
	            house[airI][airJ+1]=house[airI][airJ];
	            if(airJ==1)house[airI][airJ]=0;
	         }
	      }
	      
	      //남아있는 미세먼지의 양
	      int answer = 0;
	      for(int i=0;i<R;i++) {
	         for(int j=0;j<C;j++) {
	            answer += house[i][j];
	         }
	      }
	      answer+=2;
	      System.out.println(answer);
	   }

}

