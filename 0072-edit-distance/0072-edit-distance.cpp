class Solution {
public:
    int recur(int i,int j,string &w1,string &w2,vector<vector<int>>&dp){
        if(i<0)
        return j+1;
        if(j<0)
        return i+1;
        int minim;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(w1[i]==w2[j])
        return recur(i-1,j-1,w1,w2,dp);
        
        else{
          minim=min(recur(i,j-1,w1,w2,dp)+1,min(recur(i-1,j-1,w1,w2,dp)+1,recur(i-1,j,w1,w2,dp)+1)); 
         }    
        return dp[i][j]=minim;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        int i=word1.length()-1;
        int j=word2.length()-1;
        return recur(i,j,word1,word2,dp); 
    }
};