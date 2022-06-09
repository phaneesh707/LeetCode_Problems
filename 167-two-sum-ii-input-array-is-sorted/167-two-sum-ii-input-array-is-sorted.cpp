class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        vector<int> temp;
        while(i<j){
            if(target == numbers[i]+numbers[j]){
                temp.push_back(i+1);
                temp.push_back(j+1);
                break;
            }else if(target < numbers[i]+numbers[j])
                j--;
            else
                i++;
                
        }
        return temp;
    }
};