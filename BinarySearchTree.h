//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 16-4.

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include <iostream>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType> {
private:
    BinaryNode<ItemType> *rootPtr;

protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    // Recursively finds where the given node should be placed and
    // inserts it in a leaf at that point.
    BinaryNode<ItemType> *insertInorder(BinaryNode<ItemType> *subTreePtr,
                                        BinaryNode<ItemType> *newNode);

    // Removes the given target value from the tree while maintaining a
    // binary search tree.
    BinaryNode<ItemType> *removeValue(BinaryNode<ItemType> *subTreePtr,
                                      const ItemType target,
                                      bool &success);

    // Removes a given node from a tree while maintaining a
    // binary search tree.
    BinaryNode<ItemType> *removeNode(BinaryNode<ItemType> *nodePtr);

    // Removes the leftmost node in the left subtree of the node
    // pointed to by nodePtr.
    // Sets inorderSuccessor to the value in this node.
    // Returns a pointer to the revised subtree.
    BinaryNode<ItemType> *removeLeftmostNode(BinaryNode<ItemType> *subTreePtr,
                                             ItemType &inorderSuccessor);

    // Returns a pointer to the node containing the given value,
    // or nullptr if not found.
    BinaryNode<ItemType> *findNode(BinaryNode<ItemType> *treePtr,
                                   const ItemType &target) const;

public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinarySearchTree();

    BinarySearchTree(const ItemType &rootItem);

    BinarySearchTree(const BinarySearchTree<ItemType> &tree);

    virtual ~BinarySearchTree();

    //------------------------------------------------------------
    // Public Methods Section.
    //------------------------------------------------------------
    bool isEmpty() const;

    int getHeight() const;

    int getNumberOfNodes() const;

    ItemType getRootData() const throw(PrecondViolatedExcep);

    void setRootData(const ItemType &newData) const throw(PrecondViolatedExcep);

    bool add(const ItemType &newEntry);

    bool remove(const ItemType &anEntry);

    void clear();

    ItemType getEntry(const ItemType &anEntry) const throw(NotFoundException);

    bool contains(const ItemType &anEntry) const;

    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse(void visit(ItemType &)) const;

    void inorderTraverse(void visit(ItemType &)) const;

    void postorderTraverse(void visit(ItemType &)) const;

    //------------------------------------------------------------
    // Overloaded Operator Section.
    //------------------------------------------------------------
    BinarySearchTree<ItemType> &operator=(const BinarySearchTree<ItemType> &rightHandSide);
}; // end BinarySearchTree


//////////////////////////////////////////////////////////////
//
//      Protected Utility Methods Section
//
//////////////////////////////////////////////////////////////

template<class ItemType>
BinaryNode<ItemType> *BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType> *subTreePtr,
                                                                BinaryNode<ItemType> *newNodePtr) {
    //TODO

    if (subTreePtr == NULL) {
        subTreePtr = newNodePtr;
        return subTreePtr;
    } else {
        if (subTreePtr->getItem() > newNodePtr->getItem()) {
            subTreePtr->setLeftChildPtr(insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr));
        } else {
            subTreePtr->setRightChildPtr(insertInorder(subTreePtr->getRightChildPtr(), newNodePtr));
        }
        return subTreePtr;
    }
}  // end insertInorder

template<class ItemType>
BinaryNode<ItemType> *BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType> *subTreePtr,
                                                              const ItemType target,
                                                              bool &success) {
    //TODO
    if (subTreePtr->getItem() == target) {
        success = true;
        subTreePtr = removeNode(subTreePtr);
        return subTreePtr;
    } else if (subTreePtr != NULL) {
        if (subTreePtr->getItem() > target && subTreePtr->getLeftChildPtr() != NULL) {
            subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
        } else {
            if(subTreePtr->getRightChildPtr() != NULL) {
                subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
            }
        }
        return subTreePtr;
    } else {
        success = false;
        return NULL;
    }
}  // end removeValue

template<class ItemType>
BinaryNode<ItemType> *BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType> *nodePtr) {
    // Case 1) Node is a leaf - it is deleted
    // Case 2) Node has one child - parent adopts child
    // Case 3) Node has two children:
    //               Traditional implementation: Find successor node.
    //               Alternate implementation: Find successor value and replace node's value;
    //                  alternate does not need pass-by-reference
    if (nodePtr->isLeaf()) {
        delete nodePtr;
        return (nodePtr = nullptr); // Assign and return (student maybe should have separate statements)
    }
    else if (nodePtr->getLeftChildPtr() == nullptr)  // Has rightChild only
    {
        BinaryNode<ItemType> *nodeToConnectPtr = nodePtr->getRightChildPtr();
        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;
    }
    else if (nodePtr->getRightChildPtr() == nullptr) // Has left child only
    {
        BinaryNode<ItemType> *nodeToConnectPtr = nodePtr->getLeftChildPtr();
        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;
    }
    else                                             // Has two children
    {
        // Traditional way to remove a value in a node with two children
        ItemType newNodeValue;
        nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;

        // Alernative way to remove a value in a node with two children; does not require pass-by-reference.
        // We need to check whether this right child has a left child.
        // This is similar to the base case in "findSuccessorValue" but we need to remove the
        // special case where the right child *is* the inorder successor
        /*
              BinaryNode<ItemType>* myRightChildPtr = nodePtr->getRightChildPtr();
              BinaryNode<ItemType>* myLeftGrandChildPtr = myRightChildPtr->getLeftChildPtr();

              // Special case - right child is successor
              if (myLeftGrandChildPtr == nullptr)
              {
                 nodePtr->setItem(myRightChildPtr->getItem());
                 nodePtr->setRightChildPtr(removeNode(myRightChildPtr));
                 return nodePtr;
              }
              else
              {
                 // Now we can recurse
                 nodePtr->setItem(findSuccessorValue(nodePtr->getRightChildPtr()));
                 return nodePtr;
              }  // end if
        */
    }  // end if
}  // end removeNode

