#pragma once
#include <vector>
#include <memory>

template <typename T>
class TreeNode {
public:
    T key;
    std::vector<std::shared_ptr<TreeNode<T>>> children;

    TreeNode(const T& key) : key(key) {}
     void addChild(TreeNode* child) {
        children.push_back(child);
    }
    // Allow Tree class to access TreeNode's private members
    // friend class Tree<Key>;
};

