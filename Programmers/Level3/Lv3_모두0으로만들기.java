import java.util.*;

class Node{
    int name, value;
    Node(int name, int value) {
        this.name = name;
        this.value = value;
    }
}

class Solution {
    ArrayList<ArrayList<Node>> graph = new ArrayList<>();
    boolean[] visited;
    int[] arr;
    public long dfs(int start) {
        


    }

    public long solution(int[] a, int[][] edges) {
        long answer = 0, sum = 0;
        boolean allZero = true;
        visited = new boolean[a.length];
        arr = a;

        for(int value : a) {
            sum += value;
            if(value != 0) allZero = false;
        }
        if(sum != 0) return -1;
        if(allZero) return  0;

        for(int i=0; i<a.length; i++) graph.add(new ArrayList<>());

        for (int[] edge : edges) {
            int s = edge[0], e = edge[1];
            graph.get(s).add(new Node(e, a[e]));
            graph.get(e).add(new Node(s, a[s]));
        }
//        for(int i=0; i<graph.size(); i++) {
//            for(int j=0; j<graph.get(i).size(); j++) {
//                System.out.print("( " + graph.get(i).get(j).name + ", " + graph.get(i).get(j).value + ") ");
//            }
//            System.out.println();
//        }

        visited[0] = true;
        System.out.println(dfs(0));
        return answer;
    }
}

