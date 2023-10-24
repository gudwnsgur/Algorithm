import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Stack;

class Record {
    String time;
    char io;

    Record(String time, char io) {
        this.time = time;
        this.io = io;
    }

    public static Record enter(String time) {
        return new Record(time, 'I');
    }
}

class Solution {
    int[] answer = new int[]{12};
    ArrayList<String> cars = new ArrayList<>();
    HashMap<String, Integer> parkingRecords = new HashMap<>();
    HashMap<String, Stack<Record>> stack = new HashMap<>();


    public int[] solution(int[] fees, String[] records) {
        initializeCarNumbers(records);
        initializeStack(records);
        calculateMinutesByRecords(records);
        calculateMoney(fees);
        return answer;
    }


    private void calculateMoney(int[] fees) {
        for (int i = 0; i < cars.size(); i++) {
            answer[i] = calculateMoneyByMinutes(parkingRecords.get(cars.get(i)), fees);
        }
    }

    private int calculateMoneyByMinutes(int minute, int[] fees) {
        int result = fees[1];
        if (minute > fees[0]) {
            System.out.println(fees[0] + " " + fees[1] + " " + fees[2] + " " + fees[3]);
            result += Math.ceil((double) (minute - fees[0]) / fees[2]) * fees[3];
        }
        return result;
    }

    private void calculateMinutesByRecords(String[] records) {
        for (String record : records) {
            String time = record.split(" ")[0];
            String carNumber = record.split(" ")[1];

            if (record.split(" ")[2].equals("IN")) {
                stack.get(carNumber).add(Record.enter(time));
            } else {
                Record cur = stack.get(carNumber).pop();
                parkingRecords.put(carNumber, parkingRecords.get(carNumber) + calculateMinute(cur.time, time));
            }
        }
        for (String car : cars) {
            if (!stack.get(car).isEmpty()) {
                parkingRecords.put(car, parkingRecords.get(car) + calculateMinute(stack.get(car).pop().time, "23:59"));
            }
        }
    }

    private void initializeStack(String[] records) {
        for (String record : records) {
            stack.put(record.split(" ")[1], new Stack<>());
        }
    }

    public void initializeCarNumbers(String[] records) {
        for (String record : records) {
            String carNumber = record.split(" ")[1];
            if (!parkingRecords.containsKey(carNumber)) {
                parkingRecords.put(carNumber, 0);
                cars.add(carNumber);
            }
        }
        Collections.sort(cars);
        answer = new int[cars.size()];
    }

    private int calculateMinute(String before, String after) {
        return (Integer.parseInt(after.substring(0, 2)) * 60 + Integer.parseInt(after.substring(3)))
                - (Integer.parseInt(before.substring(0, 2)) * 60 + Integer.parseInt(before.substring(3)));
    }
}

class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        s.solution(new int[]{180, 5000, 10, 600}, new String[]{"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"});
//        s.solution(new int[]{120, 0, 60, 591}, new String[]{"16:00 3961 IN", "16:00 0202 IN", "18:00 3961 OUT", "18:00 0202 OUT", "23:58 3961 IN"});
//        s.solution(new int[]{1, 461, 1, 10}, new String[]{"00:00 1234 IN"});
    }
}
