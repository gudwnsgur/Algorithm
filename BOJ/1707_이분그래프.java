import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static int n, m;	// 정점의 개수(n), 간선의 개수(m)
	static ArrayList<ArrayList<Integer>> graph; // 인접리스트
	static char[] colors; // 각 노드에 색을 지정 (Red, Blue)
	static boolean[] visited; // bfs 탐색시 사용
	
	// 각 testCase에 해당하는 풀이
	static String solve() throws Exception {
		tk = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tk.nextToken()); // 정점의 개수 입력
		m = Integer.parseInt(tk.nextToken()); // 간선의 개수 입력
	
		colors = new char[n+1]; // 각 정점의 색을 구분하기 위한 배열
		visited = new boolean[n+1]; // 정점 방문 여부를 확인하기 위한 배열
		
		graph = new ArrayList<>(); 
		for(int i=0; i<=n; i++) graph.add(new ArrayList<>());
		// 인접리스트의 리스트 초기화
		
		// 간선 입력
		for(int i=0; i<m; i++) {
			tk = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(tk.nextToken()); // 출발 노드
			int e = Integer.parseInt(tk.nextToken()); // 도착 노드
			// 양방향 연결 그래프이므로 두군데 모두 연결
			graph.get(s).add(e); 
			graph.get(e).add(s);
		}

		// 위의 그래프가 이분 그래프라면 YES, 아니면 NO를 return
		return isBipartiteGraph() ? "YES" : "NO";
	}
	
	// bfs 탐색으로 그래프가 이분그래프인지 판단
	static boolean isBipartiteGraph() {
		
		for(int i=1; i<=n; i++) {
			Queue<Integer> q= new LinkedList<>(); // bfs탐색을 위한 queue 선언
			if(!visited[i]) {
				// 정점 i가 아직 방문되지 않았다면
				
				q.add(i); // 첫 노드를 queue에 저장
				colors[i] = 'R'; // colors 배열에 첫 노드의 시작을 red로 저장
				visited[i] = true; // 방문 여부 체크
				
				// bfs 탐색 시작
				while(!q.isEmpty()) {
					int cur = q.poll(); // cur : 현재 선택한 노드
					for(int next : graph.get(cur)) {
						// next : 다음 노드가 방문되지 않은 노드라면
						if(!visited[next]) {
							// 다음 노드의 색을 현재 노드의 색과 다른색으로 저장
							colors[next] = colors[cur] == 'R' ? 'B' : 'R';
							// 방문을 true로 바꿈
							visited[next] = true;
							// q에 다음 node 저장
							q.add(next);
						}
					}
				}
			}
		}

		// 모든 Node에 색을 칠한 후 간선 별로 색을 검사 (최대 200,000)
		for(int i=1; i<=n; i++) {
			for(int j=0; j<graph.get(i).size(); j++) {
				if(colors[i] == colors[graph.get(i).get(j)]) return false;
			}
		}
		// bfs 탐색을 전부 마쳤음에도 인접한 두 노드의 색이 모두 달랐으므로 true 반환
		return true;
	}
	
	public static void main(String[] args) throws Exception {
		int tc = Integer.parseInt(br.readLine()); // testCase 입력
		while(tc-- > 0 ) {
			System.out.println(solve()); // 각 testCase에 해당하는 결과 출력
		}
	}
}

