class Solution {
public:
    int trailingZeroes(int n) {
        int k=1;
        int val=0;
        while(n>k)
        {
            k=k*5;
            val+=n/k;
        }
   return val;
    }
};