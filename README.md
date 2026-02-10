[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/fGmzpwgf)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=22604258&assignment_repo_type=AssignmentRepo)
# Lab 5

## Directions

You will be finishing the implementation of the List ADT as a linked list. The `List` abstract class is already given to you, along with the header file for the `LinkedList` class, and a skeleton of its implementation file. Many of the operations are already done for you. Your task is to complete the remaining three methods based off of our algorithm discussion in lecture: `insert`, `remove`, and `copy`.

You are also in charge of writing your own driver program to test your `LinkedList` class. Be thorough with your testing by checking all the operations in different scenarios and with various data types.

## Notes

- If you need to access the `length` attribute in your `LinkedList` class, you need to write it as `this->length`
- All nodes are to be treated as dynamic, meaning you have to use the `new` and `delete` operators with them
    + For example, to create a node, you could do
    ```C++
    Node* myNode = new Node;
    ```
- There are some operations that need to consider if it's invalid for it to be called: in those scenarios, make sure to `throw` a `string` exception explaining the error, like this
```C++
throw string("message goes here");
```
- The `<<` stream insertion operator has been overloaded for the `LinkedList` class, meaning you can use `cout` on your `LinkedList` object to print out the nodes inside
- When testing your copy algorithm, make sure to call it through both the copy constructor and the overloaded `=` assignment operator
    + It would also be wise to check the linked list object you used to copy from to ensure there are no unintended consequences from the copy operation (i.e., sharing data)
