/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character
 
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 
Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/ 

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int **output = new int*[m + 1];
        for(int i = 0; i <= m; i++)
            output[i] = new int[n + 1];

        for(int i = 0; i <= m; i++)
            output[i][0] = i;

        for(int i = 0; i <= n; i++)
            output[0][i] = i;

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[m - i] == word2[n - j])
                    output[i][j] = output[i - 1][j - 1];
                else
                    output[i][j] = min(output[i - 1][j] + 1, min(output[i][j - 1] + 1, output[i - 1][j - 1] + 1));
            }
        }
        return output[m][n];
    }
};
