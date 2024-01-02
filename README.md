Problem Statement
Develop an application to store contact information like name, phone number, email and address allowing users to efficiently add, find and manage contacts.

Introduction
The phonebook app uses C++ structs and classes to implement a binary search tree data structure for storing contacts.
This provides efficient logarithmic time searching and inserting compared to linear structures like arrays or linked lists.

Data Structures
The main data structures used are:

Contact Struct - Contains name, phone number, email and address for each contact
TreeNode Class - Each tree node stores one Contact struct and left/right node pointer to form tree
Phonebook Class - Wrapper class to implement the full phonebook functionality
The TreeNode and Contact struct together implement the logical binary search tree to provide efficient operations.

Algorithms
The main algorithms are:

Insert
Recursively traverse left/right nodes based on new phone number to insert
Create new leaf node when reach empty spot
Time Complexity: O(log n)

Search
Recursively traverse nodes checking phone number match
Also search name field by string match
Time Complexity: O(log n)

Traversal
Inorder traversal to print contacts alphabetically
Time Complexity: O(n)

Delete
Find node then handle edge cases (no children or single child)
Replace with minimum from right subtree if two children
Time Complexity: O(log n)

So tree structure with recursive algorithms achieves efficient adding, finding and deletion.

Usage
The user can interact by choosing options:

Add new contact
Delete existing contact
Search contacts by name/number
Display all contacts
Example run:

Input:
Add contact John 1234567 john@test.com
Output:
Contact added

Input:
Search Joh
Output:
John 1234567 john@test.com

Thus, provides features expected from basic phonebook application.

Conclusion
The C++ binary search tree implementation meets efficiency and functional requirements for the phonebook application while providing for future enhancements.
