class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<char,int> a,b;
        for(auto it:word1) a[it]++;
        for(auto it:word2) b[it]++;
        
      
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                char x = i+'a',y = j+'a';
                
                if(a.find(x)!=a.end() && b.find(y)!=b.end()){
                    cout<<a[x]<<" "<<b[y]<<endl;
                    a[x]--;
                    b[y]--;
                    if(a[x]==0) a.erase(x);
                    if(b[y]==0) b.erase(y);
                    
                    a[y]++;
                    b[x]++;
                    
                    if(size(a) == size(b)) return true;
                    
                    //reswap
                    a[y]--;
                    b[x]--;
                    if(a[y]==0) a.erase(y);
                    if(b[x]==0) b.erase(x);
                    
                    a[x]++;
                    b[y]++;
                    
                }
            }
        }
        
        return false;
    }
};