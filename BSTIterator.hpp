/******************************************************************************

File Name:    BSTIterator.hpp
Description:  This program creates a class called BSTIterator, creating an
              iterator which will go through the elements in our BST
              
******************************************************************************/


#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>


/******************************************************************************
class BSTIterator

Description: Creates a BSTIterator which will allow us to go through the
    elements in our BST

Data Fields:
    curr (BSTNode<Data>*) - the current BSTNode we are working with

Public functions:
    BSTIterator - constructor for our BSTIterator class
    operator*   - overloaded operator using the * symbol
    operator++  - overloaded operator using the ++ symbol
    operator==  - overloaded operator using the == symbol
    operator!=  - overloaded operator using the != symbol
******************************************************************************/
template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

public:


  /****************************************************************************
  Function Name:  BSTIterator
  Purpose:        This function is the constructor for our BSTIterator
  Description:    This function takes in a BSTNode as a parameter and
                  initializes the current BSTNode in the BSTIterator
  Input:          curr: the current BSTNode we are working on
  Result:         We set the current node's curr to equal the curr in our
                  parameter
  ****************************************************************************/
  BSTIterator(BSTNode<Data>* curr) {
    this -> curr = curr;
  }


  /****************************************************************************
  Function Name:  operator*
  Purpose:        This function dereferences the current BSTNode in the
                  BSTIterator
  Description:    This function finds the data within curr and returns it, thus
                  dereferencing the node in the iterator
  Result:         Returns the data in curr
  ****************************************************************************/
  Data operator*() const {
    return curr -> data;
  }


  /****************************************************************************
  Function Name:  operator++
  Purpose:        This function pre-increments our current node
  Description:    This function calls our successor method in BSTNode.hpp to
                  increment our iterator
  Result:         Returns the data of our current node
  ****************************************************************************/
  BSTIterator<Data>& operator++() {
    curr = curr -> successor();
    return *this;
  }


  /****************************************************************************
  Function Name:  operator++
  Purpose:        This function post-increments our current node
  Description:    This function creates an iterator and increments the data of
                  this
  Input:          an integer value
  Result:         Returns our iterator before we increment
  ****************************************************************************/
  BSTIterator<Data> operator++(int) {
    BSTIterator before = BSTIterator(curr);
    ++(*this);
    return before;
  }


  /****************************************************************************
  Function Name:  operator==
  Purpose:        This function overloads our == operator
  Description:    This function overloads our == operator to compare two nodes
  Input:          other:  the iterator from which we are comparing nodes
  Result:         true if the nodes are equal
                  false if the nodes are not equal
  ****************************************************************************/
  bool operator==(BSTIterator<Data> const & other) const {
    return curr == other.curr;
  }


  /****************************************************************************
  Function Name:  operator!=
  Purpose:        This function overloads our != operator
  Description:    This function overloads our != operator to compare two nodes
  Input:          other:  the iterator from which we are comparing nodes
  Result:         true if the nodes are not equal
                  false if the nodes are equal
  ****************************************************************************/
  bool operator!=(BSTIterator<Data> const & other) const {
    return curr != other.curr;
  }
};

#endif //BSTITERATOR_HPP
