import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static final String[] suffix = {" is acceptable.", " is not acceptable."};
    static final char[] vowel = {'a', 'e', 'i', 'o', 'u'};

    static boolean isVowel(char ch) {
        for (char c : vowel) if (ch == c) return true;
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String pw = br.readLine();

        while(!pw.equals("end")) {

            boolean containVowel = false;
            boolean pos = true;
            for (int i = 0; i < pw.length(); i++) {
                if (isVowel(pw.charAt(i))) containVowel = true;

                if (i >= 1) {
                    if (pw.charAt(i - 1) == pw.charAt(i) && pw.charAt(i) != 'e' && pw.charAt(i) != 'o') {
                        pos = false;
                        break;
                    }
                }

                if (i >= 2) {
                    if ((isVowel(pw.charAt(i - 2)) && isVowel(pw.charAt(i - 1)) && isVowel(pw.charAt(i))) ||
                            (!isVowel(pw.charAt(i - 2)) && !isVowel(pw.charAt(i - 1)) && !isVowel(pw.charAt(i)))) {
                        pos = false;
                        break;
                    }
                }
            }

            System.out.println(pos & containVowel ? "<" + pw + ">" + suffix[0] : "<" + pw + ">" + suffix[1]);
            pw = br.readLine();
        }
    }
}

