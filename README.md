# Problem Statement
Develop an application to store contact information like `name`, `phone number`, `email` and `address` allowing users to efficiently `add`, `find` and `manage` contacts.

# Introduction
The phonebook app uses **C++** structs and classes to implement a _**binary search tree**_ for _storing contacts_. This provides efficient logarithmic time searching and inserting compared to linear structures like arrays or linked lists.

# Data Structures
The main data structures used are:

- **Contact Struct** - Contains name, phone number, email and address for each contact
- **TreeNode Class** - Each tree node stores one Contact struct and left/right node pointer to form tree
- **Phonebook Class** - Wrapper class to implement the full phonebook functionality

The TreeNode and Contact struct together implement the logical binary search tree to provide efficient operations.

# Algorithms
The main algorithms are:

- **Insert** -
Recursively traverse left/right nodes based on new phone number to insert
Create new leaf node when reach empty spot
Time Complexity: O(log n)

- **Search** -
Recursively traverse nodes checking phone number match
Also search name field by string match
Time Complexity: O(log n)

- **Traversal** -
Inorder traversal to print contacts alphabetically
Time Complexity: O(n)

- **Delete** -
Find node then handle edge cases (no children or single child)
Replace with minimum from right subtree if two children
Time Complexity: O(log n)

So tree structure with recursive algorithms achieves efficient adding, finding and deletion.

# Build and Execution

- Build `.exe` binary from the source code `phonebook.cpp`

    ```
    g++ -o phonebook.exe phonebook.cpp
    ```
- Execute the previously created binary

    ```
    .\phonebook.exe
    ```
- The output looks as follows

    ```
    Select an option:

    1. Add contact
    2. Delete contact
    3. Search contacts
    4. Display all contacts
    5. Quit
    ```


# Example run

### Add contact

**Input:**
```
Enter name: John
Enter phone: 0123456789
Enter email: john@test.com
Enter address: Testville
```

**Output:**

```
Contact added
```

### Search

**Input:**
```
Enter search query: Testville
```

### Output:
```
John
0123456789
john@test.com
Testville
```