#pragma once

#include "TreeNode.hpp"
#include <iostream>
#include <queue>
#include <stack>
class Iterator;
template <typename T>
class Tree
{
private:
    std::shared_ptr<TreeNode<T>> root; // root of the tree
    int max;                           // Maximum number of children

public:
    Tree(int max = 2) : root(nullptr), max(max) {}
    ~Tree();

    void add_root(const T &key);
    void add_sub_node(const T &parent_key, const T &child_key);
    std::shared_ptr<TreeNode<T>> findRoot(const T &key);

    // Iterators
    PreOrderIterator<T> begin_pre_order();
    PreOrderIterator<T> end_pre_order();

    PostOrderIterator<T> begin_post_order();
    PostOrderIterator<T> end_post_order();

    InOrderIterator<T> begin_in_order();
    InOrderIterator<T> end_in_order();

    BFSIterator<T> begin_bfs_scan();
    BFSIterator<T> end_bfs_scan();

    DFSIterator<T> begin_dfs_scan();
    DFSIterator<T> end_dfs_scan();

    void myHeap();
    void print(); // GUI print method
};
