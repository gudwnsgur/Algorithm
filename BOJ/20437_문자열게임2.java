import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0) {
            String str = br.readLine();
            int n = Integer.parseInt(br.readLine());
            if(n==1) {
                System.out.println("1 1");
                continue;
            }

            int minNum = 10001, maxNum = -1;

            ArrayList<ArrayList<Integer>> idx = new ArrayList<>();
            for(int i=0; i<26; i++) idx.add(new ArrayList<>());

            for(int i=0; i<str.length(); i++) idx.get(str.charAt(i) - 'a').add(i);

            boolean pos = false;
            for(int i=0; i<26; i++) {
                if(idx.get(i).size() < n) continue;
                pos = true;
                for(int j =0; j<=idx.get(i).size()-n; j++) {
                    maxNum = Math.max(maxNum, idx.get(i).get(j+n-1) - idx.get(i).get(j) + 1);
                    minNum = Math.min(minNum, idx.get(i).get(j+n-1) - idx.get(i).get(j) + 1);
                }
            }
            if(pos) System.out.println(minNum + " " + maxNum);
            else System.out.println(-1);
        }
    }
}

