#pragma once

#include "Tree.hpp"
#include <stdexcept>
#include <queue>
#include <stack>
#include <algorithm>

// Add root
template <typename T>
void Tree<T>::add_root(const T& key) {
    root = std::make_shared<TreeNode<T>>(key);
}

// Add child node
template <typename T>
void Tree<T>::add_sub_node(const T& parent_key, const T& child_key) {
    auto parent_node = find(parent_key);
    if (!parent_node) {
        throw std::invalid_argument("Parent not found");
    }
    if (parent_node->children.size() >= k) {
        throw std::out_of_range("Exceeded maximum number of children");
    }
    parent_node->children.push_back(std::make_shared<TreeNode<T>>(child_key));
}

// Find node
template <typename T>
std::shared_ptr<TreeNode<T>> Tree<T>::findRoot(const T& key) {
    if (!root) return nullptr;
    std::queue<std::shared_ptr<TreeNode<T>>> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node->key == key) return node;
        for (auto& child : node->children) {
            q.push(child);
        }
    }
    return nullptr;
}

// Pre-Order iterator
template <typename T>
typename Tree<T>::PreOrderIterator<T> Tree<T>::begin_pre_order() {
    return Iterator(root, Iterator::TraversalType::PRE_ORDER);
}

template <typename T>
typename Tree<T>::Iterator Tree<T>::end_pre_order() {
    return Iterator(nullptr, Iterator::TraversalType::PRE_ORDER);
}

// Post-Order iterator
template <typename T>
typename Tree<T>::Iterator Tree<T>::begin_post_order() {
    return Iterator(root, Iterator::TraversalType::POST_ORDER);
}

template <typename T>
typename Tree<T>::Iterator Tree<T>::end_post_order() {
    return Iterator(nullptr, Iterator::TraversalType::POST_ORDER);
}

// In-Order iterator
template <typename T>
typename Tree<T>::Iterator Tree<T>::begin_in_order() {
    return Iterator(root, Iterator::TraversalType::IN_ORDER);
}

template <typename T>
typename Tree<T>::Iterator Tree<T>::end_in_order() {
    return Iterator(nullptr, Iterator::TraversalType::IN_ORDER);
}

// BFS iterator
template <typename T>
typename Tree<T>::Iterator Tree<T>::begin_bfs_scan() {
    return Iterator(root, Iterator::TraversalType::BFS);
}

template <typename T>
typename Tree<T>::Iterator Tree<T>::end_bfs_scan() {
    return Iterator(nullptr, Iterator::TraversalType::BFS);
}

// DFS iterator
template <typename T>
typename Tree<T>::Iterator Tree<T>::begin_dfs_scan() {
    return Iterator(root, Iterator::TraversalType::DFS);
}

template <typename T>
typename Tree<T>::Iterator Tree<T>::end_dfs_scan() {
    return Iterator(nullptr, Iterator::TraversalType::DFS);
}

// Heap method
template <typename T>
void Tree<T>::myHeap() {
    // Implementation of converting to a min-heap
    if (!root) return;
    std::vector<std::shared_ptr<TreeNode<T>>> nodes;
    std::queue<std::shared_ptr<TreeNode<T>>> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        nodes.push_back(node);
        for (auto& child : node->children) {
            q.push(child);
        }
    }
    std::sort(nodes.begin(), nodes.end(), [](const std::shared_ptr<TreeNode<T>>& a, const std::shared_ptr<TreeNode<T>>& b) {
        return a->key < b->key;
    });
    // Rebuild tree
    root = nodes[0];
    q.push(root);
    int index = 1;
    while (!q.empty() && index < nodes.size()) {
        auto node = q.front();
        q.pop();
        node->children.clear();
        for (int i = 0; i < k && index < nodes.size(); ++i, ++index) {
            node->children.push_back(nodes[index]);
            q.push(nodes[index]);
        }
    }
}

// Destructor
template <typename T>
Tree<T>::~Tree() {
    // Destructor logic if needed
}
