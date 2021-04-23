import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static String src, dest;
    static int[] pi;
    static ArrayList<Integer> loc = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        src = br.readLine();
        dest = br.readLine();

        pi = new int[dest.length()];
        for (int i = 1, j = 0; i < pi.length; i++) {
            while (j > 0 && dest.charAt(i) != dest.charAt(j)) j = pi[j - 1];
            if (dest.charAt(i) == dest.charAt(j)) pi[i] = ++j;
        }

        for(int i=0, j=0; i<src.length(); i++) {
            while(j > 0 && src.charAt(i) != dest.charAt(j)) j = pi[j-1];
            if(src.charAt(i) == dest.charAt(j)) {
                if(j == dest.length()-1) {
                    loc.add(i - dest.length() + 2);
                    j = pi[j];
                }
                else j++;
            }
        }

        System.out.println(loc.size());
        for(int i=0; i<loc.size(); i++) System.out.print(loc.get(i) + " ");
        System.out.println();
    }
}
