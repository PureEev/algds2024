#pragma once
#include "func.h"
#include <stdio.h>
#include <stdlib.h>



struct SplayTree* createNode(int key) {
    struct SplayTree* newNode = malloc(sizeof(struct SplayTree));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
    }
    newNode->key = key;
    newNode->LeftNode = NULL;
    newNode->RightNode = NULL;
    return newNode;
}

void freeTree(struct SplayTree* root) {
    if (root == NULL)
        return;
    freeTree(root->LeftNode);
    freeTree(root->RightNode);
    free(root);
}

struct SplayTree* RotateLeft(struct SplayTree* node) {
    if (node == NULL || node->RightNode == NULL)
        return node;

    struct SplayTree* oldRoot = node;
    struct SplayTree* newRoot = node->RightNode;

    oldRoot->RightNode = newRoot->LeftNode;
    newRoot->LeftNode = oldRoot;

    return newRoot;
}

struct SplayTree* RotateRight(struct SplayTree* node) {
    if (node == NULL || node->LeftNode == NULL)
        return node;

    struct SplayTree* oldRoot = node;
    struct SplayTree* newRoot = node->LeftNode;

    oldRoot->LeftNode = newRoot->RightNode;
    newRoot->RightNode = oldRoot;

    return newRoot;
}

struct SplayTree* search(struct SplayTree* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key) {
        if (root->LeftNode == NULL)
            return root;
        if (key < root->LeftNode->key) {
            root->LeftNode->LeftNode = search(root->LeftNode->LeftNode, key);
            root = RotateRight(root);
        }
        else if (key > root->LeftNode->key) {
            root->LeftNode->RightNode = search(root->LeftNode->RightNode, key);
            if (root->LeftNode->RightNode != NULL)
                root->LeftNode = RotateLeft(root->LeftNode);
        }
        return (root->LeftNode == NULL) ? root : RotateRight(root);
    }
    else {
        if (root->RightNode == NULL)
            return root;
        if (key < root->RightNode->key) {
            root->RightNode->LeftNode = search(root->RightNode->LeftNode, key);
            if (root->RightNode->LeftNode != NULL)
                root->RightNode = RotateRight(root->RightNode);
        }
        else if (key > root->RightNode->key) {
            root->RightNode->RightNode = search(root->RightNode->RightNode, key);
            root = RotateLeft(root);
        }
        return (root->RightNode == NULL) ? root : RotateLeft(root);
    }
}

struct SplayTree* insert(struct SplayTree* root, int key) {
    if (root == NULL) return createNode(key);

    if (key < root->key) {
        root->LeftNode = insert(root->LeftNode, key);
    }
    else if (key > root->key) {
        root->RightNode = insert(root->RightNode, key);
    }
    else {
        return root;
    }

    return search(root, key);
}

struct SplayTree* merge(struct SplayTree* left, struct SplayTree* right) {
    if (left == NULL)
        return right;

    struct SplayTree* maxNode = left;
    while (maxNode->RightNode != NULL)
        maxNode = maxNode->RightNode;

    maxNode = search(left, maxNode->key);

    maxNode->RightNode = right;

    return maxNode;
}

void splitTree(struct SplayTree* root, struct SplayTree** leftTree, struct SplayTree** rightTree, int key) {
    if (root == NULL) {
        *leftTree = NULL;
        *rightTree = NULL;
        return;
    }

    root = search(root, key);

    if (root->key == key) {
        *leftTree = root->LeftNode;
        *rightTree = root->RightNode;
        root->LeftNode = NULL;
        root->RightNode = NULL;
    }
    else if (root->key < key) {
        *leftTree = root;
        splitTree(root->RightNode, &((*leftTree)->RightNode), rightTree, key);
    }
    else {
        *rightTree = root;
        splitTree(root->LeftNode, leftTree, &((*rightTree)->LeftNode), key);
    }
}
