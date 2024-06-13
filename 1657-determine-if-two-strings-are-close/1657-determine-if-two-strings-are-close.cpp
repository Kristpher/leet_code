class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())
        return false;
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        unordered_map<int,int>map3;
        unordered_map<int,int>map4;
      
      
        for(int i=0;i<word1.length();i++){
            map1[word1[i]-'a']++;
            map2[word2[i]-'a']++;
        }
        for(int i=0;i<word1.length();i++)
        {
            if(map2[word1[i]-'a']<=0)
            return false;
        }
        for(int i=0;i<word1.length();i++)
        {
            map3[map1[word1[i]-'a']]++;
            map4[map2[word2[i]-'a']]++;
        }
        for(int i=0;i<word1.size();i++)
        {
            map4[map1[word1[i]-'a']]--;
        }
        for(int i=0;i<word2.size();i++)
        {
            if(map4[map2[word2[i]-'a']]>0)
            return false;
        }
        return true;
    }
};