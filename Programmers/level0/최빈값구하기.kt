import java.util.ArrayList;

class Number {
    int number;
    int cnt;

    public Number(int number, int cnt) {
        this.number = number;
        this.cnt = cnt;
    }
}

class Solution {
    public int solution(int[] array) {
        int[] counts = new int[1000];
        for(int i=0; i<array.length; i++) counts[array[i]]++;
        ArrayList<Number> list = new ArrayList<>();
        for(int i=0; i<1000; i++) {
            if(counts[i] != 0) list.add(new Number(i, counts[i]));
        }
        list.sort((number1, number2) -> Integer.compare(number2.cnt, number1.cnt));

        if(list.size() == 1 || (list.size() > 1 && list.get(0).cnt > list.get(1).cnt)) return list.get(0).number;
        return -1;
    }
}
