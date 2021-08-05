import java.io.*;
import java.util.*;

public class SWEA1218 {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	static StringBuilder sb = new StringBuilder();
	
	static boolean isVaild(String str) {
		Stack<Character> stack = new Stack<>();
		for(int i=0; i<str.length(); i++) {
			char ch = str.charAt(i);
			
			if(ch == '{' || ch == '[' || ch == '(' || ch == '<') {
				stack.push(ch);
				continue;
			}
			if(stack.isEmpty()) return false;
			
			char top = stack.peek();
			if((ch == '}' && top != '{') || (ch == ']' && top != '[') || 
					(ch == ')' && top != '(') || (ch == '>' && top != '<')) return false;
			else stack.pop();
		}
		return true;
	}
	
	public static void main(String[] args) throws IOException{
		for(int i=1; i<=10; i++) {
			br.readLine();
			sb.append("#").append(i).append(" ").append(isVaild(br.readLine()) ? "1" : "0").append("\n");
		}
		System.out.println(sb.toString());
	}
}

