/******************************************************************************

File Name:    BST.hpp
Description:  This program creates a class called BST, creating a binary
              tree, allowing us to perform many functions such as inserting
              and finding BSTNodes

******************************************************************************/


#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>


/******************************************************************************
class BST

Description: Creates a BST, or binary search tree, which will allow us to
    insert or find BSTNodes

Data Fields:
    root (BSTNode<Data>*) - the root of our BST
    isize (unsigned int)  - the number of BSTNodes in our tree

Public functions:
    BST     - constructor for BST
    ~BST    - desctructor for BST
    insert  - inserts an item into our BST
    find    - finds a BSTNode in our BST
    size    - gives the size of our BST
    empty   - checks to see if BST is empty
    begin   - creates iterator pointing to the first item in the BST
    end     - creates iterator pointing past the last item in the BST
    inorder - performs an inorder traversal of our BST
******************************************************************************/
template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;


  /****************************************************************************
  Function Name:  BST
  Purpose:        This function initializes an empty BST
  Description:    This function initializes an empty BST by creating a null
                  root and setting isize to zero
  Result:         An empty BST is created
  ****************************************************************************/
  BST() : root(nullptr), isize(0) {  }


  /****************************************************************************
  Function Name:  ~BST
  Purpose:        This function deconstructs our BST
  Description:    This function unitializes our BST by calling our deleteAll
                  function starting at root, thus deleting every node in our
                  BST
  Result:         An empty BST
  ****************************************************************************/
  virtual ~BST() {
    deleteAll(root);
  }


  /****************************************************************************
  Function Name:  insert
  Purpose:        This function inserts an item into our BST
  Description:    This function creates a BSTNode which will contain the data
                  from our parameter. It checks to see if a root exists. If it
                  does, it then checks to see if it is inserted into the left
                  subtree or the right subtree. If the BSTNode already exists,
                  then item is not inserted. It then increases isize
  Input:          item: the data of the BSTNode we are attempting to insert 
                  into our tree
  Result:         true if the insert was performed successfully
                  false if the insert was performed unsuccessfully
  ****************************************************************************/
  virtual bool insert(const Data& item) {

    /* Variable to indicate whether insertiong was successful or not */
    bool inserted = false;

    BSTNode<Data>* current = root;
    BSTNode<Data>* insertingNode = new BSTNode<Data> (item);

    /* If statement is executed when current does not exist */
    if (!current) {
      root = insertingNode;
      inserted = true;
    }

    /* While loop is executed while current exists */
    while (current) {

      /* If statement is executed when data of current is less than item */
      if (current -> data < item) {

        /* If statement is executed when current's right child doesn't exist */
        if (!current -> right) {

          /* We set insertingNode as current's right child and set our variable
           * to true */
          current -> right = insertingNode;
          current -> right -> parent = current;
          inserted = true;
          break;
        }

        else

          /* Recursion is used to traverse down the right subtree */
          current = current -> right;
      }

      /* Else if statement is executed when data of current is greater than
       * item */
      else if (item < current -> data) {

        /* If statement is executed when current's left child doesn't exist */
        if (!current -> left) {

          /* We set insertingNode as current's left child and set our variable
           * to true */
          current -> left = insertingNode;
          current -> left -> parent = current;
          inserted = true;
          break;
        }

        else

          /* Recursion is used to traverse down the left subtree */
          current = current -> left;
      }

      else
        break;
    }

    /* If statement is executed when insertion is successful */
    if (inserted)
      ++isize;

    else

      /* We free the node created since it was not inserted into our BST */
      delete insertingNode;

    return inserted;
  }


  /****************************************************************************
  Function Name:  find
  Purpose:        This function finds a BSTNode in our BST
  Description:    This function creates a temporary BSTNode for tracking our
                  current location. It then comparies the value of item to the
                  data of our current node. It then goes left or right whether
                  the item is greater or less than the data of current.
  Input:          item: the data of the BSTNode we are attempting to find
  Result:         Returns an iterator pointing to the BSTNode, or pointing past
                  the last node in the BST if not found
  ****************************************************************************/
  iterator find(const Data& item) const {
    BSTNode<Data>* current = root;

    /* If statement is executed when current does not exist */
    if (!current)
      return end();

    /* While loop is executed when current exists */
    while (current) {

      /* If statement is executed when item is less that the data of current */
      if (item < current -> data) {

        /* If statement is executed when current's left childs doesn't exist */
        if (!current -> left)
          return end();

        else

          /* Recursion is used to traverse down the left subtree */
          current = current -> left;
      }

      /* Else if statement is executed when the data of current is less than
       * item */
      else if (current -> data < item) {

        /* If statement is executed when current's right child doesn't exist */
        if (!current -> right)
          return end();

        else

          /* Recursion is used to traverse down the right subtree */
          current = current -> right;

      }

      else
        break;
    }
      return typename BST<Data>::iterator(current);
  }


  /****************************************************************************
  Function Name:  size
  Purpose:        This function returns the number of items in our BST
  Description:    This function access our data field isize and return its
                  value
  Result:         Returns the number of BSTNodes in our BST
  ****************************************************************************/
  unsigned int size() const {
    return isize;
  }


  /****************************************************************************
  Function Name:  empty
  Purpose:        This function checks if our BST is empty
  Description:    This function checks if root exists. If it does, then our BST
                  is not empty
  Result:         true if our BST is empty
                  false if our BST is not empty
  ****************************************************************************/
  bool empty() const {

    /* If statement is executed when root exists */
    if (root)
      return false;

    return true;
  }


  /****************************************************************************
  Function Name:  begin
  Purpose:        This function creates an iterator pointing to the first item
                  in the BST
  Description:    This function calls upon our aliased iterator and our first
                  function to find the first item in the BST
  Result:         Returns an iterator pointing to the first item in the BST
  ****************************************************************************/
  iterator begin() const {
    return typename BST<Data>::iterator(first(root));
  }


  /****************************************************************************
  Function Name:  end
  Purpose:        This function creates an iterator pointing past the last item
                  in the BST
  Result:         Returns an iterator pointing past the last item in the BST
  ****************************************************************************/
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }


  /****************************************************************************
  Function Name:  inorder
  Purpose:        This function performs an inorder traversal of our BST
  Description:    This function calls upon our private function, inorder, to
                  help perform an inorder traversal
  Result:         An inorder traversal of our BST
  ****************************************************************************/
  void inorder() const {
    inorder(root);
  }

