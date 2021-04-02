
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    private static int[] priority = new int[126];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Character> stack = new Stack<>();
        priority['('] = priority[')'] = 1;
        priority['+'] = priority['-'] = 2;
        priority['*'] = priority['/'] = 3;
        String op = br.readLine();
        String result = "";

        for (int i = 0; i < op.length(); i++) {
            char ch = op.charAt(i);

            // 1. 피연산자 : 출력
            if (ch >= 'A' && ch <= 'Z') result += ch;

            // 2. 여는 괄호 : 스택에 push
            else if (ch == '(') stack.add(ch);

            // 3. 닫는 괄호 : 스택의 '(' 까지 연산자 출력
            else if (ch == ')') {
                while (stack.peek() != '(') {
                    result += stack.peek();
                    stack.pop();
                }
                stack.pop();
            }

            // 4. 연산자
            else {
                // 4-1. 스택이 비어있으면 스택에 push
                if (stack.isEmpty()) stack.push(ch);
                // 4-2. 우선순위 비교
                else {
                    while (!stack.isEmpty() && priority[stack.peek()] >= priority[ch]) {
                        result += stack.peek();
                        stack.pop();
                    }
                    stack.add(ch);
                }
            }
        }
        // 5. 스택에 남은 연산자 출력
        while (!stack.isEmpty()) {
            result += stack.peek();
            stack.pop();
        }
        System.out.println(result);
    }
}

