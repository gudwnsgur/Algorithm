import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        // 피사노 주기
        // 피보나치 수를 나눌 수 k = 10^n이면 피사노 주기는 15* 10^(n-1) 이다.
        long n = Long.parseLong(br.readLine());
        int pisano = 1500000; // 피사노 주기
        n %= pisano;

        long[] finbonacci = new long[pisano];
        finbonacci[0] = 0;
        finbonacci[1] = 1;

        for(int i=2; i<pisano && i<=n; i++) finbonacci[i] = (finbonacci[i-2] + finbonacci[i-1])%1000000;
        System.out.println(finbonacci[(int)n]);
    }
}
