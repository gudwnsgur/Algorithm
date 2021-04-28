import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int r1, r2, c1, c2;
    static String[][] map;
    static int cnt = 0, maxLength = 0;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};
    static boolean isFinished = false;

    static void putNum(int x, int y, int value) {
        if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
            cnt++;
            map[x - r1][y - c1] = Integer.toString(value);
            maxLength = Math.max(maxLength, map[x-r1][y-c1].length());
        }
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        r1 = Integer.parseInt(tk.nextToken());
        c1 = Integer.parseInt(tk.nextToken());
        r2 = Integer.parseInt(tk.nextToken());
        c2 = Integer.parseInt(tk.nextToken());
        map = new String[r2 - r1 + 1][c2 - c1 + 1];

        putNum(0, 0, 1);

        int x = 0, y = 0, len = 2, num = 2;
        while (true) {
            for (int i = 0; i < 4; i++) {
                if (i == 0) y++;
                else {
                    x += dx[i];
                    y += dy[i];
                }

                for (int j = 0; j < len; j++) {
                    putNum(x, y, num);
                    if (cnt == (r2 - r1 + 1) * (c2 - c1 + 1)) {
                        isFinished = true;
                        break;
                    }
                    num++;

                    if (j != len - 1) {
                        x += dx[i];
                        y += dy[i];
                    }
                }
                if (isFinished) break;
            }
            if (isFinished) break;
            len += 2;
        }

        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                for (int k = 0; k < maxLength - map[i][j].length(); k++) System.out.print(" ");
                for (int k = 0; k < map[i][j].length(); k++) System.out.print(map[i][j].charAt(k));
                System.out.print(" ");
            }
            System.out.println();
        }

    }
}

