class Solution {
public:
    int lengthOfLastWord(string s) {
        int val=0;
        int count=0;
        for(int i=0;i<s.length();i++)
        {
       
            if(s[i]!=' ')
            {
              count++;
            }
            else{
                if(count!=0)
                val=count;
                cout<<val<<" ";
                count=0;
            }

        }
        if(s[s.length()-1]!=' ' && count!=0)
        val=count;
        return val;
    }
};