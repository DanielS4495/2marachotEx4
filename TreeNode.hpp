//danielsamson10@gmail.com
//211358486
#pragma once
#include <vector>
#include <memory>
#include "complex.hpp"


template <typename T>
class TreeNode {
public:
    T key;
    std::vector<TreeNode*> children;

    TreeNode(const T& key) : key(key) {}
    ~TreeNode() {}   
    T getKey() {
        return key;
    }
    void addChild(TreeNode* child) {
        children.push_back(child);
    }
};