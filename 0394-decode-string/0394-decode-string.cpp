class Solution {
public:
    bool isnum(char c) {
        return c >= '0' && c <= '9';
    }

    string decodeString(string s) {
        std::stack<char> stack;
        string temp = "";
        string out = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                stack.push(s[i]);
            } else {
              
                temp = "";
                while (!stack.empty() && stack.top() != '[') {
                    temp = stack.top() + temp;
                    stack.pop();
                }
                stack.pop();
                string str = "";
                while (!stack.empty() && isnum(stack.top())) {
                    str = stack.top() + str;
                    stack.pop();
                }

                int no = stoi(str);
                string sub = "";
                for (int j = 0; j < no; j++) {
                    sub += temp;
                }

          
                for (char c : sub) {
                    stack.push(c);
                }
            }
        }

      
        while (!stack.empty()) {
            out = stack.top() + out;
            stack.pop();
        }

        return out;
    }
};