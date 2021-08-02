import java.io.*;

public class Main {
	static final String a = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
	static final String b = "\"재귀함수가 뭔가요?\"";
	static final String c = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
	static final String c2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
	static final String c3 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
	static final String d = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
	static final String e = "라고 답변하였지.";	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	static void recursion(int cur, int n, int cnt) {
		if(cur == n) {
			for(int i=0; i<cnt; i++) System.out.print("_");
			System.out.println(b);
			for(int i=0; i<cnt; i++) System.out.print("_");
			System.out.println(d);
			for(int i=0; i<cnt; i++) System.out.print("_");
			System.out.println(e);
			return;
		}
		
		for(int i=0; i<cnt; i++) System.out.print("_");
		System.out.println(b);
		for(int i=0; i<cnt; i++) System.out.print("_");
		System.out.println(c);
		for(int i=0; i<cnt; i++) System.out.print("_");
		System.out.println(c2);
		for(int i=0; i<cnt; i++) System.out.print("_");
		System.out.println(c3);

		recursion(cur+1, n, cnt+4);
		for(int i=0; i<cnt; i++) System.out.print("_");
		System.out.println(e);
}
	
	public static void main(String[] args) throws IOException{
		int n = Integer.parseInt(br.readLine());
		System.out.println(a);
		recursion(0, n, 0);
	}

}

