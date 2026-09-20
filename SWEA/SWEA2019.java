import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();

        int a =1;
        for(int i=0; i <= 8; i++) {
            System.out.print(a + " ");
            a *= 2;
        }
    }
}