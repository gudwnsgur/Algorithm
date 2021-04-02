import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static final int[] priority = new int[124];

    static boolean isNum(char ch) {
        return ch >= '0' && ch <= '9';
    }

    static int fileCompare(String a, String b) {
//        System.out.println(a + " 비교 " + b);

        for(int i=0, j=0; i<a.length() && j<b.length(); i++, j++) {
            if(isNum(a.charAt(i)) && isNum(b.charAt(i))) {
                String aNum = "", bNum = "";
                while(i<a.length() && isNum(a.charAt(i))) {
                    aNum += a.charAt(i);
                    i++;
                }
                i--;
                while(j<b.length() && isNum(b.charAt(j))) {
                    bNum += b.charAt(j);
                    j++;
                }
                j--;

//                System.out.println(aNum + " " + bNum);
                int aZero = 0, bZero = 0;
                String aa = "", bb = "";
                int aIdx = 0, bIdx = 0;
                while(aIdx < aNum.length() && aNum.charAt(aIdx++) == '0') aZero++;
                while(bIdx < bNum.length() && bNum.charAt(bIdx++) == '0') bZero++;
                aIdx--; bIdx--;

                while(aIdx < aNum.length()) aa += aNum.charAt(aIdx++);
                while(bIdx < bNum.length()) bb += bNum.charAt(bIdx++);

//                System.out.println(aa + "(" + aZero + ")  " + bb + "(" +bZero + ")");

                if(aa.length() < bb.length()) return -1;
                else if(aa.length() > bb.length()) return 1;

                for(int k=0; k<aa.length(); k++) {
                    if(aa.charAt(k) < bb.charAt(k)) return -1;
                    else if(aa.charAt(k) > bb.charAt(k)) return 1;
                }
                if(aZero < bZero) return -1;
                else if(aZero > bZero) return 1;
            }

            else if(a.charAt(i) == b.charAt(j)) continue;

            if(priority[a.charAt(i)] < priority[b.charAt(j)]) return -1;
            else if(priority[a.charAt(i)] > priority[b.charAt(j)]) return 1;
        }


        if(a.length() < b.length()) return -1;
        else if(a.length() > b.length()) return 1;
        return 0;
    }

    public static void main(String[] args) throws IOException {
        for(int i=48; i<=57; i++) priority[i] = i;
        for(int i=65, j=65; i<=90; i++, j+=2) priority[i] = j;
        for(int i=97, j=66; i<=122; i++, j+=2) priority[i] = j;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<String> arr = new ArrayList<>();
        while(n-- > 0 ) arr.add(br.readLine());


        Collections.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return fileCompare(o1, o2);
            }
        });


        for(int i=0; i<arr.size(); i++) System.out.println(arr.get(i));
    }
}

