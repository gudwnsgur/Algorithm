import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n;
    static String result = "";
    static int[] alphabet = new int[26];
    public static void main(String[] args) throws IOException   {
        n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++) alphabet[br.readLine().charAt(0) - 97]++;
        for(int i=0; i<26; i++) if(alphabet[i] >= 5) result += (char)(i+97);

        System.out.println( (result.length() == 0 ? "PREDAJA" : result));
;    }
}

