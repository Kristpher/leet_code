class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stack;
        int count = 0;
        string temp = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ')') {
                if (s[i] == '(')
                    count++;
                stack.push(s[i]);
            } else {
                if(count%2==0){
                while (stack.top() != '(' ) {
                    //cout<<stack.top();
                    temp = stack.top() + temp;
                    stack.pop();
                }
                if ( stack.top() == '(') {
                    stack.pop();
                    count--;
                }
                }
                else{
                while (stack.top() != '(' ) {
                     //cout<<stack.top();
                    temp= stack.top()+temp;
                    
                    stack.pop();
                }
                if (  stack.top() == '(') {
                    stack.pop();
                    count--;
                }
                }
                while (!temp.empty()) {
                    stack.push(temp[temp.length() - 1]);
                    cout<<stack.top();
                    temp.pop_back();
                }
                cout<<endl;
            }
        }
        string out = "";
        while (!stack.empty()) {
            out = stack.top()+out;
            stack.pop();
        }
        return out;
    }
};
