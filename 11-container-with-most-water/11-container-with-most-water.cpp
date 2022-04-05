class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = -1,i=0,j=height.size()-1;
        while(i<j){
            int area = (abs(i-j)*min(height[i],height[j]));
            if(area>max)
                max=area;
            if(height[i]>height[j])
                j--;
            else if(height[j]>height[i])
                i++;
            else{
                 i++;
                j--;
                
            }
               
                
        }
        
        return max;
        
        
        
        
        
    }
};