import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine().trim());
        ArrayList<Long> customersX = new ArrayList<>();
        ArrayList<Long> customersY = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine().trim());
            customersX.add(Long.parseLong(tk.nextToken()));
            customersY.add((Long.parseLong(tk.nextToken())));
        }
        Collections.sort(customersX);
        Collections.sort(customersY);

        long sumOfDist = 0;
        for (int i = 0; i < n; i++) {
            sumOfDist += Math.abs(customersX.get(n / 2) - customersX.get(i)) +
                    Math.abs(customersY.get(n / 2) - customersY.get(i));
        }
        System.out.println(sumOfDist);
    }
}

