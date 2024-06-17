class Solution {
public:
  
     int recur(vector<vector<int>>& triangle, int i,int j,int n,vector<vector<int>>& dp){
	if(i==n-1)
	{
		return triangle[n-1][j];
	}
   if(dp[i][j]!=-1)
   return dp[i][j];
   int down=recur(triangle,i+1,j,n,dp)+triangle[i][j];
   int diagonal=recur(triangle,i+1,j+1,n,dp)+triangle[i][j];
    int minim=INT_MAX;
   minim=min(down,diagonal);
   return dp[i][j]=minim;
}

 int minimumTotal(vector<vector<int>>& triangle){
int n=triangle.size();
 vector<vector<int>>dp(n,vector<int>(n+1,-1));
 return recur(triangle,0,0,n,dp);
 
}
};