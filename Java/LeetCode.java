/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

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

//Given an array nums and a value val, remove all instances of that value in-place and return the new length.
    
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

//Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

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

/*
Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.
You need to merge them into a new binary tree. 
The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. 
Otherwise, the NOT null node will be used as the node of new tree.

 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null)
            return t2;
        if (t2 == null)
            return t1;
        t1.val += t2.val;
        t1.left = mergeTrees(t1.left, t2.left);
        t1.right = mergeTrees(t1.right, t2.right);
        return t1;
    }
}

/*
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
The binary search tree is guaranteed to have unique values.

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        
        int ans = 0;
        Stack<TreeNode> st = new Stack<TreeNode>();
        if (root == null) return 0;
        st.push(root);
        while (st.size() > 0) {
            TreeNode p = st.peek();
            st.pop();
            if (p != null) {
                if (p.val >= L && p.val <= R) {
                    ans += p.val;   // update the sum
                }
                if (L < p.val) {
                    st.push(p.left);  // push left tree
                }
                if (p.val < R) {
                    st.push(p.right);  // push the right tree
                }
            }
        }
        return ans;  
    }
}

/*
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

    get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
    addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    addAtTail(val) : Append a node of value val to the last element of the linked list.
    addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
    deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.

 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
*/

class MyLinkedList {

    private int size;
    private Node head;
    private Node tail;
    
    public static class Node {
        private int val;
        private Node next;
        public Node(int val) {
        this.val = val;
        }
    }

    /** Initialize your data structure here. */
    public MyLinkedList() {
        size = 0;
        head = null;
        tail = null;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (size == 0 || index >= size) return -1;
        // asset: size > 0 && index >= 0 && exists valid result
        Node target = head;
        for (int i = 0; i < index; i++) {
            target = target.next;
        }
        return target.val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        Node newNode = new Node(val);
        if (size == 0) {
            head = newNode;
            tail = head;
        } else {
            newNode.next = head;
            head = newNode;
        }
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        Node newNode = new Node(val);
        if (size == 0) {
            head = newNode;
            tail = head;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            Node newNode = new Node(val);
            Node pre = head;
            for (int i = 1; i < index; i++) pre = pre.next;
            newNode.next = pre.next;
            pre.next = newNode;
            size++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if (size == 0 || index >= size) return;
        if (size == 1) {
            head = null;
            tail = null;
        } else if (index == 0){
            head = head.next;
        } else {
            Node pre = head;
            for (int i = 1; i < index; i++) pre = pre.next;
            if (pre.next == tail) tail = pre;
            pre.next = pre.next.next;
        }
        size--;
    }
}

/*
Invert Binary Tree

 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode invertTree(TreeNode root) {
        
        if(root==null){
            return root;
        }
 
        invertTree(root.left);
        invertTree(root.right);
 
        TreeNode t = root.left;
        root.left = root.right;
        root.right = t;
 
        return root;
    }
}
