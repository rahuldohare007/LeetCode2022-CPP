/*
Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed 
(for example, 1 and 5).

Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 
Constraints:
1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/ 

class Solution {
public:
    void merge(vector<int>&nums, int l, int mid, int r)
    {
        if(l >= r)
            return;
        int i = l;
        int j = mid + 1;
        vector<int> sorted;
        while(i <= mid && j <= r)
        {
            if(nums[i] <= nums[j])
                sorted.push_back(nums[i]), i++;
            else
                sorted.push_back(nums[j]), j++;
        }
        if(i > mid)
        {
            while(j <= r)
                sorted.push_back(nums[j]), j++;
        }
        else
        {
            while(i <= mid)
                sorted.push_back(nums[i]), i++;
        }
        int k = 0;
        for(int i=l; i<=r; i++)
        {
            nums[i] = sorted[k];
            k++;
        }
    }
    void mergesort(vector<int>&nums, int l, int r)
    {
        if(l < r){
            int mid = (l+r)/2;
            mergesort(nums, l, mid);
            mergesort(nums, mid+1, r);
            merge(nums, l, mid, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};
