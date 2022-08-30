/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
 
Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        vector<int> counter1(26,0), counter2(26,0);

        for(int idx = 0; idx < s.length(); idx++) {
            counter1[s[idx]-'a']++;
            counter2[t[idx]-'a']++;
        }

        for(int idx = 0; idx < 26; idx++) {

            if(counter1[idx] != counter2[idx])
                return false;
        }
        return true;
    }
};
