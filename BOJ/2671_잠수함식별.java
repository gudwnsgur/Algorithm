import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    static boolean isMarin(String sound){
        int n = sound.length();
        int i = 0;
        while(i < n) {
            if(sound.charAt(i) == '0') {
                if(i >= n-1 || sound.charAt(i+1) != '1') return false;
                i+=2;
            }
            else {
                if(i >= n-3) return false;
                if(sound.charAt(i+1) != '0' || sound.charAt(i+2) != '0') return false;

                i ++;
                while(i < sound.length() && sound.charAt(i) == '0') i++;
                if(i >= n) return false;
                i++;
                while (i < n && sound.charAt(i) == '1') {
                    if(i+2 < n && sound.charAt(i+1)=='0' && sound.charAt(i+2) =='0') break;
                    i++;
                }

            }
        }
        return true;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String sound = br.readLine();

        System.out.println(isMarin(sound) ? "SUBMARINE" : "NOISE");
    }
}

