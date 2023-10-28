import java.util.HashMap;

class Solution {

    HashMap<String, Integer> employees = new HashMap<>();
    int[] tree, totalAmount;
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        initializeTree(enroll, referral);

        for(int i=0; i<seller.length; i++) {
            settleMoney(employees.get(seller[i]), amount[i] * 100);
        }
        return totalAmount;
    }

    public void settleMoney(int cur, int money) {
        do {
            if(money < 10) {
                totalAmount[cur] += money;
                return;
            }
            totalAmount[cur] += money - money/10;
            cur = tree[cur];
            money /= 10;
        } while (cur != -1);
    }
    public void initializeTree(String[] enroll, String[] referral) {
        tree = new int[enroll.length];
        totalAmount = new int[enroll.length];

        for(int i=0; i<enroll.length; i++) {
            employees.put(enroll[i], i);
        }
        for(int i=0; i<referral.length; i++) {
            if (referral[i].equals("-")) tree[i] = -1;
            else tree[i] = employees.get(referral[i]);
        }
    }
}

