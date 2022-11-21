/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers
directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"
 
Constraints:
1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/ 

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i1 = num1.size() - 1, i2 = num2.size() - 1, carry = 0;
        while (i1 >= 0 || i2 >= 0 || carry > 0) {
            if (i1 >= 0) {
                carry += num1[i1] - '0';
                i1 -= 1;
            }
            if (i2 >= 0) {
                carry += num2[i2] - '0';
                i2 -= 1;
            }
            ans += char(carry % 10 + '0');
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
