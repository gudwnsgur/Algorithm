import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int targetChannel, brokenChannel;
    static boolean[] brokenNumber = new boolean[10];

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.println(getCountOfClick());
    }

    static void initialize() throws IOException {
        targetChannel = Integer.parseInt(br.readLine());
        brokenChannel = Integer.parseInt(br.readLine());
        if (brokenChannel != 0) {
            tk = new StringTokenizer(br.readLine());
        }
        for (int i = 0; i < brokenChannel; i++) {
            brokenNumber[Integer.parseInt(tk.nextToken())] = true;
        }
    }

    private static int getCountOfClick() {
        if(brokenChannel == 10) return  Math.abs(100 - targetChannel);
        int nearestChannel = getNearestChannel();
        return Math.min(getDigitOfNumber(nearestChannel) + Math.abs(nearestChannel - targetChannel),
                        Math.abs(100 - targetChannel));
    }

    private static int getNearestChannel() {
        int curDiff = 0;
        while (true) {
            boolean possibleUp = possibleClick(targetChannel + curDiff);
            boolean possibleDown = possibleClick(targetChannel - curDiff);

            if (possibleUp && possibleDown) {
                return getDigitOfNumber(targetChannel + curDiff) < getDigitOfNumber(targetChannel + curDiff) ?
                       targetChannel + curDiff :
                       targetChannel - curDiff;
            } else if (possibleUp) {
                return targetChannel + curDiff;
            } else if (possibleDown) {
                return targetChannel - curDiff;
            }
            curDiff++;
        }
    }

    private static boolean possibleClick(int channel) {
        if (channel < 0) {
            return false;
        }
        if(channel == 0 && brokenNumber[channel]) return false;
        while (channel > 0) {
            int number = channel % 10;
            if (brokenNumber[number]) {
                return false;
            }
            channel /= 10;
        }
        return true;
    }

    private static int getDigitOfNumber(int number) {
        return String.valueOf(number).split("").length;
    }
}

