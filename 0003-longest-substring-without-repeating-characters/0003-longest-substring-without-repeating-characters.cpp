class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==1)
        return 1;
        unordered_map<char,int>map1;
        int l =0;
        int r=0;
        int len=0;
        for(int i=0;i<s.length();i++){
        if(map1.count(s[i])){
        l=map1[s[i]];  
        }
         map1[s[i]]=i+1;
        len=max(len,i-l+1);
      
        }
        return len;
    }
};