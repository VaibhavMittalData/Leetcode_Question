class Solution {
public:
    void sub(vector<vector<int>>&ans, vector<int>&res,vector<int>nums,int i ){
        if(nums.size()==i){
            ans.push_back({res});
            return;
        }
        res.push_back(nums[i]);
        sub(ans,res,nums,i+1);
        res.pop_back();
        sub(ans,res,nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        sub(ans,res,nums,0);
        return ans;
    }
};