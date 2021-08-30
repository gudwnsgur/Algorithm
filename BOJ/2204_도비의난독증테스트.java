import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        while(n != 0 ) {
            String[] str = new String[n];
            Map<String, String> map = new HashMap<>();
            for(int i=0; i<n; i++) {
                str[i] = br.readLine();
                map.put(str[i].toUpperCase(), str[i]);
                str[i] = str[i].toUpperCase();
            }
            Arrays.sort(str);
            System.out.println(map.get(str[0]));
            n = Integer.parseInt(br.readLine());
        }
    }
}


