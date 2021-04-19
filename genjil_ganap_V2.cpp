#include <iostream>
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
        __inorder(_root);
    }

private:
    
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

    void printInorder(BSTNode *root){
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->key << " ";
 
    printInorder(root->right);
    }   
};

int main(){
    BST set;
    set.init();

    int testcase;
    cin >> testcase;
        for(int i=1; i<=testcase; i++){
        int angka[testcase];
        cin >> angka[i];
        if(i==0){
            if(angka[i]%2==0){
                set.insert(angka[i]);
            }
        }
        else{
            if(angka[i]%2==0){
                set.insert(angka[i]);
            }
            else{
                for(int j=i; j>=0; j--){
                    if(angka[j]%2==0){
                        set.remove(angka[j]);
                        angka[j]++;
                        break;
                    }
                }
            }
        }
    }

    if(set.isEmpty()){
        cout << "Tree Kosong!";
    }
    else{
        set.traverseInorder();
    }
    cout<< endl;
    puts("");
    
    return 0;
}
