#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
struct BSTNode {
    BSTNode *left, *right;
    int key;
};

struct BST {
    
    BSTNode *_root;
    unsigned int _size;

    
    void init() {
        _root = NULL;
        _size = 0u;
    }
    
        bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }
    
     void traverseInorder() {
        __inorder(_root);
    }
   BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }
    
    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }
};
int main () {
    BST set;
    set.init();
    
    int testcase,N;
    cin >> testcase;
        for (int i=1; i<= testcase; i++) {
        cin >> N;
            set.insert(N);
        }
        
        set.traverseInorder();
        puts("");
        return 0;
}
