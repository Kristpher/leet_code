class Solution {
public:
    string removeStars(string s) {
        int flag = 0;
        std::stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*') {
                if (!flag) {
                    stack.push(s[i]);
                } else {
                    flag--;
                }
            } else {
                if (!stack.empty()) {
                    stack.pop();
                } else {
                    flag++;
                }
            }
        }

        string result(stack.size(), ' ');
        for (int i = stack.size() - 1; i >= 0; i--) {
            result[i] = stack.top();
            stack.pop();
        }

        return result;
    }
};
