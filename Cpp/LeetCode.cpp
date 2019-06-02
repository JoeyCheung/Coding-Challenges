//Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

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

/*
Write a function to find the longest common prefix string amongst an array of strings. 
If there is no common prefix, return an empty string "".
*/

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

/*
Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.
*/

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

/*
Write a function that reverses a string. The input string is given as an array of characters char[].
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
You may assume all the characters consist of printable ascii characters.
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

//verse a singly linked list.

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

//implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

class Solution {
public:
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};

/*
Given a n-ary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
}
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

/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  
Each character in S is a type of stone you have.  
You want to know how many of the stones you have are also jewels.
The letters in J are guaranteed distinct, and all characters in J and S are letters. 
Letters are case sensitive, so "a" is considered a different type of stone from "A".
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) { 
        int ans  = 0;
        for(int i = 0; i < S.length(); i++){
            for(int j = 0; j < J.length(); j++){
                if(J[j] == S[i]){
                    ans ++;
                    break;
                }
            }
        }
        return ans;
    }
};

/*
Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.
You need to merge them into a new binary tree. 
The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. 
Otherwise, the NOT null node will be used as the node of new tree.

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr)
            return t2;
        if (t2 == nullptr)
            return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

/*
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
The binary search tree is guaranteed to have unique values.

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        int ans = 0;
        stack<TreeNode*> st;
        if (root == nullptr) return 0;
        st.push(root);
        while (st.size() > 0) {
            auto p = st.top();
            st.pop();
            if (p != NULL) {
                if (p->val >= L && p->val <= R) {
                    ans += p->val;   // update the sum
                }
                if (L < p->val) {
                    st.push(p->left);  // push left tree
                }
                if (p->val < R) {
                    st.push(p->right);  // push the right tree
                }
            }
        }
        return ans;  
    }
};

/*
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

    get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
    addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    addAtTail(val) : Append a node of value val to the last element of the linked list.
    addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
    deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
*/

class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next;
        Node(int x, Node* n): val(x), next(n) {}
    };
    Node *head, *tail;
    int size;    
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node *cur = head;
        for (int i = 0; i < index; ++i) cur = cur->next;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *t = new Node(val, head);
        head = t;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *cur = head;
        while (cur->next) cur = cur->next;
        cur->next = new Node(val, NULL);
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {addAtHead(val); return;}
        Node *cur = head;
        for (int i = 0; i < index - 1; ++i) cur = cur->next;
        Node *t = new Node(val, cur->next);
        cur->next = t;
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            head = head->next;
            --size;
            return;
        }
        Node *cur = head;
        for (int i = 0; i < index - 1; ++i) cur = cur->next;
        cur->next = cur->next->next;
        --size;
    }
};

// invert a binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == nullptr){
            return root;
        }
 
        invertTree(root->left);
        invertTree(root->right);
 
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
 
        return root;
    }
};
/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its minimum depth = 2.

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int minDepth(TreeNode* root) {
        
        // Corner case. Should never be hit unless the code is  
        // called on root = NULL 
        if (root == NULL) 
            return 0; 
  
        // Base case : Leaf Node. This accounts for height = 1. 
        if (root->left == NULL && root->right == NULL) 
        return 1; 
  
        // If left subtree is NULL, recur for right subtree 
        if (!root->left) 
        return minDepth(root->right) + 1; 
  
        // If right subtree is NULL, recur for left subtree 
        if (!root->right) 
        return minDepth(root->left) + 1; 
  
        return min(minDepth(root->left), minDepth(root->right)) + 1;       
    }
};
