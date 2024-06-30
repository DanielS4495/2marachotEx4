

#include "Iterator.hpp"


// Constructor
template <typename T>
Tree<T>::Iterator::Iterator(std::shared_ptr<TreeNode<T>> root, TraversalType type) : current(root), type(type) {
    if (root) {
        switch (type) {
            case TraversalType::PRE_ORDER:
                stack.push(root);
                break;
            case TraversalType::POST_ORDER:
                // Post-order requires processing all nodes first
                stack.push(root);
                while (!stack.empty()) {
                    auto node = stack.top();
                    stack.pop();
                    queue.push(node);
                    for (auto& child : node->children) {
                        stack.push(child);
                    }
                }
                current = queue.back();
                queue.pop();
                break;
            case TraversalType::IN_ORDER:
                stack.push(root);
                break;
            case TraversalType::BFS:
                queue.push(root);
                break;
            case TraversalType::DFS:
                stack.push(root);
                break;
        }
    }
}

template <typename T>
bool Tree<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

template <typename T>
typename Tree<T>::Iterator& Tree<T>::Iterator::operator++() {
    switch (type) {
        case TraversalType::PRE_ORDER:
            pre_order_next();
            break;
        case TraversalType::POST_ORDER:
            post_order_next();
            break;
        case TraversalType::IN_ORDER:
            in_order_next();
            break;
        case TraversalType::BFS:
            bfs_next();
            break;
        case TraversalType::DFS:
            dfs_next();
            break;
    }
    return *this;
}

template <typename T>
T& Tree<T>::Iterator::operator*() {
    return current->key;
}

// Pre-Order Next
template <typename T>
void Tree<T>::Iterator::pre_order_next() {
    if (stack.empty()) {
        current = nullptr;
        return;
    }
    current = stack.top();
    stack.pop();
    for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
        stack.push(*it);
    }
}

// Post-Order Next
template <typename T>
void Tree<T>::Iterator::post_order_next() {
    if (queue.empty()) {
        current = nullptr;
        return;
    }
    current = queue.back();
    queue.pop();
}

// In-Order Next
template <typename T>
void Tree<T>::Iterator::in_order_next() {
    // In-Order traversal logic
    if (stack.empty()) {
        current = nullptr;
        return;
    }
    // Similar to Pre-Order for generic k-ary trees
    current = stack.top();
    stack.pop();
    for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
        stack.push(*it);
    }
}

// BFS Next
template <typename T>
void Tree<T>::Iterator::bfs_next() {
    if (queue.empty()) {
        current = nullptr;
        return;
    }
    current = queue.front();
    queue.pop();
    for (auto& child : current->children) {
        queue.push(child);
    }
}

// DFS Next
template <typename T>
void Tree<T>::Iterator::dfs_next() {
    if (stack.empty()) {
        current = nullptr;
        return;
    }
    current = stack.top();
    stack.pop();
    for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
        stack.push(*it);
    }
}

#endif // TREEITERATOR_TPP
