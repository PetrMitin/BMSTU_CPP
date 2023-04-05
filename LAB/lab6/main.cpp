#include <iostream>

using namespace std;

struct TreeNode {
    int x;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* lft = nullptr, TreeNode* rght = nullptr) : x(val), left(lft), right(rght) {}
};

TreeNode* addNode(int value, TreeNode* node) {
    if (!node) node = new TreeNode(value);
    else {
        if (value < node->x) node->left = addNode(value, node->left);
        else node->right = addNode(value, node->right);
    }
    return node;
}

void printTreeLeft(TreeNode* node) {
    if (node) {
        printTreeLeft(node->left);
        cout << node->x << ' ';
        printTreeLeft(node->right);
    }
}

void printTreeRight(TreeNode* node) {
    if (node) {
        printTreeRight(node->right);
        cout << node->x << ' ';
        printTreeRight(node->left);
    }
}

void freeMemory(TreeNode* node) {
    if (node) {
        freeMemory(node->left);
        freeMemory(node->right);
        delete node;
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes" << endl;
    cin >> n;
    TreeNode* node = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        node = addNode(val, node);
    }
    cout << "Ascending tree output: " << endl;
    printTreeLeft(node);
    cout << endl << "Descending tree output: " << endl;
    printTreeRight(node);
    cout << endl;
    freeMemory(node);
    return 0;
}
