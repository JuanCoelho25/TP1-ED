#include "../include/BinaryTree.hpp"
#include "../include/BooleanEvaluation.hpp"
#include <string>



BinaryTree::BinaryTree(){
    root = nullptr;
}

void nodeEvaluation(TreeNode* node){
    node->boolean_result = evaluateExpression()
}

BinaryTree::buildTree(std::string expression, unsigned int index){
    TreeNode* root = new TreeNode(expression);

    for(auto i = index; i < expression.length(); i++){
        if (expression[i] == 'e' || expression[i] == 'a') {
            std::string left = expression;
            left[i] = '0';
            root->left = buildTree(left, i + 1);

            std::string right = expression;
            left[i] = '1';
            root->right = buildTree(right, i + 1);

            break;
        }
    }
    return root;
}

void BinaryTree::treeEvaluation(TreeNode* root, std::string& expression, unsigned int index){
    if (root == nullptr) break;

    treeEvaluation(root->left, expression, index + 1);
    treeEvaluation(root->right, expression, index + 1);

    if (root->left == nullptr && root->right == nullptr) {
        nodeEvaluation();
    return;
  }

}
