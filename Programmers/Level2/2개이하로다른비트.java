import java.util.*;
import java.io.*;

class Solution {

    long solve(long number) {
        long result = 0;
        String bit = Long.toBinaryString(number);
        if(bit.charAt(bit.length()-1) == '0') return number+1;

        int zeroIdx = -1;
        for(int i=bit.length()-1; i>=0; i--) {
            if(bit.charAt(i) == '0') {
                zeroIdx = i;
                break;
            }
        }
        System.out.println(zeroIdx);
        if(zeroIdx == -1) {
            return (long)(number + Math.pow(2, bit.length()) - Math.pow(2, bit.length()-1));
        }


        StringBuilder newBit = new StringBuilder();
        int idx = 0;
        for(; idx<zeroIdx; idx++) newBit.append(bit.charAt(idx));
        newBit.append('1');
        newBit.append('0');
        idx += 2;
        for(; idx < bit.length(); idx++) newBit.append(bit.charAt(idx));


        long mul = 1;
        for(int i=newBit.length()-1; i>=0; i--) {
            result += (newBit.charAt(i) == '1' ? mul : 0);
            mul *= 2;
        }

        return result;
    }


    public long[] solution(long[] numbers) {
        ArrayList<Long> ans = new ArrayList<>();
        for(int i=0; i< numbers.length; i++) {
            ans.add(solve(numbers[i]));
        }

        long[] answer = new long[ans.size()];
        for(int i=0; i<ans.size(); i++) answer[i] = ans.get(i);
        return answer;
    }
}

class Main {
    public static void main(String[] args) throws IOException {

    }
}
