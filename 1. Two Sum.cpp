/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

//1. Using for loops

#include <iostream> 
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {      
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
        }
        return v;
    }    
};

//O(n2) time complexity

//2. Using Hashing 

#include <iostream> 
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {      
        unordered_map<int, int> cache;
        vector<int> answer;
        
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int needed_num = target - nums[i];
            
            if (cache.find(needed_num) != cache.end())
            {
                // We found it
                answer.push_back(cache[needed_num]);
                answer.push_back(i);
                return answer;
            }
            else
            {
                // Didn't find it
                cache.insert(make_pair(nums[i], i));
            }
        }
        return answer;
    }     
};

//O(n) time complexity
