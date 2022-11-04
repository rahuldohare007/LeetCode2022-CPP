/*
Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. Return the output in any order.

Example 1:
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: s = "3z4"
Output: ["3z4","3Z4"]

Constraints:
1 <= s.length <= 12
s consists of lowercase English letters, uppercase English letters, and digits.
*/ 

class Solution {
public:
    void backtrack(string &s, int i, vector<string> &ans) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        char c = s[i];
        s[i] = islower(c) ? toupper(c) : tolower(c);
        backtrack(s, i + 1, ans);
        
        if (isalpha(c)) {
            s[i] = c;
            backtrack(s, i + 1, ans);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtrack(s, 0, ans);
        return ans;
    }    
};