template<class ItemType>
BinaryNode<ItemType> *BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType> *nodePtr,
                                                                     ItemType &inorderSuccessor) {
    if (nodePtr->getLeftChildPtr() == nullptr) {
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    }
    else {
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
        return nodePtr;
    }  // end if
}  // end removeLeftmostNode

/*
template<class ItemType>
ItemType BinarySearchTree<ItemType>::findSuccessorValue(BinaryNode<ItemType>* subTreePtr)
{
   BinaryNode<ItemType>* myLeftChildPtr = subTreePtr->getLeftChildPtr();
   if (myLeftChildPtr->getLeftChildPtr() == nullptr) {
      ItemType nodeItemValue = myLeftChildPtr->getItem();
      subTreePtr->setLeftChildPtr(removeNode(myLeftChildPtr));
      return nodeItemValue;
   }
   else
   {
      return findSuccessorValue(subTreePtr->getLeftChildPtr());
   }  // end if
}  // end findSuccessorValue
*/

// Override findNode because now we can use a binary search:
template<class ItemType>
BinaryNode<ItemType> *BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType> *subTreePtr,
                                                           const ItemType &target) const {
    //TODO
    if (subTreePtr == NULL) {
        return NULL;
    }

    if (subTreePtr->getItem() == target) {
        return subTreePtr;
    } else if (subTreePtr->getItem() > target) {
        subTreePtr = findNode(subTreePtr->getLeftChildPtr(), target);
    } else if (subTreePtr->getItem() < target) {
        subTreePtr = findNode(subTreePtr->getRightChildPtr(), target);
    } else {
        return NULL;
    }
    return subTreePtr;
}  // end findNode


//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr) {
}  // end default constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType &rootItem) {
    rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}  // end constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType> &treePtr) {
    rootPtr = this->copyTree(treePtr.rootPtr); // Call inherited method
}  // end copy constructor

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
    this->destroyTree(rootPtr); // Call inherited method
}  // end destructor


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}  // end isEmpty

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
    return this->getHeightHelper(rootPtr); // Call inherited method
}  // end getHeight

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
    return this->getNumberOfNodesHelper(rootPtr); // Call inherited method
}  // end getNumberOfNodes

template<class ItemType>
void BinarySearchTree<ItemType>::clear() {
    this->destroyTree(rootPtr); // Call inherited method
    rootPtr = nullptr;
}  // end clear

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcep) {
    if (isEmpty())
        throw PrecondViolatedExcep("getRootData() called with empty tree.");

    return rootPtr->getItem();
}  // end getRootData

// Must override setRootData to disable its affect:
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType &newItem) const throw(PrecondViolatedExcep) {
    throw PrecondViolatedExcep("Cannot change root value in a BST!");
}  // end setRootData

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType &newData) {
    BinaryNode<ItemType> *newNodePtr = new BinaryNode<ItemType>(newData);
    rootPtr = insertInorder(rootPtr, newNodePtr);

    return true;
}  // end add

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType &target) {
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, target, isSuccessful);
    return isSuccessful;
}  // end remove

// Override getEntry to use our improved findNode:
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType &anEntry) const throw(NotFoundException) {
    BinaryNode<ItemType> *nodeWithEntry = findNode(rootPtr, anEntry);
    if (nodeWithEntry == nullptr)
        throw NotFoundException("Entry not found in tree.");
    else
        return nodeWithEntry->getItem();
}  // end getEntry

// Override contains to use our improved findNode:
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType &anEntry) const {

    return findNode(rootPtr, anEntry);  // nullptr is same as false
}  // end contains


//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType &)) const {
    this->preorder(visit, rootPtr); // Call inherited method
}  // end preorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType &)) const {
    this->inorder(visit, rootPtr); // Call inherited method
}  // end inorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType &)) const {
    this->postorder(visit, rootPtr); // Call inherited method
}  // end postorderTraverse


//////////////////////////////////////////////////////////////
//      Overloaded Operator
//////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType> &BinarySearchTree<ItemType>::
operator=(const BinarySearchTree<ItemType> &rightHandSide) {
    if (!isEmpty())
        clear();
    this = copyTree(&rightHandSide); // Call inherited method

    return *this;
}  // end operator=


#endif
