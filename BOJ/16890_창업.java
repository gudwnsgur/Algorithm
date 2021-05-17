import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static char[] koosaga, cubelover, res;
    static int n;

    public static void main(String[] args) throws IOException {
        String s1 = br.readLine(), s2 = br.readLine();
        n = s1.length();
        koosaga = new char[n];
        cubelover = new char[n];
        res = new char[n];
        for (int i = 0; i < n; i++) koosaga[i] = s1.charAt(i);
        for (int i = 0; i < n; i++) cubelover[i] = s2.charAt(i);
        Arrays.sort(koosaga);
        Arrays.sort(cubelover);

        int kooIdx = 0, cubeIdx = n - 1, left = 0, right = n - 1;
        int kooRight = (n+1)/2 - 1, cubeLeft = (n+1)/2;
        for (int i = 0; i < n; i++) {
            // koosaga
            if (i % 2 == 0) {
                if (koosaga[kooIdx] < cubelover[cubeIdx]) res[left++] = koosaga[kooIdx++];
                else res[right--] = koosaga[kooRight--];
            }
            // cubeLover
            else {
                if (cubelover[cubeIdx] > koosaga[kooIdx]) res[left++] = cubelover[cubeIdx--];
                else res[right--] = cubelover[cubeLeft++];
            }
        }
        for (int i = 0; i < res.length; i++) System.out.print(res[i]);
        System.out.println();
    }
}
