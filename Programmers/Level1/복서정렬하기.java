
import java.util.*;

class Node {
    int name, heavyCnt, weight, winCnt;
    double rate;
    Node(int name, int winCnt, int heavyCnt, int weight, double rate) {
        this.name = name;
        this.winCnt = winCnt;
        this.heavyCnt = heavyCnt;
        this.weight = weight;
        this.rate = rate;
    }
}

class Solution {
    int n;
    public int[] solution(int[] weights, String[] head2head) {
        ArrayList<Node> arr = new ArrayList<>();
        n = weights.length;

        for(int i=0; i<n; i++) {
            int heavyCnt = 0, winCnt = 0, game = 0;
            double rate = 0;

            for(int j=0; j<n; j++) {
                if(head2head[i].charAt(j) != 'N') game++;
                if(head2head[i].charAt(j) == 'W') {
                    winCnt++;
                    if(weights[i] < weights[j]) heavyCnt++;
                }
                if(game != 0 ) {
                    rate = ((double)winCnt*100)/game;
                }

            }
            arr.add(new Node(i+1, (game == 0 ? 0 : (winCnt * 10000000)/game), heavyCnt, weights[i], rate));
        }
        for(int i=0; i<n; i++) {
            Node c = arr.get(i);
            System.out.println(c.name + " "  +  c.winCnt  + " " + c.heavyCnt + " " + c.weight);
        }

        Collections.sort(arr, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if((o1.rate == o2.rate)) {
                    if(o1.heavyCnt == o2.heavyCnt) {
                        if(o1.weight == o2.weight ) return Integer.compare(o1.name, o2.name);
                        return Integer.compare(o2.weight, o1.weight);
                    }
                    return Integer.compare(o2.heavyCnt, o1.heavyCnt);
                }
                return Double.compare(o2.rate, o1.rate);
            }
        });

        int[] answer = new int[n];
        for(int i=0; i<n; i++) answer[i] = arr.get(i).name;
        return answer;
    }
}
class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
    }
}
