import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Lecture{
    int pay, day;
    Lecture(int pay, int day) {
        this.pay = pay;
        this.day = day;
    }
}
class Main {
    static int[] money;
    static int maxDay = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        ArrayList<Lecture> arr = new ArrayList<>();
        for(int i=0; i<n; i++) {
            StringTokenizer tk = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(tk.nextToken());
            int y = Integer.parseInt(tk.nextToken());
            arr.add(new Lecture(x, y));
            maxDay = Math.max(maxDay, y);
        }
        money = new int[maxDay+1];
        Collections.sort(arr, new Comparator<Lecture>() {
            @Override
            public int compare(Lecture o1, Lecture o2) {
                if(o1.pay > o2.pay) return -1;
                else if(o1.pay < o2.pay) return 1;
                return 0;
            }
        });
        for (Lecture lecture : arr) {
            for (int j = lecture.day; j >= 1; j--) {
                if (money[j] == 0) {
                    money[j] = lecture.pay;
                    break;
                }
            }
        }
        int result = 0;
        for(int i =0; i<money.length; i++) result += money[i];
        System.out.println(result);
    }
}
