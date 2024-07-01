class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0)
            return 0;
        if(left==right)
        return left;    
      long long p = left; 
       if (right >= 2LL * left) 
            return 0;
      for (long long i = left + 1; i <= right; ++i) {
            p &= i; 
           }
return static_cast<int>(p); 
    }
};
