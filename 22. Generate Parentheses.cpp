/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
 
Constraints:
1 <= n <= 8
*/ 

class Solution {
public:
    void f(int open, int close, vector<string> &v, string s){
        if(open == 0 && close == 0)
        {
            v.push_back(s);
            return;
        }

        if(close == 0 && open != 0)
            return;

        if(open == 0)
            f(open, close - 1, v, s + ')');

        else{
            if(open < close)
            {
                f(open - 1, close, v, s + '(');
                f(open, close - 1, v, s + ')');
            }
            else
                f(open - 1, close, v, s + '(');
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        f(n - 1, n, v, "(");
        return v;
    }
};
