import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        int testCase = Integer.parseInt(br.readLine());

        for (int i = 0; i < testCase; i++) {
            tk = new StringTokenizer(br.readLine());
            int result = getCasesOfStealMoney(Integer.parseInt(tk.nextToken()),
                                              Integer.parseInt(tk.nextToken()),
                                              Integer.parseInt(tk.nextToken()));
            System.out.println(result);
        }
    }

    static int getCasesOfStealMoney(int house, int targetHouse, int maxMoney) throws IOException {
        int[] money = getMoneyList(house, targetHouse);
        long currentMoney = getFirstMoney(money, targetHouse);
        int count = currentMoney < maxMoney ? 1 : 0;

        for (int i = targetHouse; i < money.length; i++) {
            currentMoney = currentMoney - money[i - targetHouse] + money[i];
            if (currentMoney < maxMoney) {
                count++;
            }
        }
        return count;
    }

    private static long getFirstMoney(int[] money, int targetHouse) {
        int currentMoney = 0;
        for (int i = 0; i < targetHouse; i++) {
            currentMoney += money[i];
        }
        return currentMoney;
    }

    private static int[] getMoneyList(int house, int targetHouse) throws IOException {
        tk = new StringTokenizer(br.readLine());
        int[] money = house == targetHouse ? new int[house] : new int[house + targetHouse - 1];
        for (int j = 0; j < house; j++) {
            money[j] = Integer.parseInt(tk.nextToken());
        }

        if(house != targetHouse) {
            for (int j = house; j < house + targetHouse - 1; j++) {
                money[j] = money[j - house];
            }
        }
        return money;
    }
}

