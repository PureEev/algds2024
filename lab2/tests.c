#include <stdio.h>
#include "func.h"
#include <assert.h>

void test_Insert_NegativeValue_ReturnTreeWithKeyOfNegValue() {
    struct SplayTree* root = createNode(11);
    root->LeftNode = createNode(5);
    root->RightNode = createNode(15);
    root->LeftNode->LeftNode = createNode(3);
    root->LeftNode->RightNode = createNode(7);
    root->RightNode->LeftNode = createNode(12);
    root->RightNode->RightNode = createNode(20);

    root = insert(root, -6);
    assert(root->key == -6);


    freeTree(root);
}

void test_Insert_ZeroValue_ReturnTreeWithKeyOfZeroValue() {
    struct SplayTree* root = createNode(11);
    root->LeftNode = createNode(5);
    root->RightNode = createNode(15);
    root->LeftNode->LeftNode = createNode(3);
    root->LeftNode->RightNode = createNode(7);
    root->RightNode->LeftNode = createNode(12);
    root->RightNode->RightNode = createNode(20);

    root = insert(root, 0);
    assert(root->key == 0);


    freeTree(root);
}

// Объединение двух деревьев и проверка корректности операции
void test_merge_NegativeTree_ReturnTreeWithNegativeAndPositiveValues() {
    struct SplayTree* left = createNode(-10);
    left->LeftNode = createNode(-5);

    struct SplayTree* right = createNode(15);

    struct SplayTree* merged = merge(left, right);

    assert(merged->key == -10);
    assert(merged->RightNode->key == 15);

    freeTree(merged);
}

void test_split_NegativeAndPositiveTree_ReturnLeftNegativeAndRightPositive() {
    struct SplayTree* root = createNode(11);
    root->LeftNode = createNode(-5);
    root->RightNode = createNode(15);
    root->LeftNode->LeftNode = createNode(-3);
    root->LeftNode->RightNode = createNode(-7);
    root->RightNode->LeftNode = createNode(12);
    root->RightNode->RightNode = createNode(20);

    struct SplayTree* left;
    struct SplayTree* right;

    splitTree(root, &left, &right, 11);

    assert(left->key == -5);
    assert(right->key == 15);

    freeTree(left);
    freeTree(right);
}

void test_search_negativeValue_TreeWithNegValue() {
    struct SplayTree* root = createNode(10);
    root->LeftNode = createNode(-5);
    root->RightNode = createNode(15);

    struct SplayTree* found = search(root, 5);

    assert(found->key == -5);

    freeTree(root);
}

void test_RotateLeft_ZeroValue_ReturnTreeWithZeroVal() {

    struct SplayTree* root = createNode(10);
    root->RightNode = createNode(0);
    root->RightNode->LeftNode = createNode(15);

    root = RotateLeft(root);

    assert(root->key == 0);

    freeTree(root);
}

void test_RotateRight_ZeroValue_ReturnTreeWithZeroVal() {

    struct SplayTree* root = createNode(20);
    root->LeftNode = createNode(0);
    root->LeftNode->RightNode = createNode(15);

    root = RotateRight(root);

    assert(root->key == 0);
 
    freeTree(root);
}

void test_createNode_NegValue_NodeWithNegValue() {
    struct SplayTree* root = createNode(-3);
    assert(root->key == -3);
    freeTree(root);
}

void test_freeTree_ZeroValue_Null() {
    struct SplayTree* root = createNode(0);
    freeTree(root);
    assert(root->key != 0);
}