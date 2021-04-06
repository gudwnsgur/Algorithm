import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> minPQ, maxPQ;
        ArrayList<Integer> arr;

        while (tc-- > 0) {
            int n = Integer.parseInt(br.readLine());
            minPQ = new PriorityQueue<>();
            maxPQ = new PriorityQueue<>(Collections.reverseOrder());
            arr = new ArrayList<>();

            for (int i = 0; i < (n % 10 == 0 ? n / 10 : n / 10 + 1); i++) {
                StringTokenizer tk = new StringTokenizer(br.readLine());
                while(tk.hasMoreElements()) {
                    int x = Integer.parseInt(tk.nextToken());
                    if(maxPQ.isEmpty()) {
                        maxPQ.add(x);
                        arr.add(x);
                    }
                    else if(maxPQ.size() <= minPQ.size()) {
                        if(minPQ.element() >= x) maxPQ.add(x);
                        else {
                            int mid = minPQ.poll();
                            minPQ.add(x);
                            maxPQ.add(mid);
                        }
                        arr.add(maxPQ.element());
                    }
                    else {
                        if(maxPQ.element() <= x) minPQ.add(x);
                        else {
                            int mid = maxPQ.poll();
                            maxPQ.add(x);
                            minPQ.add(mid);
                        }
                    }

                }

            }
            System.out.println(arr.size());
            for(int i=0; i<arr.size(); i++) {
                System.out.print(arr.get(i) + " ");
                if(i%10 == 9) System.out.println();
            }
        }

    }
}
