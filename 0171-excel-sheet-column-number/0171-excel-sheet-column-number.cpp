class Solution {
public:
    int titleToNumber(string columnTitle) {
        int k=0;
        int n=0;
        int l=0;
        while(k<columnTitle.length()){
           int c=columnTitle[k]-'A'+1;
           n=n*26+c;
           k++;
        }
        return n;

    }
};