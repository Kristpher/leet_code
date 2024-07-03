class Solution {
public:
    void back(int n, vector<string>& out, string temp, int l, int r) {
        if (l == n && r == n) {
            out.push_back(temp);
            return;
        }
        
        if (l < n) {
            temp += '(';
            back(n, out, temp, l + 1, r);
            temp.pop_back(); 
        }
        if (r < l) {
            temp += ')';
            back(n, out, temp, l, r + 1);
            temp.pop_back(); 
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string temp = "";
        back(n, out, temp, 0, 0);
        return out;
    }
};
