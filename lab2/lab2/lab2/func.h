#pragma once

struct SplayTree {
    int key;
    struct SplayTree* RightNode;
    struct SplayTree* LeftNode;
};

struct SplayTree* createNode(int key);

void freeTree(struct SplayTree* root);

struct SplayTree* RotateLeft(struct SplayTree* node);

struct SplayTree* RotateRight(struct SplayTree* node);

struct SplayTree* search(struct SplayTree* root, int key);

struct SplayTree* insert(struct SplayTree* root, int key);

struct SplayTree* merge(struct SplayTree* left, struct SplayTree* right);

void splitTree(struct SplayTree* root, struct SplayTree** leftTree, struct SplayTree** rightTree, int key);