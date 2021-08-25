/******************************************************************************

File Name:    BSTNode.hpp
Description:  This program creates a class called BSTNode, creating a node
              to insert into our binary search tree
              
******************************************************************************/


#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>


/******************************************************************************
class BSTNode

Description: Creates a BSTNode, or binary search tree node, which will allow
    us to find a node's successor, if one exists, and print out the data of
    a specific node

Data Fields:
    left (BSTNode<Data>*)    - the left child of a node
    right (BSTNode<Data>*)   - the right child of a node
    parent (BSTNode<Data>*)  - the parent of a node
    data (Data const)        - the data contained within the node

Public functions:
    BSTNode   - constructor for our BSTNode class
    successor - finds the successor of a BSTNode, if one exists
******************************************************************************/
template<typename Data>
class BSTNode {

public:


  /****************************************************************************
  Function Name:  BST
  Purpose:        This function initializes a node
  Description:    This function initializes a node by setting the data of our
                  node to our given parameter and setting the left, right, and
                  parent nodes to nullptr
  Input:          d:  the data value of our created BSTNode
  Result:         A BSTNode with no left, right, or parent node is created
  ****************************************************************************/
  BSTNode(const Data & d) : data(d) {
    left = right = parent = nullptr;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.


  /****************************************************************************
  Function Name:  successor
  Purpose:        This function finds the successor of a BSTNode, if one exists
  Description:    This function first checks to see if a right child for the
                  current node exists. If so, then it goes to that node and
                  keeps traversing down the left subtree until we find the last
                  node, thus finding its successor. If no right child exists,
                  we check to see if a parent exists we keep traversing up the
                  tree until we find a node greater than our original node,
                  thus finding its successor
  Result:         Returns the successor of a BSTNode
                  Returns nullptr of no successor exists for a BSTNode
  ****************************************************************************/
  BSTNode<Data>* successor() {
    BSTNode<Data>* current = this;

    /* If statement is executed when right child exists */
    if (right) {
      current = current -> right;

      /* While loop is executed when current's left child exists */
      while (current -> left)

        /* We traverse down the left subtree */
        current = current -> left;

      return current;
    }

    /* Else if statement is executed when parent exists */
    else if (parent) {
      BSTNode<Data>* currentParent = parent;

      /* While loop is executed when the data of currentParent is less than
       * the data of current */
      while (currentParent -> data < current -> data) {

        /* If statement is executed when the parent of currentParent does not
         * exist */
        if (!currentParent -> parent)
          return nullptr;

        /* We traverse up the tree */
        currentParent = currentParent -> parent;
      }
      return currentParent;
    }
    return nullptr;
  }
}; 


/******************************************************************************
Function Name:  operator<<
Purpose:        This function overloads the << operator
Description:    This function overloads the << operator by making it pring out
                the data of a node. It prints out its address, its left, right,
                and parent node, and the data within the node
Input:          stm - the ostream we are printing this out on
                n   - the node we are using our operator on
Result:         The data of a node is printed
******************************************************************************/
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
