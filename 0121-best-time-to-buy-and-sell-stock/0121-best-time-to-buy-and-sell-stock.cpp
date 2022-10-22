class Solution {
public:
    int maxProfit(vector<int>& a) {
        int mini = a[0];
        int maxi = 0;
        for(int i=1;i<size(a);i++){
            mini = min(mini,a[i]);
            maxi = max(maxi,a[i]-mini);
        }
        return maxi;
    }
};