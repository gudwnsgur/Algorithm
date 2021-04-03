import java.io.*;
import java.util.*;

class Music {
    int idx;
    int cnt;
    Music (int idx, int cnt ) {
        this.idx = idx;
        this.cnt = cnt;
    }

}

class Solution {
    public int[] solution(String[] genres, int[] plays) {
       ArrayList<Integer> answer = new ArrayList<>();

        ArrayList<String> genre = new ArrayList<>();
        HashMap<String, Integer> total = new HashMap<>();
        HashMap<String, ArrayList<Music>> map = new HashMap<>();

        for(int i=0; i<genres.length; i++) {
            if(map.containsKey(genres[i])) {
                map.get(genres[i]).add(new Music(i, plays[i]));
                total.put(genres[i], total.get(genres[i]) + plays[i]);
            }
            else {
                genre.add(genres[i]);
                ArrayList<Music> tmp = new ArrayList<>();
                tmp.add(new Music(i, plays[i]));

                map.put(genres[i], tmp);
                total.put(genres[i], plays[i]);
            }
        }

        Collections.sort(genre, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if(total.get(o1) > total.get(o2)) return -1;
                else if(total.get(o1) < total.get(o2)) return 1;
                return 0;
            }
        });

        for(String key : map.keySet()) {
            Collections.sort(map.get(key), new Comparator<Music>() {
                @Override
                public int compare(Music o1, Music o2) {
                    if(o1.cnt > o2.cnt) return -1;
                    else if(o1.cnt < o2.cnt) return 1;
                    return 0;
                }
            });
        }

        for(String g : genre) {
            ArrayList<Music> tmp = map.get(g);
            for(int i=0; i<tmp.size() && i < 2 ; i++) {
                answer.add(tmp.get(i).idx);
            }
        }
        
        int[] ans = new int[answer.size()];
        for(int i=0; i<answer.size(); i++) ans[i] = answer.get(i);
        return ans;
    }
}
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    }
}

