#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bt.h"

void freeTree(struct TreeNode *root)
{
    if (!root)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void postorderTraversal(struct TreeNode *root, int *result, int *index)
{
    if (!root)
        return;

    postorderTraversal(root->left, result, index);

    postorderTraversal(root->right, result, index);

    result[(*index)++] = root->val;
}

bool test_buildTree()
{
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[] = {4, 2, 5, 1, 3};
    int expected_postorder[] = {4, 5, 2, 3, 1};

    int num_nodes = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode *root = buildTree(preorder, num_nodes, inorder, num_nodes);
    if (!root) {
        printf("Fail building a tree.\n");
        return false;
    }

    int *expected_postorder_seq = malloc(num_nodes * sizeof(int));
    int expected_postorder_idx = 0;
    postorderTraversal(root, expected_postorder_seq, &expected_postorder_idx);

    bool result = true;
    for (int i = 0; i < num_nodes; i++) {
        if (expected_postorder[i] != expected_postorder_seq[i]) {
            result = false;
            break;
        }
    }

    free(expected_postorder_seq);
    freeTree(root);

    return result;
}

int main()
{
    srand(time(NULL));

    if (test_buildTree()) {
        printf(
            "Test passed: The tree was successfully constructed and matches "
            "the expected postorder.\n");
    } else {
        printf(
            "Test failed: The tree construction failed or the generated "
            "postorder does not match the expected one.\n");
    }

    return 0;
}
