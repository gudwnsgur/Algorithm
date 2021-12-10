import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String n;
    static String[] rule = {"000", "001", "010", "011", "100", "101", "110", "111"};
    static String[] firstRule = {"0", "1", "10", "11", "100", "101", "110", "111"};

    public static void main(String[] args) throws IOException {
        n = br.readLine();
        if(n.equals("0")) {
            System.out.println("0");
            return;
        }
        StringBuilder str = new StringBuilder();
        for(int i=0; i<n.length(); i++) {
            if(i == 0) str.append(firstRule[n.charAt(i)-48]);
            else str.append(rule[n.charAt(i)-48]);
        }
        System.out.println(str.toString());
    }
}
