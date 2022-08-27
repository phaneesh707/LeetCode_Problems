class Solution {
public:
    bool checkIfPangram(string sen) {
        int n = size(sen);
        vector<int> a(26,0);
        for(int i=0;i<n;i++){
            cout<<sen[i]-'a'<<endl;
            a[sen[i]-'a']+=1;
        }
        
        for(int i=0;i<26;i++){
           if(a[i]==0)
               return 0;
        }
        
        return 1;
    }
};