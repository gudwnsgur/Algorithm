import java.util.*;
import java.io.*;

class Circle {
    int name;
    int value;
    Circle(int name, int value) {
        this.name = name;
        this.value = value;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static ArrayList<Circle> circles = new ArrayList<>();
    static boolean isValid() {
        Stack<Integer> s = new Stack<>();
        for(int i=0; i<circles.size(); i++) {
            if(s.isEmpty()) s.add(circles.get(i).name);
            else if(s.peek() == circles.get(i).name) {
            s.pop();
            }
            else s.push(circles.get(i).name);
        }
        return s.isEmpty();
    }
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++){
            tk = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(tk.nextToken());
            int r = Integer.parseInt(tk.nextToken());

            circles.add(new Circle(i, x-r));
            circles.add(new Circle(i, x+r));

        }
        Collections.sort(circles, new Comparator<Circle>() {
            @Override
            public int compare(Circle o1, Circle o2) {
                return Integer.compare(o1.value, o2.value);
            }
        });
        System.out.println(isValid() ? "YES" : "NO");


    }
}


