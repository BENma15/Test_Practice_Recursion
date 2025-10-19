# Binary Tree Insert Example

This folder contains a simple Binary Search Tree Insert implementation

## Files

- `tree_insert_example.cpp` - TODO: Implement the recursive `Insert` function
- `tree_insert_example_answer.cpp` - Complete solution
- `Makefile` - Build configuration for easy compilation
- `.vscode/` - VS Code debugging configuration

## Usage

### Compilation
```bash
make
```

### Running
```bash
./tree_insert_example
```

### Debugging in VS Code

1. Open the `tree_insert` folder in VS Code
2. Set breakpoints in the code by clicking in the left margin
3. Press F5 or go to Run → Start Debugging
4. The debugger will build and run the program

## Function
The `Insert(TreeNode* root, int value)` function adds a new value to a binary search tree (BST) using recursion.

### Step-by-Step Implementation Instructions

1. **Base Cases**:  
   - If the current node (`root`) is `nullptr`, create a new `TreeNode` with the given value and return it.  
   - If the current node's value (`root->data`) is equal to the value to insert, do not insert a duplicate; simply return the current node as-is.

2. **Recursive Case**:  
   - If the value to insert is **less than** the current node's value, recursively insert into the **left** subtree.
   - If the value to insert is **greater than** the current node's value, recursively insert into the **right** subtree.
   - Assign the result of the recursive call back to the appropriate child pointer (`root->left` or `root->right`).

3. **Return the (possibly updated) root**

## Example

The program builds this binary search tree using `Insert`:
```
       4
      / \
     2   6
    / \ / \
   1  3 5  7
```

### Expected Output
```
Inorder Traversal:
=============================
1 2 3 4 5 6 7
```

### Example Trace: Inserting value 3

```
Insert(4, 3):
├─ 3 < 4, so go left
├─ Insert(2, 3):
│  ├─ 3 > 2, so go right  
│  ├─ Insert(nullptr, 3):
│  │  └─ Base case: return new TreeNode(3)
│  └─ Assign result to right child
├─ Assign result to left child
└─ Return root (4)
```

## Memory Management

The program includes a recursive `Clear` function that properly deallocates all memory:
- Traverses the entire tree recursively
- Deletes nodes in post-order (children first, then parent)
- Prevents memory leaks
