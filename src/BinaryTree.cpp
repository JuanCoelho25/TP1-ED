#include "../include/BinaryTree.hpp"
#include "../include/BooleanEvaluation.hpp"
#include <string>


BinaryTree::BinaryTree(){
    root = nullptr;
}

void BinaryTree::nodeEvaluation(TreeNode* node){
    node->boolean_result = evaluateExpression(node->data);
}

TreeNode* BinaryTree::buildTree(std::string expression, unsigned int index){
    TreeNode* root = new TreeNode(expression);

    for (auto i = index; i < expression.length(); i++){
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
        nodeEvaluation(root);
        return;
    }

    if ((root->left->boolean_result == 1) && (root->right->boolean_result == 1)){
        for (unsigned int i = 0; i < root->data.length(); i++){
            if (root->right->value[i] != root->left->value[i]) {
                root->value[i] = 'a';
            }
            else {
                root->data[i] = root->left->data[i];
            }
        }
        root->boolean_result = 1;
    }

    else if ((root->left->boolean_result) || (root->right->boolean_result)){
        unsigned int position = index_;
        while (position < root->data.length() && root->data[position] != 'e' && expression[position] != 'a') {
            position++;
        }
        if (root->data[position] == 'a'){
            root->boolean_result = 0;
            break;
        }
        std::string value;
        if (root->right->boolean_result) value = root->right->boolean_result;
        else {value = root->left->boolean_result;}
        root->data = value;
        root->boolean_result = 1;
    }
    
    else {
        root->result = 0;
        root->data[index] = '0';
    }
}

void BinaryTree::BinaryTreeDestructor(TreeNode* node){
    if(root == nullptr) break;

    BinaryTreeDestructor(node->left);
    BinaryTreeDestructor(node->right);
}

BinaryTree::~BinaryTree(){
    BinaryTreeDestructor(root);
}


