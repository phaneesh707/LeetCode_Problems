class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> a,b;
        for(int i=0;i<s.size();i++)
            a[s[i]]++;
        for(int i=0;i<t.size();i++)
            b[t[i]]++;
        
        if(a.size()!=b.size())
            return false;
        
        for(auto it = a.begin();it!=a.end();it++){
            if(b[it->first]!=it->second)
                return false;
        }
        
        return true;
                
        
    }
};