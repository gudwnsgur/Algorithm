
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static String intToString(int time) {
        String h ="", m ="", s = "";
        if(time % 60 == 0) s += "00";
        else if(time % 60 < 10) s += ("0" + Integer.toString(time%60));
        else s += Integer.toString(time%60);

        time /= 60;

        if(time % 60 == 0) m += "00";
        else if(time % 60 < 10) m += ("0" + Integer.toString(time%60));
        else m += Integer.toString(time%60);

        time /= 60;

        if(time == 0) h += "00";
        else if(time < 10) h += ("0" + Integer.toString(time));
        else h += Integer.toString(time);

        return h + ":" + m + ":" + s;
    }
    static int stringToInt(String s) {
        return Integer.parseInt(s.substring(0, 2)) * 3600 +
                Integer.parseInt(s.substring(3,5)) * 60 +
                Integer.parseInt(s.substring(6,8));
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String e = br.readLine();

        if(s.compareTo(e) < 0 ) System.out.println(intToString((stringToInt(e)) - (stringToInt(s))));
        else System.out.println(intToString( (stringToInt("24:00:00") + stringToInt(e) - stringToInt(s)) ));
    }
}

