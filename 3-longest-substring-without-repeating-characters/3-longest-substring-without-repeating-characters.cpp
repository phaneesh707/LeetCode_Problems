class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        unordered_map<char,int> dummy;
        int maxi = 1,flag = 0;
        string str;
        int index,i=0;
        while(i<s.length())
        {
            for(int j = maxi;j<=s.length()-i;j++)
            {
                dummy.clear();
                str = s.substr(i,j);
                // cout<<str<<" "<<maxi<<endl;
                
                flag = 0;
                for(int k = 0;k<str.length();k++)
                {
                    if(dummy.find(str[k])==dummy.end())
                        dummy[str[k]] = 1;
                    else{
                        flag = 1;
                    } 
                        
                }
                if(!flag){
                    int n=str.length();
                    maxi = max(maxi,n);
                }else
                    break;
                
                
                
            }
            // cout<<"out i = "<<i<<endl;
            i++;
        }
        
        
        
        return maxi;
    }
};