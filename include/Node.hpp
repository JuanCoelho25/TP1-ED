#ifndef NODE_HPP
#define NODE_HPP

#include <string>

/**
 * @brief Represents a node in a generic stack data structure.
 *
 * The StackNode class is a template class that holds data and a link to the next node
 * in a stack. It is used in the implementation of the Stack class.
 *
 * @tparam T The type of data stored in the node.
 */
template <typename T>
class StackNode {
public:
    T data;         
    StackNode* link; 

    /**
     * @brief Constructor: Initializes a stack node with given data.
     *
     * @param n The data to be stored in the node.
     */
    StackNode(T n);
};

/**
 * @brief Represents a node in a binary tree data structure.
 *
 * The TreeNode class represents a node in a binary tree. It holds a string data value,
 * pointers to its left and right children, and a boolean result field, which may be used
 * for specific tree-related operations.
 */
class TreeNode {
public:
    std::string data;      
    TreeNode* left;       
    TreeNode* right;      
    bool boolean_result;   

    /**
     * @brief Constructor: Initializes a tree node with given data.
     *
     * @param value The string data value to be stored in the node.
     */
    TreeNode(std::string value);

    /**
     * @brief Destructor for TreeNode.
     */
    ~TreeNode();
};

#endif
