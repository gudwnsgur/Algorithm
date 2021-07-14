import java.util.*;

class SWEA2072 {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for(int i=1; i<=tc ;i++) {
            int oddSum = 0;
            for(int j=0; j<10; j++) {
                int num = sc.nextInt();
                if(num % 2 == 1) oddSum += num;
            }
            System.out.println("#" + i + " " + oddSum);
        }
    }
}

