class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stack;
        int count = 0;
        string temp = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ')') {
                stack.push(s[i]);
            } else {
                while (stack.top() != '(') {
                    temp = stack.top() + temp;
                    stack.pop();
                }
                if (stack.top() == '(') {
                    stack.pop();
                }
                while (!temp.empty()) {
                    stack.push(temp[temp.length() - 1]);
                    temp.pop_back();
                }
            }
        }
        string out = "";
        while (!stack.empty()) {
            out = stack.top() + out;
            stack.pop();
        }
        return out;
    }
};
