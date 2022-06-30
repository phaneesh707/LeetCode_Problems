class Solution {
public:
    int minDeletions(string s) {
        int maxi = INT_MIN,count = 0;
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            if(m[s[i]]>maxi)
                maxi = m[s[i]];
        }
        
        vector<int> a(maxi+1,0);
        
        for(auto it=m.begin();it!=m.end();it++){
            // cout<<it->second<<" "<<a[it->second]<<endl;
            if(a[it->second]){
                int l = it->second;
                while(l && a[l]){
                    count++;
                    l--;
                }   
                if(l)
                    a[l]=1;
            }else
                a[it->second]=1;
        }
        
        for(int i=0;i<a.size();i++)
            cout<<a[i]<<" ";
        return count;
        
    }
};