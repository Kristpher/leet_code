class Solution {
public:
    long long minimumSteps(string s) {
      long long swaps=0;
      long long count=0;
      for(int i=0;i<s.length();i++)
      {
        if(s[i]=='1')
        count++;
        else
        swaps+=count;

      }   
      return swaps;
    }
};