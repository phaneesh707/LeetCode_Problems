class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(),n = word2.size();
        vector<vector<int>> dummy(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(!i || !j)
                    dummy[i][j] = i + j;
                else{
                    if(word1[i-1] == word2[j-1])
                        dummy[i][j] = dummy[i-1][j-1];
                    else
                        dummy[i][j] = 1 + min(dummy[i-1][j],dummy[i][j-1]);
                }
            }
        }
        
        
        return dummy[m][n];
    }
    
    
};