import java.io.*;
import java.math.BigInteger;
import java.util.*;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer tk;
	public static void main(String args[]) throws Exception {
		tk = new StringTokenizer(br.readLine());
		BigInteger a = new BigInteger(tk.nextToken());
		BigInteger b = new BigInteger(tk.nextToken());
		System.out.println(a.add(b));
  }
}
