Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
    
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == target - nums[i]) {
                    return new int[] { i, j };
                }
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}

Given an array nums and a value val, remove all instances of that value in-place and return the new length.
    
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
}

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

class Solution {
    public boolean isPalindrome(int x) {
        
        int rev = 0,val;
        val = x;
        while(x > 0) { 
            rev = rev * 10 + x % 10; 
            x = x / 10; 
        } 
        if(val==rev) return true;
        else return false;
        
    }
}
