class Solution {
public:
    int trap(vector<int>& height) {
        int rightmax = 0,leftmax =0,left =0,right=height.size()-1, ans =0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=leftmax)leftmax = height[left];
                else ans += leftmax - height[left];
                left++;
            }
            else{
                if(height[right]>=rightmax)rightmax = height[right];
                else ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};