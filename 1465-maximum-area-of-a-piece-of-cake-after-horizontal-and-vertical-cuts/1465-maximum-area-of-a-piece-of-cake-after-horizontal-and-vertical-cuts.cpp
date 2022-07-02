class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& verti) {
        sort(hori.begin(),hori.end());
        sort(verti.begin(),verti.end());
        long long int maxiH = INT_MIN,maxiW=INT_MIN;
        for(int i = 1;i<hori.size();i++){
            if(hori[i]-hori[i-1]>maxiH)
                maxiH = hori[i]-hori[i-1];
        }
        
        if(hori[0]>maxiH) maxiH = hori[0];
        if(h-hori[hori.size()-1]>maxiH) maxiH= h-hori[hori.size()-1];
        
        
        
        for(int i = 1;i<verti.size();i++){
            if(verti[i]-verti[i-1]>maxiW)
                maxiW = verti[i]-verti[i-1];
        }
        if(verti[0]>maxiW) maxiW = verti[0];
        if(w-verti[verti.size()-1]>maxiW) maxiW= w-verti[verti.size()-1];
        
        long long int it = (maxiH*maxiW)%1000000007;
        return it;
    }
};