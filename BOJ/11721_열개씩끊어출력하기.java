import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String str = br.readLine();
        for(int i=1; i<=str.length(); i++) {
            System.out.print(str.charAt(i-1));
            if(i % 10 == 0) System.out.println();
        }
    }
}


