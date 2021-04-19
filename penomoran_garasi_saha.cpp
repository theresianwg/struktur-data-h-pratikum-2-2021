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

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        printInorder(_root);
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

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            cout << root->key << " ";
            __inorder(root->right);
        }
    }

    int checker1, temp;
    void printInorder(BSTNode *root){
        int h = height(root);
        int i, checker=0;
        for (i=h; i>=1; i--){
            if(checker==0){
                temp=100000;
                printLevel(root, i, checker);
                cout << checker1;
                checker++;
            }
            else{
                temp=0;
                printLevel(root, i, checker);
                cout << checker1;
                checker--;
            }
            cout << (" ");
        }
    }

    void printLevel(BSTNode *root, int level, int checker){
        if (root == NULL){
            return;
        }   
        if (level == 1){
            if(checker==0){
                if(root->key<=temp){
                    temp=root->key;
                    checker1=temp;
                }
            }
            else{
                if(root->key>=temp){
                    temp=root->key;
                    checker1=temp;
                }
            }
        }
        else if (level > 1){
            printLevel(root->left, level-1, checker);
            printLevel(root->right, level-1, checker);
        }
    }

    int height(BSTNode *root){
        if (root==NULL){
            return 0;
        }
        else{
            int lheight = height(root->left);
            int rheight = height(root->right);
 
            if (lheight > rheight)
                return(lheight+1);
            else return(rheight+1);
        }
    }
};
int main (){
    BST set;
    set.init();
    
    int testcase,N;
    cin >> testcase;
        for (int i=1; i <= testcase; i++){
            cin >> N;
            set.insert(N);
        }
        
    set.traverseInorder ();
    return 0;
}
