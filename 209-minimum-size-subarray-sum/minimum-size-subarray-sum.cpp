class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int>s;
        int sum =0;
        int left =0;
        int count =INT_MAX;
        for(int i =0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                count = min(count,i-left+1);
                sum-=nums[left];
                left++;
            }
        }
        if(count==INT_MAX)return 0;
        return count;
    }
};