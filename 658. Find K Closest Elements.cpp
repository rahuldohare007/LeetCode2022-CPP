/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 
Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 
Constraints:
1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
*/ 

class Solution {
public:
        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans;
        for(int i=0; i<arr.size(); i++)
        {
            int k = arr[i]-x;
            if(k < 0)
                k *= -1;
				//to make negative no. difference  a positive number for sorting
            pq.push({k, arr[i]});
        }
        while(k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
