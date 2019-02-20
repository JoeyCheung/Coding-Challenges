Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0,val;
        val = x;
        while(x > 0) { 
            rev = rev * 10 + x % 10; 
            x = x / 10; 
        } 
        if(val==rev) return true;
        else return false;
    }
};