private:


  /****************************************************************************
  Function Name:  inorder
  Purpose:        This function performs an inorder traversal of our BST,
                  printing out each node
  Description:    This function first checks to see if our starting BSTNode
                  exists. It then checks to see if a left child exists. After
                  printing the current node, it checks to see if a right child
                  exists
  Input:          n:  the BSTNode we start our inorder traversal from
  Result:         An inorder traversal of our BST, printing out the data of
                  each node in ascending order
  ****************************************************************************/
  void inorder(BSTNode<Data>* n) const {

    /* If statement is executed when n exists */
    if (n) {

      /* If statement is executed when n's left child exists */
      if (n -> left)

        /* Recursion is used to go down the left subtree */
        inorder(n -> left);

      std::cout << *n << std::endl;

      /* If statement is executed when n's right child exists */
      if (n -> right)

        /* Recursion is used to go down the left subtree */
        inorder(n->right);
    }
  }


  /****************************************************************************
  Function Name:  first
  Purpose:        This function finds the first element of the BST
  Description:    This function first checks to see if root exists. If it does,
                  it then checks to see if root's left child exists
  Input:          root: the root of our BST
  Result:         Returns 0 if root does not exist
                  Returns the first element of the BST
  ****************************************************************************/
  static BSTNode<Data>* first(BSTNode<Data>* root) {

    /* If statement is executed when root doesn't exist */
    if(!root)
      return 0;

    /* While loop is executed when root's left child exists */
    while(root -> left) {

      /* Recursion is used to go down the left subtree */
      root = root -> left;
    }

    return root;
  }


  /****************************************************************************
  Function Name:  deleteAll
  Purpose:        This function deletes nodes in our BST
  Description:    This function performs a postorder traversal, deleting nodes
                  in our BST. It first checks to see if n exists. It then
                  checks to see if left child of n exists, followed by checking
                  to see if right child of n exists. It then deletes n
  Input:          n:  then current node we are on
  Result:         Deletes all of the the nodes in a BST starting from a
                  specific node
  ****************************************************************************/
  static void deleteAll(BSTNode<Data>* n) {

    /* If statement is executed when n exists */
    if (n) {

      /* If statement is executed when n's left child exists */
      if (n -> left)

        /* Recursion is used to go down the left subtree */
        deleteAll(n -> left);

      /* If statement is executed when n's right child exists */
      if (n -> right)

        /* Recursion is used to go down the right subtree */
        deleteAll(n -> right);

      delete n;
    }
  }
};


#endif //BST_HPP

