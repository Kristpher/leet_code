class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int k=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1' &&s[k]!='1')
            swap(s[k++],s[i]);
            if(s[k]=='1')
            k++;
        }
        k--;
        if(s[s.length()-1]!='1')
        swap(s[k],s[s.length()-1]);
        return s;
    }
};