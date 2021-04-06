import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<String> trees = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<>();
        int total = 0;

        String tree = br.readLine();
        while(tree != null) {
            total++;
            if(!map.containsKey(tree)) {
                trees.add(tree);
                map.put(tree, 1);
            }
            else map.put(tree, map.get(tree) + 1);
            tree = br.readLine();
        }

        Collections.sort(trees);
        for (String s : trees) {
            double x = (double) ((double)map.get(s) / total) * 100;
            System.out.println(s + " " + String.format("%.4f", x));
        }
    }
}
