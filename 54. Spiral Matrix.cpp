/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/ 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int rs=0, re=n-1, cs=0, ce=m-1;
        vector<int> ans;
        while(rs <= re && cs <= ce){
            for(int col=cs; col<= ce; col++){
                ans.push_back(matrix[rs][col]);
            }
            rs++;
            for(int row=rs; row<=re; row++){
                ans.push_back(matrix[row][ce]);
            }
            ce--;
            if(rs > re)
                break;
                
            for(int col=ce; col>=cs; col--){
                ans.push_back(matrix[re][col]);
            }
            re--;
            if(cs > ce)
                break;
                
            for(int row=re; row>=rs; row--){
                ans.push_back(matrix[row][cs]);
            }
            cs++;
            if(rs > re)
                break;
        }
        return ans;
    }
};
