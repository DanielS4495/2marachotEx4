#pragma once

#include "Tree.hpp"
#include "TreeNode.hpp"
#include <stack>
#include <queue>
#include <vector>

template <typename T>
class Tree<T>::PreOrderIterator<T> {

private:
    std::shared_ptr<TreeNode<T>> current;
    // TraversalType type;
    std::stack<std::shared_ptr<TreeNode<T>>> stack;
    std::queue<std::shared_ptr<TreeNode<T>>> queue;

    void pre_order_next();
    void post_order_next();
    void in_order_next();
    void bfs_next();
    void dfs_next();

public:
    PreOrderIterator<T>(std::shared_ptr<TreeNode<T>> root);

    bool operator!=(const PreOrderIterator<T>& other) const;
    PreOrderIterator<T>& operator++();
    T& operator*();
};


template <typename Key>
class PreOrderIterator {
public:
    PreOrderIterator(TreeNode<Key>* root);
    Key& operator*();
    PreOrderIterator& operator++();
    bool operator!=(const PreOrderIterator& other) const;

private:
    std::stack<TreeNode<Key>*> stack;
};

template <typename Key>
class PostOrderIterator {
public:
    PostOrderIterator(TreeNode<Key>* root);
    Key& operator*();
    PostOrderIterator& operator++();
    bool operator!=(const PostOrderIterator& other) const;

private:
    std::stack<TreeNode<Key>*> stack;
    std::stack<bool> visited;
};

template <typename Key>
class InOrderIterator {
public:
    InOrderIterator(TreeNode<Key>* root);
    Key& operator*();
    InOrderIterator& operator++();
    bool operator!=(const InOrderIterator& other) const;

private:
    std::stack<TreeNode<Key>*> stack;
    void pushLeft(TreeNode<Key>* node);
};

template <typename Key>
class BFSIterator {
public:
    BFSIterator(TreeNode<Key>* root);
    Key& operator*();
    BFSIterator& operator++();
    bool operator!=(const BFSIterator& other) const;

private:
    std::queue<TreeNode<Key>*> queue;
};

template <typename Key>
class DFSIterator {
public:
    DFSIterator(TreeNode<Key>* root);
    Key& operator*();
    DFSIterator& operator++();
    bool operator!=(const DFSIterator& other) const;

private:
    std::stack<TreeNode<Key>*> stack;
};

