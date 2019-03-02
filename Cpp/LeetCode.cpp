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

Write a function to find the longest common prefix string amongst an array of strings. 
If there is no common prefix, return an empty string "".

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() == 1) return "";
        else {
            int min = strs[0].length();
            for (int i = 1; i < strs.size(); i++) {
                if (min > strs[i].length())
                    min = strs[i].length();
                for (int j = 0; j < min; j++) {
                    if (strs[i][j] != strs[i - 1][j]) {
                        min = j;
                        break;
                    }
                }
            }
            return strs[0].substr(0, min);
        }
    }
};

Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

Write a function that reverses a string. The input string is given as an array of characters char[].
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
You may assume all the characters consist of printable ascii characters.

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

Reverse a singly linked list.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = NULL;
        ListNode* c = head;
        ListNode* n;
        
        while (c != NULL) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        
        return p;
    }
};

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

class Solution {
public:
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};

Given a n-ary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) 
            return 0; 
        int maxdepth = 0; 
        for (vector<Node*>::iterator it = root->children.begin(); it != root->children.end(); it++) {
            maxdepth = max(maxdepth, maxDepth(*it)); 
        }
    return maxdepth + 1 ; 
    }
};
