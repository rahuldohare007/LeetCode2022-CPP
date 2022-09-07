/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2
 
Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 1000
*/ 

class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0, maxIndex = 0, size = nums.size(), cnt = 0, i;
        if(size <= 1)
            return 0;
        while(end < size) {
		    //when cnt = 1, at the end, we will get maxIndex which is the fartehst index you can go in 1 step and so on
            cnt++; 
            //find the maximum index you can reach in the range [start, end]
            for(i = start; i <= end; i++) {
                if(i + nums[i] >= size - 1)
                    return cnt;
                maxIndex = max(maxIndex, i + nums[i]);
            }
            //the next start will be end + 1, because we have processed till end
            start = end + 1;
            //the next end will be the maximum index you can reach till now
            end = maxIndex;        
        }
        return cnt;
    }
};
