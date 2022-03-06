import java.util.*;

class Solution {
    boolean[] visited;
    boolean finished = false;
    String[] arr;
    String[][] ticket;

    void dfs(int length, int n) {
        if(finished) return;
        if(length == n ){
            finished = true;
            return;
        }

        for(int i=0; i<n-1; i++) {
            if(!visited[i] && ticket[i][0].equals(arr[length-1]) && !finished) {
                visited[i] = true;
                arr[length] = ticket[i][1];
                dfs(length+1, n);
                visited[i] = false;
            }
        }
    }

    public String[] solution(String[][] tickets) {
        ticket = tickets;
        Arrays.sort(tickets, new Comparator<String[]>() {
            @Override
            public int compare(String[] o1, String[] o2) {
                if(o1[1].compareTo(o2[1]) == 0) return o1[0].compareTo(o2[0]);
                return o1[1].compareTo(o2[1]);
            }
        });

        visited = new boolean[tickets.length];
        arr = new String[tickets.length+1];
        arr[0] = "ICN";

        dfs(1, tickets.length+1);
        return arr;
    }
}
