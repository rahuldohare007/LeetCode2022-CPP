/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
Input: s = "God Ding"
Output: "doG gniD"
 
Constraints:
1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/ 

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        
        while(right < n)
        {
            while(right < n && s[right] != ' ')
            {
                right++;
            }
            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
            right++;
        }
        
        return s;
    }
};
