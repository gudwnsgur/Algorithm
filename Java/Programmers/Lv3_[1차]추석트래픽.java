import java.util.*;

class Time {
    int start;
    int end;
    Time(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

class Solution {
    int stringTimeToInt(String s) {
        return Integer.parseInt(s.substring(0,2))*3600*1000 +
                    Integer.parseInt(s.substring(3,5))*60*1000 +
                    Integer.parseInt(s.substring(6,8))*1000 +
                    Integer.parseInt(s.substring(9, 12));
    }
    int findStartTime(String t) {
        String a = "", b ="";
        boolean aa = true;
        for(int i=0; i<t.length(); i++) {
            if(t.charAt(i) == 's') break;
            if(t.charAt(i) == '.') {
                aa = false;
                continue;
            }
            if(aa) a += t.charAt(i);
            else b += t.charAt(i);
        }
        if(b.equals("")) return Integer.parseInt(a) * 1000;
        return Integer.parseInt(a)*1000 + Integer.parseInt(b);
    }

    public int solution(String[] lines) {
        ArrayList<Time> arr = new ArrayList<>();
        for(int i=0; i<lines.length; i++) {
            int end = stringTimeToInt(lines[i].substring(11, 23));
            int length = findStartTime(lines[i].substring(24));
            arr.add(new Time(end-length+1, end));
        }

        Collections.sort(arr, new Comparator<Time>() {
            @Override
            public int compare(Time o1, Time o2) {
                if(o1.start < o2.start) return -1;
                else if(o1.start > o2.start) return 1;
                return 0;
            }
        });
        int answer = 0;
        for(int i=0; i<arr.size(); i++) {
            int s = arr.get(i).end, e = arr.get(i).end + 999;
            int cnt =1;
            for(int j=0; j<arr.size(); j++) {
                if(i == j) continue;
                if (arr.get(j).start <= e && arr.get(j).end >= s) cnt ++;
            }
            answer = Math.max(cnt, answer);
        }
        return answer;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.solution(new String[] {"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"}));
        System.out.println("---------------------------");
        System.out.println(solution.solution(new String[] {"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"}));
    }
}
