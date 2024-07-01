class Solution {
public:
    bool isPowerOfTwo(int i) {
        int n=0;
        long long num=1;
        while(num<i)
        {
           num=pow(2,n);
           n++;
        }
       if(num==i)
       return true;
      return false;
    }
};