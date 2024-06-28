class Solution {
public:
    string addBinary(string a, string b) {
        string temp = "";
        int maxim = max(a.length(), b.length());
        while (a.length() < maxim)
            a = '0' + a;
        while (b.length() < maxim)
            b = '0' + b;

        int i = 0;
        char carry = '0';
        int j = maxim - 1;
        
        while (i < maxim) {
            if (a[j] == b[j]) {
                if (a[j] == '1') {
                    if (carry == '1') {
                        carry = '1';
                        temp = '1' + temp;
                    } else {
                        carry = '1';
                        temp = '0' + temp;
                    }
                } else {
                    if (carry == '1') {
                        carry = '0';
                        temp = '1' + temp;
                    } else {
                        carry = '0';
                        temp = '0' + temp;
                    }
                }
            } else {
                if (carry == '1') {
                    carry = '1';
                    temp = '0' + temp;
                } else {
                    carry = '0';
                    temp = '1' + temp;
                }
            }
            i++;
            j--;
        }
        
        if (carry == '1') {
            temp = '1' + temp;
        }

        return temp;
    }
};
