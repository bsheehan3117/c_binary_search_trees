# Homework 10 - Binary Search Trees (BST)

Name: Brendan Sheehan

Github Account name: bsheehan3117

Link to Assignment on Github: https://github.com/Su23-CS5008-Online-Lionelle/homework10-bsheehan3117.git

How many hours did it take you to complete this assignment (estimate)? 

14

Did you collaborate with any other students/TAs/Professors? If so, tell us who and in what capacity.  
- one per row, add more if needed

No.

Did you use any external resources (you do not have to cite in class material)? (Cite them below)  
- one row per resource

No.

(Optional) What was your favorite part of the assignment? 

(Optional) How would you improve the assignment? 

## BST Questions

1. Given a *balanced* and *full* Binary Search Tree, what is the Big O for finding a value in the tree?

The Big O for finding a value in the tree is O(log n).

2. Define balanced in relation to BSTs. Remember to relate it to height. 


A BST is balanced if every node's left and right sides are almost the same height.  They can be different by one level at most. This means the tree doesn't lean too much to one side and is balanced.

3. What is the Worst Case Big O for searching or adding to a BST?

The worst case is O(n).

   * What type of BST would this be? (how would it look)

According to the CLRS article it would look like a linear chain of nodes, almost like a linked list.
 "If the tree is a linear chain of n nodes, however, the same operations take O(n) worst-case time" (CLRS Binary_Search_Trees)

This would be a degenerate tree.

4. What are some of the advantages of a BST over a linked list?

A balanced BST has a time complexity of O(log n) which is better than a linked list time complexity of O(n).  They can also show relationships between data as opposed to a linked list.

5. What are some cases / examples of when you would use a BST?

A BST would be used if you want to keep data in order retrive it in sorted order.  It would also be used for finding data quickly in a balanced tree or when the tree needs to change in size when adding or removing data.



