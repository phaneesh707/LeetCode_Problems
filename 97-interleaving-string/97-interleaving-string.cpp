class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
   if(s1.size()+s2.size()!=s3.size()) return false;
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    
    return fun(s1,s2,s3,0,0,dp);
}
bool fun(string &s1, string &s2, string &s3,int ind1,int ind2,vector<vector<int>>&dp)
{
    if(ind1+ind2==s3.size()) return 1;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    bool ans=0;        
    if(ind1<s1.size() and s1[ind1]==s3[ind1+ind2] and fun(s1,s2,s3,ind1+1,ind2,dp)) ans=1;
    if(ind2<s2.size() and s2[ind2]==s3[ind1+ind2] and fun(s1,s2,s3,ind1,ind2+1,dp)) ans=1;
    
    return dp[ind1][ind2]=ans;
}
};