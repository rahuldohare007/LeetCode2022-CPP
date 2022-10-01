/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/ 

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size())
            return addBinary(b, a);
        
        int x = a.size() - 1;
        int y = b.size() - 1;

        unsigned short n = 0;
        
        for(; x >= 0; x--){
            n += (a[x] == '1') + (y < 0 ? 0 : b[y--] == '1');
            a[x] = '0' + (n & 1);
            n >>= 1;
        }
        
        if(n)
            return '1' + a;
        else
            return a;
    }
};
