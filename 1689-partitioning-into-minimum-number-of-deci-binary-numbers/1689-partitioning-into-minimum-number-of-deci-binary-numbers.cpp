class Solution {
public:
    int minPartitions(string n) {
        int maxi = 1;
        for(int i=0;i<n.length();i++){
            if(maxi<(n[i]-'0'))
                maxi = n[i]-'0';
        }
        return maxi;
    }
};