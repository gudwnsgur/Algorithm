import java.util.*;

class Solution {
    public String solution(String new_id) {
        // 1단계
        new_id = new_id.toLowerCase();
        System.out.println(new_id);

        // 2단계
        StringBuilder tmp = new StringBuilder();
        for(int i=0; i<new_id.length(); i++) {
            char ch = new_id.charAt(i);
            if(ch >= 'a' && ch <= 'z') tmp.append(ch);
            else if(ch >= '0' && ch <= '9') tmp.append(ch);
            else if(ch == '-' || ch =='_' || ch == '.') tmp.append(ch);
        }
        new_id = tmp.toString();
        System.out.println(new_id);

        //3단계
        tmp = new StringBuilder();
        for(int i=0; i<new_id.length(); i++) {
            if(new_id.charAt(i) != '.') tmp.append(new_id.charAt(i));
            else {
                tmp.append('.');
                while(i <new_id.length()-1 && new_id.charAt(i+1) == '.') i++;
            }
        }
        new_id = tmp.toString();
        System.out.println(new_id);


        // 4단계
        tmp = new StringBuilder();
        for(int i=0; i<new_id.length(); i++) {
            if(i ==0 && new_id.charAt(i) == '.') continue;
            if(i == new_id.length()-1 && new_id.charAt(i) == '.') continue;
            tmp.append(new_id.charAt(i));
        }
        new_id = tmp.toString();
        System.out.println(new_id);


        // 5단계
        if(new_id.length() == 0) new_id += 'a';
        System.out.println(new_id);


        // 6단계
        if(new_id.length() >= 16) {
            new_id = new_id.substring(0, 15);
            if(new_id.charAt(new_id.length()-1) == '.')
                new_id = new_id.substring(0, 14);
        }
        System.out.println(new_id);

        // 7단계
        if(new_id.length() <=2) {
            char ch = new_id.charAt(new_id.length()-1);
            while(new_id.length() < 3) new_id += ch;
        }
        System.out.println(new_id);

        return new_id;
    }
}
