#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* BuildTree(const char* input, int* index) {
    if (input[*index] == '\0' || input[*index] == '#') {
        (*index)++;
        return NULL;
    }
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    node->data = input[(*index)++];
    node->left = BuildTree(input, index);
    node->right = BuildTree(input, index);
    return node;
}

void PrintTree(struct TreeNode* root) {
    if(root == NULL) return;
    PrintTree(root->left);
    printf("%c", root->data);
    PrintTree(root->right);
}

void SwapChildren(struct TreeNode* root) {
    if (root == NULL) return;
    if (root->left != NULL && root->right != NULL) {
        struct TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    SwapChildren(root->left);
    SwapChildren(root->right);
}

int GetTreeHeight(struct TreeNode* root) {
    if (root == NULL) return 0;
    int left_height = GetTreeHeight(root->left);
    int right_height = GetTreeHeight(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

int CountBalancedNode(struct TreeNode* root) {
    if (root == NULL) return 0;
    int balanced_count = 0;
    int height_left = GetTreeHeight(root->left);
    int height_right = GetTreeHeight(root->right);

    if (height_left == height_right)
        balanced_count = 1;
    balanced_count += CountBalancedNode(root->left) + CountBalancedNode(root->right);
    return balanced_count;
}

int main() {
    //char test_sample[] = "ABD#E###CF##G##";
    char tree[100];
    scanf("%s", tree);
    int i = 0;
    struct TreeNode* root = BuildTree(tree, &i);
    SwapChildren(root);
    //printf("The tree after swap: ");
    if (root != NULL)
        PrintTree(root);
    else 
        printf("NULL");
    //printf("\nThe balanced node: ");
    printf("\n%d\n", CountBalancedNode(root));
    
    return 0;
}
