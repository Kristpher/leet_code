class Solution {
public:
    string recur(vector<int>& temp, string str, int& k, int f[], int n) {
        if (temp.size() == n) {
            k--;
            if (k == 0) {
                long long a = 0;
                for (int i = 0; i < temp.size(); i++) {
                    a = a * 10 + temp[i];
                }
                str = to_string(a);
            }
            return str;
        }
        
        int fact = 1;
        for (int i = 1; i <= n - temp.size() - 1; ++i) {
            fact *= i;
        }

        for (int i = 1; i <= n; i++) {
            if (!f[i]) {
                if (fact < k) {
                    k -= fact;
                    continue;
                }
                f[i] = 1;
                temp.push_back(i);
                str = recur(temp, str, k, f, n);
                if (k == 0) return str;
                f[i] = 0;
                temp.pop_back();
            }
        }
        return str;
    }

    string getPermutation(int n, int k) {
        vector<int> temp;
        int f[n + 1];
        for (int i = 0; i <= n; i++)
            f[i] = 0;

        string str = "";
        return recur(temp, str, k, f, n);
    }
};
