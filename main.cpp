//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "BinarySearchTree.h"  // ADT binary tree operations
#include <iostream>
#include <string>

using namespace std;

void display(string &anItem) {
    cout << "Displaying item - " << anItem << endl;
}  // end display

void check(bool success) {
    if (success)
        cout << "Done." << endl;
    else
        cout << " Entry not in tree." << endl;
}  // end check

int main() {
    BinarySearchTree<string> *tree1Ptr = new BinarySearchTree<string>();

    tree1Ptr->add("10");
    tree1Ptr->add("20");
    tree1Ptr->add("30");
    tree1Ptr->add("40");
    tree1Ptr->add("50");
    tree1Ptr->add("60");
    tree1Ptr->add("70");
    tree1Ptr->add("80");

    cout << "Tree 1 Preorder: Should be 10 20 30 40 50 60 70 80\n";
    tree1Ptr->preorderTraverse(display);

    cout << "Tree 1 Inorder: Should be 10 20 30 40 50 60 70 80\n";
    tree1Ptr->inorderTraverse(display);

    cout << "Tree 1 Postorder: Should be 80 70 60 50 40 30 20 10\n";
    tree1Ptr->postorderTraverse(display);

    cout << "Tree 1 height: " << tree1Ptr->getHeight() << "; should be 8." << endl;
    cout << "Tree 1 number of nodes: " << tree1Ptr->getNumberOfNodes() << "; should be 8." << endl;

    cout << "Remove the leaf 80: ";
    bool success = tree1Ptr->remove("80");
    check(success);

    cout << "Try to remove the leaf 80 again: ";
    success = tree1Ptr->remove("80");
    check(success);

    cout << "Remove the node 40 that has only a right child: ";
    success = tree1Ptr->remove("40");
    check(success);

    cout << "Tree 1 Preorder: Should be 10 20 30 50 60 70\n";
    tree1Ptr->preorderTraverse(display);

    cout << "Tree 1 Inorder: Should be 10 20 30 50 60 70\n";
    tree1Ptr->inorderTraverse(display);

    cout << "Tree 1 Postorder: Should be 70 60 50 30 20 10\n";
    tree1Ptr->postorderTraverse(display);

    cout << "Tree 1 height: " << tree1Ptr->getHeight() << "; should be 6." << endl;
    cout << "Tree 1 number of nodes: " << tree1Ptr->getNumberOfNodes() << "; should be 6." << endl;

    cout << "Remove the root 10 (has a right subtree): ";
    success = tree1Ptr->remove("10");
    check(success);

    // 20
    //   \
   //   30
    //     \
   //     50
    //       \
   //       60
    //         \
   //         70

    cout << "Tree 1 Preorder: Should be 20 30 50 60 70\n";
    tree1Ptr->preorderTraverse(display);

    cout << "Tree 1 Inorder: Should be 20 30 50 60 70\n";
    tree1Ptr->inorderTraverse(display);

    cout << "Tree 1 Postorder: Should be 70 60 50 30 20\n";
    tree1Ptr->postorderTraverse(display);

    cout << "Tree 1 height: " << tree1Ptr->getHeight() << "; should be 5." << endl;
    cout << "Tree 1 number of nodes: " << tree1Ptr->getNumberOfNodes() << "; should be 5." << endl;
    cout << endl;
    //===========================
    BinarySearchTree<string> *tree2Ptr = new BinarySearchTree<string>();

    tree2Ptr->add("40");
    tree2Ptr->add("20");
    tree2Ptr->add("10");
    tree2Ptr->add("30");
    tree2Ptr->add("60");
    tree2Ptr->add("50");
    tree2Ptr->add("70");
    tree2Ptr->add("80");

    //        40
    //     /     \
   //    20     60
    //   /  \   /  \
   //  10  30 50  70
    //               \
   //               80

    cout << "Tree 2 Preorder: Should be 40 20 10 30 60 50 70 80\n";
    tree2Ptr->preorderTraverse(display);

    cout << "Tree 2 Inorder: Should be 10 20 30 40 50 60 70 80\n";
    tree2Ptr->inorderTraverse(display);

    cout << "Tree 2 Postorder: Should be 10 30 20 50 80 70 60 40\n";
    tree2Ptr->postorderTraverse(display);

    cout << "Tree 2 height: " << tree2Ptr->getHeight() << "; should be 4." << endl;
    cout << "Tree 2 number of nodes: " << tree2Ptr->getNumberOfNodes() << "; should be 8." << endl;

    cout << "Remove the node 70 that has only a right child: ";
    success = tree2Ptr->remove("70");
    check(success);
    //        40
    //     /     \
   //    20     60
    //   /  \   /  \
   //  10  30 50  80

    cout << "Tree 2 Preorder: Should be 40 20 10 30 60 50 80\n";
    tree2Ptr->preorderTraverse(display);

    cout << "Tree 2 Inorder: Should be 10 20 30 40 50 60 80\n";
    tree2Ptr->inorderTraverse(display);

    cout << "Tree 2 Postorder: Should be 10 30 20 50 80 60 40\n";
    tree2Ptr->postorderTraverse(display);

    cout << "Tree 2 height: " << tree2Ptr->getHeight() << "; should be 3." << endl;
    cout << "Tree 2 number of nodes: " << tree2Ptr->getNumberOfNodes() << "; should be 7." << endl;

    cout << "Remove the node 60 that has two children: ";
    success = tree2Ptr->remove("60");
    check(success);
    //        40
    //     /     \
   //    20     80
    //   /  \   /
    //  10  30 50

    cout << "Tree 2 Preorder: Should be 40 20 10 30 80 50 \n";
    tree2Ptr->preorderTraverse(display);

    cout << "Tree 2 Inorder: Should be 10 20 30 40 50 80\n";
    tree2Ptr->inorderTraverse(display);

    cout << "Tree 2 Postorder: Should be 10 30 20 50 80 40\n";
    tree2Ptr->postorderTraverse(display);

    cout << "Tree 2 height: " << tree2Ptr->getHeight() << "; should be 3." << endl;
    cout << "Tree 2 number of nodes: " << tree2Ptr->getNumberOfNodes() << "; should be 6." << endl;

    cout << "Remove the leaf 10: ";
    success = tree2Ptr->remove("10");
    check(success);
    //        40
    //     /     \
   //    20     80
    //      \   /
    //      30 50

    cout << "Tree 2 Preorder: Should be 40 20 30 80 50 \n";
    tree2Ptr->preorderTraverse(display);

    cout << "Tree 2 Inorder: Should be 20 30 40 50 80\n";
    tree2Ptr->inorderTraverse(display);

    cout << "Tree 2 Postorder: Should be 30 20 50 80 40\n";
    tree2Ptr->postorderTraverse(display);

    cout << "Tree 2 height: " << tree2Ptr->getHeight() << "; should be 3." << endl;
    cout << "Tree 2 number of nodes: " << tree2Ptr->getNumberOfNodes() << "; should be 5." << endl;

    cout << "Remove the root 40: ";
    success = tree2Ptr->remove("40");
    check(success);
    //      50
    //     /  \
   //    20   80
    //      \
   //      30

    cout << "Tree 2 Preorder: Should be 50 20 30 80\n";
    tree2Ptr->preorderTraverse(display);

    cout << "Tree 2 Inorder: Should be 20 30 50 80\n";
    tree2Ptr->inorderTraverse(display);

    cout << "Tree 2 Postorder: Should be 30 20 80 50\n";
    tree2Ptr->postorderTraverse(display);

    cout << "Tree 2 height: " << tree2Ptr->getHeight() << "; should be 3." << endl;
    cout << "Tree 2 number of nodes: " << tree2Ptr->getNumberOfNodes() << "; should be 4." << endl;

    cout << "\nTesting overloaded assignment operator: \n";
    cout << "\nRecall tree1Ptr: \n";

    cout << "Tree 1 Preorder: Should be 20 30 50 60 70\n";
    tree1Ptr->preorderTraverse(display);

    cout << "Tree 1 Inorder: Should be 20 30 50 60 70\n";
    tree1Ptr->inorderTraverse(display);

    cout << "Tree 1 Postorder: Should be 70 60 50 30 20\n";
    tree1Ptr->postorderTraverse(display);

    cout << "Tree 1 height: " << tree1Ptr->getHeight() << "; should be 5." << endl;
    cout << "Tree 1 number of nodes: " << tree1Ptr->getNumberOfNodes() << "; should be 5." << endl;
    cout << endl;

    cout << "\nAfter assigning Tree 2 to Tree 3, we have: \n";
    BinarySearchTree<string> tree3 = *tree2Ptr;
    BinarySearchTree<string> *tree3Ptr = &tree3;

    cout << "Tree 2 Preorder: Should be 50 20 30 80\n";
    tree2Ptr->preorderTraverse(display);

    cout << "Tree 2 Inorder: Should be 20 30 50 80\n";
    tree2Ptr->inorderTraverse(display);

    cout << "Tree 2 Postorder: Should be 30 20 80 50\n";
    tree2Ptr->postorderTraverse(display);

    cout << "Tree 2 height: " << tree2Ptr->getHeight() << "; should be 3." << endl;
    cout << "Tree 2 number of nodes: " << tree2Ptr->getNumberOfNodes() << "; should be 4." << endl << endl;

    cout << "Tree 3 Preorder: Should be 50 20 30 80\n";
    tree3Ptr->preorderTraverse(display);

    cout << "Tree 3 Inorder: Should be 20 30 50 80\n";
    tree3Ptr->inorderTraverse(display);

    cout << "Tree 3 Postorder: Should be 30 20 80 50\n";
    tree3Ptr->postorderTraverse(display);

    cout << "Tree 3 height: " << tree3Ptr->getHeight() << "; should be 3." << endl;
    cout << "Tree 3 number of nodes: " << tree3Ptr->getNumberOfNodes() << "; should be 4." << endl;
    cout << endl;


    cout << endl << "Change Tree 2 by removing 50" << endl;;
    tree2Ptr->remove("50");

    cout << "Tree 2 Preorder: Should be 80 20 30\n";
    tree2Ptr->preorderTraverse(display);

    cout << "Tree 2 Inorder: Should be 20 30 80\n";
    tree2Ptr->inorderTraverse(display);

    cout << "Tree 2 Postorder: Should be 30 20 80 \n";
    tree2Ptr->postorderTraverse(display);

    cout << "Tree 2 height: " << tree2Ptr->getHeight() << "; should be 2." << endl;
    cout << "Tree 2 number of nodes: " << tree2Ptr->getNumberOfNodes() << "; should be 3." << endl << endl;

    cout << "Tree 3 should be unchanged:" << endl;;
    cout << "Tree 3 Preorder: Should be 50 20 30 80\n";
    tree3Ptr->preorderTraverse(display);

    cout << "Tree 3 Inorder: Should be 20 30 50 80\n";
    tree3Ptr->inorderTraverse(display);

    cout << "Tree 3 Postorder: Should be 30 20 80 50\n";
    tree3Ptr->postorderTraverse(display);

    cout << "Tree 3 height: " << tree3Ptr->getHeight() << "; should be 3." << endl;
    cout << "Tree 3 number of nodes: " << tree3Ptr->getNumberOfNodes() << "; should be 4." << endl;

    return 0;
}  // end main
/*
 Tree 1 Preorder: Should be 10 20 30 40 50 60 70 80
 Displaying item - 10
 Displaying item - 20
 Displaying item - 30
 Displaying item - 40
 Displaying item - 50
 Displaying item - 60
 Displaying item - 70
 Displaying item - 80
 Tree 1 Inorder: Should be 10 20 30 40 50 60 70 80
 Displaying item - 10
 Displaying item - 20
 Displaying item - 30
 Displaying item - 40
 Displaying item - 50
 Displaying item - 60
 Displaying item - 70
 Displaying item - 80
 Tree 1 Postorder: Should be 80 70 60 50 40 30 20 10
 Displaying item - 80
 Displaying item - 70
 Displaying item - 60
 Displaying item - 50
 Displaying item - 40
 Displaying item - 30
 Displaying item - 20
 Displaying item - 10
 Tree 1 height: 8; should be 8.
 Tree 1 number of nodes: 8; should be 8.
 Remove the leaf 80: Done.
 Try to remove the leaf 80 again:  Entry not in tree.
 Remove the node 40 that has only a right child: Done.
 Tree 1 Preorder: Should be 10 20 30 50 60 70
 Displaying item - 10
 Displaying item - 20
 Displaying item - 30
 Displaying item - 50
 Displaying item - 60
 Displaying item - 70
 Tree 1 Inorder: Should be 10 20 30 50 60 70
 Displaying item - 10
 Displaying item - 20
 Displaying item - 30
 Displaying item - 50
 Displaying item - 60
 Displaying item - 70
 Tree 1 Postorder: Should be 70 60 50 30 20 10
 Displaying item - 70
 Displaying item - 60
 Displaying item - 50
 Displaying item - 30
 Displaying item - 20
 Displaying item - 10
 Tree 1 height: 6; should be 6.
 Tree 1 number of nodes: 6; should be 6.
 Remove the root 10 (has a right subtree): Done.
 Tree 1 Preorder: Should be 20 30 50 60 70
 Displaying item - 20
 Displaying item - 30
 Displaying item - 50
 Displaying item - 60
 Displaying item - 70
 Tree 1 Inorder: Should be 20 30 50 60 70
 Displaying item - 20
 Displaying item - 30
 Displaying item - 50
 Displaying item - 60
 Displaying item - 70
 Tree 1 Postorder: Should be 70 60 50 30 20
 Displaying item - 70
 Displaying item - 60
 Displaying item - 50
 Displaying item - 30
 Displaying item - 20
 Tree 1 height: 5; should be 5.
 Tree 1 number of nodes: 5; should be 5.
 
 Tree 2 Preorder: Should be 40 20 10 30 60 50 70 80
 Displaying item - 40
 Displaying item - 20
 Displaying item - 10
 Displaying item - 30
 Displaying item - 60
 Displaying item - 50
 Displaying item - 70
 Displaying item - 80
 Tree 2 Inorder: Should be 10 20 30 40 50 60 70 80
 Displaying item - 10
 Displaying item - 20
 Displaying item - 30
 Displaying item - 40
 Displaying item - 50
 Displaying item - 60
 Displaying item - 70
 Displaying item - 80
 Tree 2 Postorder: Should be 10 30 20 50 80 70 60 40
 Displaying item - 10
 Displaying item - 30
 Displaying item - 20
 Displaying item - 50
 Displaying item - 80
 Displaying item - 70
 Displaying item - 60
 Displaying item - 40
 Tree 2 height: 4; should be 4.
 Tree 2 number of nodes: 8; should be 8.
 Remove the node 70 that has only a right child: Done.
 Tree 2 Preorder: Should be 40 20 10 30 60 50 80
 Displaying item - 40
 Displaying item - 20
 Displaying item - 10
 Displaying item - 30
 Displaying item - 60
 Displaying item - 50
 Displaying item - 80
 Tree 2 Inorder: Should be 10 20 30 40 50 60 80
 Displaying item - 10
 Displaying item - 20
 Displaying item - 30
 Displaying item - 40
 Displaying item - 50
 Displaying item - 60
 Displaying item - 80
 Tree 2 Postorder: Should be 10 30 20 50 80 60 40
 Displaying item - 10
 Displaying item - 30
 Displaying item - 20
 Displaying item - 50
 Displaying item - 80
 Displaying item - 60
 Displaying item - 40
 Tree 2 height: 3; should be 3.
 Tree 2 number of nodes: 7; should be 7.
 Remove the node 60 that has two children: Done.
 Tree 2 Preorder: Should be 40 20 10 30 80 50
 Displaying item - 40
 Displaying item - 20
 Displaying item - 10
 Displaying item - 30
 Displaying item - 80
 Displaying item - 50
 Tree 2 Inorder: Should be 10 20 30 40 50 80
 Displaying item - 10
 Displaying item - 20
 Displaying item - 30
 Displaying item - 40
 Displaying item - 50
 Displaying item - 80
 Tree 2 Postorder: Should be 10 30 20 50 80 40
 Displaying item - 10
 Displaying item - 30
 Displaying item - 20
 Displaying item - 50
 Displaying item - 80
 Displaying item - 40
 Tree 2 height: 3; should be 3.
 Tree 2 number of nodes: 6; should be 6.
 Remove the leaf 10: Done.
 Tree 2 Preorder: Should be 40 20 30 80 50
 Displaying item - 40
 Displaying item - 20
 Displaying item - 30
 Displaying item - 80
 Displaying item - 50
 Tree 2 Inorder: Should be 20 30 40 50 80
 Displaying item - 20
 Displaying item - 30
 Displaying item - 40
 Displaying item - 50
 Displaying item - 80
 Tree 2 Postorder: Should be 30 20 50 80 40
 Displaying item - 30
 Displaying item - 20
 Displaying item - 50
 Displaying item - 80
 Displaying item - 40
 Tree 2 height: 3; should be 3.
 Tree 2 number of nodes: 5; should be 5.
 Remove the root 40: Done.
 Tree 2 Preorder: Should be 50 20 30 80
 Displaying item - 50
 Displaying item - 20
 Displaying item - 30
 Displaying item - 80
 Tree 2 Inorder: Should be 20 30 50 80
 Displaying item - 20
 Displaying item - 30
 Displaying item - 50
 Displaying item - 80
 Tree 2 Postorder: Should be 30 20 80 50
 Displaying item - 30
 Displaying item - 20
 Displaying item - 80
 Displaying item - 50
 Tree 2 height: 3; should be 3.
 Tree 2 number of nodes: 4; should be 4.
 
 Testing overloaded assignment operator:
 
 Recall tree1Ptr:
 Tree 1 Preorder: Should be 20 30 50 60 70
 Displaying item - 20
 Displaying item - 30
 Displaying item - 50
 Displaying item - 60
 Displaying item - 70
 Tree 1 Inorder: Should be 20 30 50 60 70
 Displaying item - 20
 Displaying item - 30
 Displaying item - 50
 Displaying item - 60
 Displaying item - 70
 Tree 1 Postorder: Should be 70 60 50 30 20
 Displaying item - 70
 Displaying item - 60
 Displaying item - 50
 Displaying item - 30
 Displaying item - 20
 Tree 1 height: 5; should be 5.
 Tree 1 number of nodes: 5; should be 5.
 
 
 After assigning Tree 2 to Tree 3, we have:
 Tree 2 Preorder: Should be 50 20 30 80
 Displaying item - 50
 Displaying item - 20
 Displaying item - 30
 Displaying item - 80
 Tree 2 Inorder: Should be 20 30 50 80
 Displaying item - 20
 Displaying item - 30
 Displaying item - 50
 Displaying item - 80
 Tree 2 Postorder: Should be 30 20 80 50
 Displaying item - 30
 Displaying item - 20
 Displaying item - 80
 Displaying item - 50
 Tree 2 height: 3; should be 3.
 Tree 2 number of nodes: 4; should be 4.
 
 Tree 3 Preorder: Should be 50 20 30 80
 Displaying item - 50
 Displaying item - 20
 Displaying item - 30
 Displaying item - 80
 Tree 3 Inorder: Should be 20 30 50 80
 Displaying item - 20
 Displaying item - 30
 Displaying item - 50
 Displaying item - 80
 Tree 3 Postorder: Should be 30 20 80 50
 Displaying item - 30
 Displaying item - 20
 Displaying item - 80
 Displaying item - 50
 Tree 3 height: 3; should be 3.
 Tree 3 number of nodes: 4; should be 4.
 
 
 Change Tree 2 by removing 50
 Tree 2 Preorder: Should be 80 20 30
 Displaying item - 80
 Displaying item - 20
 Displaying item - 30
 Tree 2 Inorder: Should be 20 30 80
 Displaying item - 20
 Displaying item - 30
 Displaying item - 80
 Tree 2 Postorder: Should be 30 20 80
 Displaying item - 30
 Displaying item - 20
 Displaying item - 80
 Tree 2 height: 3; should be 2.
 Tree 2 number of nodes: 3; should be 3.
 
 Tree 3 should be unchanged:
 Tree 3 Preorder: Should be 50 20 30 80
 Displaying item - 50
 Displaying item - 20
 Displaying item - 30
 Displaying item - 80
 Tree 3 Inorder: Should be 20 30 50 80
 Displaying item - 20
 Displaying item - 30
 Displaying item - 50
 Displaying item - 80
 Tree 3 Postorder: Should be 30 20 80 50
 Displaying item - 30
 Displaying item - 20
 Displaying item - 80
 Displaying item - 50
 Tree 3 height: 3; should be 3.
 Tree 3 number of nodes: 4; should be 4.

*/
