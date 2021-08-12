import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    
	public static void main(String[] args) throws IOException {
		int[] dwarf = new int[9];
		for(int i=0; i<9; i++) dwarf[i] = Integer.parseInt(br.readLine());
		
		for(int i=0; i<8; i++) {
			for(int j=i+1; j<9; j++) {
				int sum = 0;
				for(int k=0; k<9; k++) if(k != i && k != j) sum += dwarf[k];
				if(sum != 100) continue;
				for(int k=0; k<9; k++) {
					if(k != i && k != j) System.out.println(dwarf[k]);
				}
				return;
			}
		}
				
	}

}

