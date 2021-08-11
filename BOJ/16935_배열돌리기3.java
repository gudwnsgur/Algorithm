import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    static int n, m, r;
    static int[][] arr;
    
    static void copyTmpToArr (int[][] tmp) {
    	arr = new int[tmp.length][tmp[0].length];
    	for(int i=0; i<tmp.length; i++) {
    		for(int j=0; j<tmp[i].length; j++) {
    			arr[i][j] = tmp[i][j];
    		}
    	}
    }
    static void one() {
    	int[][] tmp = new int[arr.length][arr[0].length];
    	for(int i=0; i<arr.length; i++) {
    		for(int j=0; j<arr[i].length; j++) { 
    			tmp[arr.length-i-1][j] = arr[i][j];
    		}
    	}
    	copyTmpToArr(tmp);
    }
    static void two() {
    	int[][] tmp = new int[arr.length][arr[0].length];
    	for(int i=0; i<arr.length; i++) {
    		for(int j=0; j<arr[i].length; j++) { 
    			tmp[i][arr[0].length-j-1] = arr[i][j];
    		}
    	}
    	copyTmpToArr(tmp);
    }
    static void three() {
    	int[][] tmp = new int[arr[0].length][arr.length];
    	for(int i=0; i<arr.length; i++) {
    		for(int j=0; j<arr[i].length; j++) {
    			tmp[j][arr.length-i-1] = arr[i][j];
    		}
    	}
    	copyTmpToArr(tmp);
    }
    static void four() {
    	int[][] tmp = new int[arr[0].length][arr.length];
       	for(int i=0; i<arr.length; i++) {
    		for(int j=0; j<arr[i].length; j++) {
    			tmp[arr[i].length-j-1][i] = arr[i][j];
    		}
    	}
       	copyTmpToArr(tmp);
    	
    }
    static void five() {
    	int [][] tmp = new int[arr.length][arr[0].length];
    	n = arr.length;
    	m = arr[0].length;
    	
    	for(int i=0; i<n/2; i++) {
    		for(int j=0; j < m/2; j++) {
    			tmp[i][j] = arr[i + n/2][j];
    		}
    	}
    	for(int i=n/2; i<n; i++) {
    		for(int j=0; j<m/2; j++) {
    			tmp[i][j] = arr[i][j + m/2];
    		}
    	}
    	for(int i=n/2; i<n; i++) {
    		for(int j=m/2; j<m; j++) {
    			tmp[i][j] = arr[i - n/2][j];
    		}
    	}
    	for(int i=0; i<n/2; i++) {
    		for(int j=m/2; j<m; j++) {
    			tmp[i][j] = arr[i][j - m/2];
    		}
    	}
    	copyTmpToArr(tmp);
    }
    static void six() {
    	int [][] tmp = new int[arr.length][arr[0].length];
    	n = arr.length;
    	m = arr[0].length;
    	
    	for(int i=0; i<n/2; i++) {
    		for(int j=0; j < m/2; j++) {
    			tmp[i][j] = arr[i][j + m/2];
    		}
    	}
    	for(int i=n/2; i<n; i++) {
    		for(int j=0; j<m/2; j++) {
    			tmp[i][j] = arr[i - n/2][j];
    		}
    	}
    	for(int i=n/2; i<n; i++) {
    		for(int j=m/2; j<m; j++) {
    			tmp[i][j] = arr[i][j - m/2];
    		}
    	}
    	for(int i=0; i<n/2; i++) {
    		for(int j=m/2; j<m; j++) {
    			tmp[i][j] = arr[i + n/2][j];
    		}
    	}
    	copyTmpToArr(tmp);
    }
	public static void main(String[] args) throws IOException{
		tk = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tk.nextToken());
		m = Integer.parseInt(tk.nextToken());
		r = Integer.parseInt(tk.nextToken());
		
		arr = new int[n][m];
		for(int i=0; i<n; i++) {
			tk = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) arr[i][j] = Integer.parseInt(tk.nextToken());
		}
		
		tk = new StringTokenizer(br.readLine());
		while(tk.hasMoreTokens()) {
			int op = Integer.parseInt(tk.nextToken());
			if(op == 1) one();
			else if(op == 2) two();
			else if(op == 3) three();
			else if(op == 4) four();
			else if(op == 5) five();
			else six();
		}
		
		for(int i=0; i<arr.length; i++) {
			for(int j=0; j<arr[i].length; j++) {
				sb.append(arr[i][j]).append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
}

