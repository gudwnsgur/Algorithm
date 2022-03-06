import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static ArrayList<String> results = new ArrayList<>();
    static boolean[] visited;
    static String str;
    static int[] arr;
    static int[] bracket;

    static void dfs(int length, int m, int n) {
        if(length == m) {
            String tmp = "";
            for(int i=0; i< bracket.length; i++) {
                boolean use = true;
                for(int j=0; j<arr.length; j++) {
                    if(bracket[i] == arr[j]) {
                        use = false;
                        break;
                    }
                }
                if(use) tmp += str.charAt(i);
            }
            results.add(tmp);
            return;
        }

        for(int i=1; i<=n; i++) {
            if(!visited[i]) {
                if(length == 0 || arr[length - 1] < i) {
                    visited[i] = true;
                    arr[length] = i;
                    dfs(length+1, m, n);
                    visited[i] = false;
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        str = br.readLine();
        bracket = new int[str.length()];
        Stack<Integer> s = new Stack<>();

        int number = 1;
        for(int i=0; i<str.length(); i++) {
            if(str.charAt(i) == '(') {
                s.add(number);
                bracket[i] = number;
                number++;
            }
            else if(str.charAt(i) == ')') {
                bracket[i] = s.peek();
                s.pop();
            }
        }
        number--;
        for(int i=1; i<= number; i++) {
            visited = new boolean[number+1];
            arr = new int[i];
            dfs(0, i, number);
        }


        Collections.sort(results);
        System.out.println(results.get(0));
        for(int i=1; i<results.size(); i++) {
            if(!results.get(i).equals(results.get(i-1))) System.out.println(results.get(i));
        }
    }
}

