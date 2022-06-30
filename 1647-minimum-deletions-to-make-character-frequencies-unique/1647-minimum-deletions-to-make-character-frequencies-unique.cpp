class Solution {
public:
    //time - O(N) 
    int minDeletions(string s) {
        
        int maxi = INT_MIN,count = 0;
        //cal the freq 
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            if(m[s[i]]>maxi)
                maxi = m[s[i]];
        }

        vector<int> a(maxi+1,0);
        //traversing the map and finding immediate empty places when clashed b/w freq occurs;
        for(auto it=m.begin();it!=m.end();it++){
            if(a[it->second]){
                int l = it->second;
                while(l && a[l]){
                    count++;
                    l--;
                }   
                if(l) a[l]=1;
            }else
                a[it->second]=1;
        }

        return count;
        
    }
};