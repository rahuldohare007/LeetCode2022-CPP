/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/ 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string final_str = strs[0], new_str = "";
        int size = strs.size();
        for (int i = 0; i < size; i++)
        {
            int size1 = final_str.size(),size2 = strs[i].size();
            int j = 0,k = 0;
            while(j < size1 && k < size2){
                if(final_str[j] == strs[i][k]){
                    new_str += final_str[k];
                }
                else{
                    break;
                }
                k++;
                j++;
            }
            final_str = new_str;
            new_str = "";
        }
        return final_str;
    }
};
