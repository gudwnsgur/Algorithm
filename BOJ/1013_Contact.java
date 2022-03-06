import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final String pattern = "(100+1+|01)+";

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0) {
            System.out.println(br.readLine().matches(pattern) ? "YES" : "NO");
        }
    }
}

