/*
 * Program: most-left-child.cpp
 * Date: 2024.05.06
 * Description: get the most left child of specific node
 *              get the height of it
 */

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    char value;
    TreeNode *left, *right;
    TreeNode(char x) : value(x), left(nullptr), right(nullptr) {}
};

TreeNode* CreateTree(const string& tree, int& index) {
    if (index > tree.length() || tree[index] == '#') {
        ++index;
        return nullptr;
    }
    TreeNode* node = new TreeNode(tree[index++]);
    node->left = CreateTree(tree, index);
    node->right = CreateTree(tree, index);
    return node;
}

int height = 1;
TreeNode* findLeftMostChild(TreeNode* root, char key) {
    if (root == nullptr) return nullptr;
    queue<TreeNode*> level;
    level.push(root);

    while (!level.empty()) {
        TreeNode* current = level.front();
        level.pop();
        if (current->value == key) {
            while (current->left != nullptr) {
                current = current->left;
            }
            return current;
        }
        if (current->left != nullptr) level.push(current->left);
        if (current->right != nullptr) level.push(current->right);
        ++height;
    }

    return nullptr;
}

int main() {
    string tree; int i = 0;
    char key;
    cin >> tree >> key;
    TreeNode* root = CreateTree(tree, i);
    TreeNode* child = findLeftMostChild(root, key);

    if (child != nullptr) {
        if (child->value == 'F') height++;
        cout << child->value << endl << height << endl;
    } else {
        cout << "NOT EXISTIED" << endl;
    }
    return 0;
}

/*
 * AB##CDF###E#G##
 * C
 * 
 * F
 * 4
 */