class Solution {
public:
    
    static bool helper(const vector<int>& v1,const vector<int>& v2){
        return v1[1]>v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& box, int truck) {
        sort(box.begin(),box.end(),helper);
        int sum = 0,units = 0,i=0;
        
        while(i<box.size() && units+box[i][0]<=truck){
            sum+=box[i][0]*box[i][1];
            units+=box[i][0];
            i++;
            
            // cout<<sum<<" "<<units<<endl;
        }
        
        if(i<box.size()) sum+=(truck-units)*box[i][1];
        return sum;
        
    }
};