class Solution {
public:
    string convertToTitle(int columnNumber) {
     string c="";
     int n=columnNumber;
     while(n>0){
       n--;
        int val=n%26;
        n=n/26;
       
        c.push_back(val+'A');
        }
       reverse(c.begin(),c.end());
     return c;
    }
};