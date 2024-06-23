class Solution {
public:
    bool isPalindrome(string s) {
      int k=0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] > 64 && s[i] < 91) {
                char val = s[i] + 32 ;
                s[k]=val;
                k++;
            } else if (s[i] < 123 && s[i] > 96 ||(s[i]>=48 && s[i]<=57)) {        
                 char val = s[i]  ;
                    s[k]= val;
                    k++;
            }
            else
            continue;
        }
    
        int l = 0;
        int r = k-1;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};