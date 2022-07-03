class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
	int n = size(nums), up = 1, down = 1;
	for(int i = 1; i < n; i++){
		if(nums[i] < nums[i - 1])
            up = 1 + down;
		else if(nums[i] > nums[i - 1]) 
            down = 1 + up;
    }

	return max(up, down); 
}
};