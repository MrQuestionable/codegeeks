/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int countNodes(struct Node* tree) {
        if (tree == nullptr) return 0;
        return 1 + countNodes(tree->left) + countNodes(tree->right);
    }
    bool isCBT(struct Node* tree, int index, int cnt) {
        if (tree == nullptr) return true;
        if (index >= cnt) return false;
        bool left = isCBT(tree->left, 2 * index + 1, cnt);
        bool right = isCBT(tree->right, 2 * index + 2, cnt);
        return (left && right);
    }
    bool isMax(struct Node* tree) {
        if (tree->left == nullptr && tree->right == nullptr) {
            return true;
        }
        if (tree->right == nullptr) {
            return (tree->data >= tree->left->data);
        }
        if (tree->data >= tree->left->data && tree->data >= tree->right->data) {
            return isMax(tree->left) && isMax(tree->right);
        }
        return false;
    }
    bool isHeap(struct Node* tree) {
        if (tree == nullptr) return true;
        int totalNodes = countNodes(tree);
        if (isCBT(tree, 0, totalNodes) && isMax(tree)) {
            return true;
        }
        return false;
    }
};