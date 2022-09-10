/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0

Constraints:
3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/ 

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0,diff = 1e8;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0 ; i<size-1 ; i++){
            int l = i+1, r = size-1;
            while(l < r){
                int curr = nums[i] + nums[l] + nums[r];
                if(abs(target-curr) < diff){
                    diff = abs(target - curr);
                    ans = curr;
                    if(diff == 0) return ans;
                }
                else if(curr > target){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};
