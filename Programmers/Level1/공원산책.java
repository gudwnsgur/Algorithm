class Loc {
    int x;
    int y;

    Loc(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    static Loc me;
    static char[][] map;

    public int[] solution(String[] park, String[] routes) {
        makeMap(park);
        for (String route : routes) {
            move(route.charAt(0), route.charAt(2) - 48);
        }
        return new int[]{me.x, me.y};
    }

    private void makeMap(String[] park) {
        map = new char[park.length][park[0].length()];
        for (int i = 0; i < park.length; i++) {
            for (int j = 0; j < park[i].length(); j++) {
                map[i][j] = park[i].charAt(j);
                if (map[i][j] == 'S') me = new Loc(i, j);
            }
        }
    }

    private void move(char dir, int dist) {
        try {
            if (dir == 'N') {
                for (int i = me.x - 1; i >= me.x - dist; i--) {
                    if (map[i][me.y] == 'X') return;
                }
                me.x -= dist;
            } else if (dir == 'S') {
                for (int i = me.x + 1; i <= me.x + dist; i++) {
                    if (map[i][me.y] == 'X') return;
                }
                me.x += dist;
            } else if (dir == 'W') {
                for (int i = me.y - 1; i >= me.y - dist; i--) {
                    if (map[me.x][i] == 'X') return;
                }
                me.y -= dist;
            } else {
                for (int i = me.y + 1; i <= me.y + dist; i++) {
                    if (map[me.x][i] == 'X') return;
                }
                me.y += dist;
            }
        } catch (Exception ignored) {
        }
    }
}
