//danielsamson10@gmail.com
//211358486
#pragma once
#include <stack>
#include <queue>
#include "TreeNode.hpp"

template <typename T>
class PreOrderIterator
{
private:
    TreeNode<T> *m_pointer;
    std::queue<TreeNode<T> *> m_queue;

public:
    PreOrderIterator(TreeNode<T> *ptr = nullptr) : m_pointer(ptr)
    {
        if (ptr)
        {
            m_queue.push(ptr);
        }
    }

    bool operator!=(const PreOrderIterator &other) const { return !m_queue.empty(); }
    T &operator*() const { return m_queue.front()->key; }

    // Preorder ++
    PreOrderIterator &operator++()
    {
        TreeNode<T> *current = m_queue.front();
        m_queue.pop();
        for (auto child : current->children)
        {
            m_queue.push(child);
        }
        return *this;
    }
};

template <typename T>
class PostOrderIterator
{
private:
    TreeNode<T> *m_pointer;
    std::stack<TreeNode<T> *> m_stack;
    TreeNode<T> *m_last_visited;

public:
    PostOrderIterator(TreeNode<T> *ptr = nullptr) : m_pointer(ptr), m_last_visited(nullptr)
    {
        if (ptr)
        {
            m_stack.push(ptr);
            advance();
        }
    }

    bool operator!=(const PostOrderIterator &other) const
    {
        return m_pointer != other.m_pointer;
    }

    T &operator*() const
    {
        return m_pointer->key;
    }

    PostOrderIterator &operator++()
    {
        advance();
        return *this;
    }

private:
    void advance()
    {
        while (!m_stack.empty())
        {
            TreeNode<T> *current = m_stack.top();
            if (!current->children.empty() && m_last_visited != current->children.back())
            {
                for (auto it = current->children.rbegin(); it != current->children.rend(); ++it)
                {
                    m_stack.push(*it);
                }
            }
            else
            {
                m_stack.pop();
                m_last_visited = current;
                m_pointer = current;
                return;
            }
        }
        m_pointer = nullptr;
    }
};

template <typename T>
class InorderIterator
{
private:
    TreeNode<T> *m_pointer;
    std::stack<TreeNode<T> *> m_stack;

public:
    void push_leftmost(TreeNode<T> *node)
    {
        while (node)
        {
            m_stack.push(node);
            if (!node->children.empty())
            {
                node = node->children[0];
            }
            else
            {
                node = nullptr;
            }
        }
    }

public:
    InorderIterator(TreeNode<T> *ptr = nullptr) : m_pointer(ptr)
    {
        if (ptr)
        {
            push_leftmost(ptr);
            m_pointer = m_stack.empty() ? nullptr : m_stack.top();
        }
    }

    bool operator!=(const InorderIterator &other) const
    {
        return m_pointer != other.m_pointer;
    }

    T &operator*() const
    {
        return m_stack.top()->key;
    }

    InorderIterator &operator++()
    {
        if (!m_stack.empty())
        {
            TreeNode<T> *node = m_stack.top();
            m_stack.pop();
            if (node->children.size() > 1)
            {
                push_leftmost(node->children[1]);
            }
            m_pointer = m_stack.empty() ? nullptr : m_stack.top();
        }
        return *this;
    }
};

template <typename T>
class BfsIterator
{
private:
    TreeNode<T> *m_pointer;
    std::queue<TreeNode<T> *> m_queue;

public:
    BfsIterator(TreeNode<T> *ptr = nullptr) : m_pointer(ptr)
    {
        if (ptr)
        {
            m_queue.push(ptr);
        }
    }

    bool operator!=(const BfsIterator &other) const { return !m_queue.empty(); }
    T &operator*() const { return m_queue.front()->key; }

    BfsIterator &operator++()
    {
        TreeNode<T> *current = m_queue.front();
        m_queue.pop();
        for (auto child : current->children)
        {
            m_queue.push(child);
        }
        return *this;
    }
};

template <typename T>
class DfsIterator
{
private:
    TreeNode<T> *m_pointer;
    std::stack<TreeNode<T> *> m_stack;

public:
    DfsIterator(TreeNode<T> *ptr = nullptr) : m_pointer(ptr)
    {
        if (ptr)
        {
            m_stack.push(ptr);
        }
    }

    bool operator!=(const DfsIterator &other) const
    {
        // Properly compare against another iterator
        if (other.m_stack.empty() && m_stack.empty())
        {
            return false;
        }
        if (!m_stack.empty() && other.m_stack.empty())
        {
            return true;
        }
        return m_stack.top() != other.m_stack.top();
    }

    T &operator*() const
    {
        if (!m_stack.empty())
        {
            return m_stack.top()->key;
        }
        throw std::out_of_range("Iterator out of range");
    }

    DfsIterator &operator++()
    {
        if (!m_stack.empty())
        {
            TreeNode<T> *current = m_stack.top();
            m_stack.pop();
            for (auto it = current->children.rbegin(); it != current->children.rend(); ++it)
            {
                m_stack.push(*it);
            }
        }
        return *this;
    }

    bool operator==(const DfsIterator &other) const
    {
        return !(*this != other);
    }
};


template <typename T>
class HeapIterator
 {
private:
    typename std::vector<T>::iterator m_iterator;

public:
    HeapIterator(typename std::vector<T>::iterator it) : m_iterator(it) {}

    bool operator!=(const HeapIterator &other) const { return m_iterator != other.m_iterator; }
    T &operator*() const { return *m_iterator; }
    HeapIterator &operator++() {
        ++m_iterator;
        return *this;
    }
};


// // #pragma once

// // #include "TreeNode.hpp"
// // #include <stack>
// // #include <queue>
// // #include <vector>

// // template <typename T>
// // class PreOrderIterator
// // {

// // private:
// //     std::stack<TreeTreeNode<T> *> stack;

// // public:
// //     PreOrderIterator(TreeTreeNode<T> *root);

// //     bool operator!=(const PreOrderIterator &other) const;
// //     PreOrderIterator &operator++();
// //     T &operator*();
// // };

// // template <typename T>
// // class PostOrderIterator
// // {
// // private:
// //     std::stack<TreeTreeNode<T>> stack;
// //     std::stack<bool> visited;

// // public:
// //     PostOrderIterator(TreeTreeNode<T> root);
// //     T &operator*();
// //     PostOrderIterator &operator++();
// //     bool operator!=(const PostOrderIterator &other) const;
// // };

// // template <typename T>
// // class InOrderIterator
// // {
// // private:
// //     std::stack<TreeTreeNode<T>> stack;
// //     void pushLeft(TreeTreeNode<T> node);

// // public:
// //     InOrderIterator(TreeTreeNode<T> root);
// //     T &operator*();
// //     InOrderIterator &operator++();
// //     bool operator!=(const InOrderIterator &other) const;
// // };

// // template <typename T>
// // class BFSIterator
// // {
// // private:
// //     std::queue<TreeTreeNode<T>> queue;

// // public:
// //     BFSIterator(TreeTreeNode<T> root);
// //     T &operator*();
// //     BFSIterator &operator++();
// //     bool operator!=(const BFSIterator &other) const;
// // };

// // template <typename T>
// // class DFSIterator
// // {
// // private:
// //     std::stack<TreeTreeNode<T>> stack;

// // public:
// //     DFSIterator(TreeTreeNode<T> root);
// //     T &operator*();
// //     DFSIterator &operator++();
// //     bool operator!=(const DFSIterator &other) const;
// // };

// // #include "Iterator.hpp"

// // // PreOrderIterator implementation
// // template <typename T>
// // PreOrderIterator<T>::PreOrderIterator(TreeTreeNode<T> *root)
// // {
// //     if (root)
// //     {
// //         stack.push(root);
// //     }
// // }

// // template <typename T>
// // T &PreOrderIterator<T>::operator*()
// // {
// //     return stack.top()->key;
// // }

// // template <typename T>
// // PreOrderIterator<T> &PreOrderIterator<T>::operator++()
// // {
// //     auto node = stack.top();
// //     stack.pop();
// //     for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
// //     {
// //         stack.push(*it);
// //     }
// //     return *this;
// // }

// // template <typename T>
// // bool PreOrderIterator<T>::operator!=(const PreOrderIterator<T> &other) const
// // {
// //     return !stack.empty() || !other.stack.empty();
// // }

// // // PostOrderIterator implementation
// // template <typename T>
// // PostOrderIterator<T>::PostOrderIterator(TreeTreeNode<T> root)
// // {
// //     if (root)
// //     {
// //         stack.push(root);
// //         visited.push(false);
// //     }
// // }

// // template <typename T>
// // T &PostOrderIterator<T>::operator*()
// // {
// //     return stack.top()->T;
// // }

// // template <typename T>
// // PostOrderIterator<T> &PostOrderIterator<T>::operator++()
// // {
// //     while (!stack.empty())
// //     {
// //         auto node = stack.top();
// //         bool node_visited = visited.top();
// //         if (!node_visited)
// //         {
// //             visited.top() = true;
// //             for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
// //             {
// //                 stack.push(*it);
// //                 visited.push(false);
// //             }
// //         }
// //         else
// //         {
// //             stack.pop();
// //             visited.pop();
// //             if (!stack.empty() && visited.top())
// //             {
// //                 return *this;
// //             }
// //         }
// //     }
// //     return *this;
// // }

// // template <typename T>
// // bool PostOrderIterator<T>::operator!=(const PostOrderIterator<T> &other) const
// // {
// //     return !stack.empty() || !other.stack.empty();
// // }

// // // InOrderIterator implementation
// // template <typename T>
// // InOrderIterator<T>::InOrderIterator(TreeTreeNode<T> root)
// // {
// //     pushLeft(root);
// // }

// // template <typename T>
// // T &InOrderIterator<T>::operator*()
// // {
// //     return stack.top()->T;
// // }

// // template <typename T>
// // InOrderIterator<T> &InOrderIterator<T>::operator++()
// // {
// //     auto node = stack.top();
// //     stack.pop();
// //     if (!node->children.empty())
// //     {
// //         pushLeft(node->children[0]);
// //     }
// //     return *this;
// // }

// // template <typename T>
// // bool InOrderIterator<T>::operator!=(const InOrderIterator<T> &other) const
// // {
// //     return !stack.empty() || !other.stack.empty();
// // }

// // template <typename T>
// // void InOrderIterator<T>::pushLeft(TreeTreeNode<T> node)
// // {
// //     while (node)
// //     {
// //         stack.push(node);
// //         if (node->children.empty())
// //             break;
// //         node = node->children[0];
// //     }
// // }

// // // BFSIterator implementation
// // template <typename T>
// // BFSIterator<T>::BFSIterator(TreeTreeNode<T> root)
// // {
// //     if (root)
// //     {
// //         queue.push(root);
// //     }
// // }

// // template <typename T>
// // T &BFSIterator<T>::operator*()
// // {
// //     return queue.front()->T;
// // }

// // template <typename T>
// // BFSIterator<T> &BFSIterator<T>::operator++()
// // {
// //     auto node = queue.front();
// //     queue.pop();
// //     for (auto &child : node->children)
// //     {
// //         queue.push(child);
// //     }
// //     return *this;
// // }

// // template <typename T>
// // bool BFSIterator<T>::operator!=(const BFSIterator<T> &other) const
// // {
// //     return !queue.empty() || !other.queue.empty();
// // }

// // // DFSIterator implementation
// // template <typename T>
// // DFSIterator<T>::DFSIterator(TreeTreeNode<T> root)
// // {
// //     if (root)
// //     {
// //         stack.push(root);
// //     }
// // }

// // template <typename T>
// // T &DFSIterator<T>::operator*()
// // {
// //     return stack.top()->T;
// // }

// // template <typename T>
// // DFSIterator<T> &DFSIterator<T>::operator++()
// // {
// //     auto node = stack.top();
// //     stack.pop();
// //     for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
// //     {
// //         stack.push(*it);
// //     }
// //     return *this;
// // }

// // template <typename T>
// // bool DFSIterator<T>::operator!=(const DFSIterator<T> &other) const
// // {
// //     return !stack.empty() || !other.stack.empty();
// // }
// // ///////////////////////////////////////////
// // template <typename T>
// // class HeapIterator
// // {
// // public:
// //     HeapIterator(typename std::vector<T>::iterator ptr) : m_ptr(ptr) {}

// //     T &operator*() const { return *m_ptr; }
// //     std::vector<T>::iterator operator->() { return m_ptr; }

// //     // Prefix increment
// //     HeapIterator &operator++()
// //     {
// //         ++m_ptr;
// //         return *this;
// //     }

// //     // Postfix increment
// //     HeapIterator operator++(int)
// //     {
// //         HeapIterator tmp = *this;
// //         ++(*this);
// //         return tmp;
// //     }

// //     bool operator==(const HeapIterator &other)
// //     {
// //         return this.m_ptr == other.m_ptr;
// //     }

// //     bool operator!=(const HeapIterator &other)
// //     {
// //         return this.m_ptr != other.m_ptr;
// //     }

// // private:
// //     typename std::vector<T>::iterator m_ptr;
// // };

// // // void make_heap(TreeTreeNode<T>* node);
// // // void myHeap();
// // // HeapIterator heap_begin() { return HeapIterator(heap.key()); }
// // // HeapIterator heap_end() { return HeapIterator(heap.key() + heap.size()); }
// // // };

// #pragma once

// #include "TreeNode.hpp"
// #include <stack>
// #include <queue>
// #include <vector>

// // PreOrderIterator implementation
// template <typename T>
// class PreOrderIterator
// {
// private:
//     std::stack<TreeTreeNode<T> *> stack;

// public:
//     PreOrderIterator(TreeTreeNode<T> *root)
//     {
//         if (root)
//         {
//             stack.push(root);
//         }
//     }

//     T operator*()
//     {
//         return stack.top()->getKey();
//     }

//     PreOrderIterator &operator++()
//     {
//         auto node = stack.top();
//         stack.pop();
//         for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
//         {
//             stack.push(*it);
//         }
//         return *this;
//     }

//     bool operator!=(const PreOrderIterator &other) const
//     {
//         return !stack.empty() || !other.stack.empty();
//     }
// };

// // // PostOrderIterator implementation
// // template <typename T>
// // class PostOrderIterator
// // {
// // private:
// //     std::stack<TreeTreeNode<T> *> stack;
// //     std::stack<bool> visited;

// // public:
// //     PostOrderIterator(TreeTreeNode<T> *root)
// //     {
// //         if (root)
// //         {
// //             stack.push(root);
// //             visited.push(false);
// //         }
// //     }

// //     T operator*()
// //     {
// //         return stack.top()->getKey();
// //     }

// //     PostOrderIterator& operator++() {
// //         while (!stack.empty()) {
// //             auto node = stack.top();
// //             bool node_visited = visited.top();
// //             if (!node_visited) {
// //                 visited.top() = true;
// //                 for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
// //                     stack.push(*it);
// //                     visited.push(false);
// //                 }
// //             } else {
// //                 stack.pop();
// //                 visited.pop();
// //                 if (!stack.empty()) {
// //                     return *this;
// //                 }
// //             }
// //         }
// //         return *this;
// //     }

// //     bool operator!=(const PostOrderIterator &other) const
// //     {
// //         return !stack.empty() || !other.stack.empty();
// //     }
// // };
// template <typename T>
// class PostOrderIterator {
// private:
//     std::stack<TreeTreeNode<T>*> stack;
//     std::stack<bool> visited;

//     void pushLeftmost(TreeTreeNode<T>* node) {
//         while (node) {
//             stack.push(node);
//             visited.push(false);
//             if (!node->children.empty()) {
//                 node = node->children[0]; // Go to the leftmost child
//             } else {
//                 node = nullptr;
//             }
//         }
//     }

// public:
//     PostOrderIterator(TreeTreeNode<T>* root) {
//         if (root) {
//             pushLeftmost(root);
//         }
//     }

//     T& operator*() {
//         return stack.top()->key;
//     }

//     PostOrderIterator& operator++() {
//         while (!stack.empty()) {
//             TreeTreeNode<T>* node = stack.top();
//             bool node_visited = visited.top();
//             stack.pop();
//             visited.pop();

//             if (!node_visited) {
//                 stack.push(node);
//                 visited.push(true);
//                 if (!node->children.empty()) {
//                     for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
//                         pushLeftmost(*it);
//                     }
//                 }
//             } else {
//                 return *this;
//             }
//         }
//         return *this;
//     }

//     bool operator!=(const PostOrderIterator& other) const {
//         return !stack.empty() || !other.stack.empty();
//     }
// };











// // InOrderIterator implementation
// template <typename T>
// class InOrderIterator
// {
// private:
//     std::stack<TreeTreeNode<T> *> stack;
//     void pushLeft(TreeTreeNode<T> *node)
//     {
//         while (node)
//         {
//             stack.push(node);
//             if (node->children.empty())
//                 break;
//             node = node->children[0];
//         }
//     }

// public:
//     InOrderIterator(TreeTreeNode<T> *root)
//     {
//         pushLeft(root);
//     }

//     T &operator*()
//     {
//         return stack.top()->key;
//     }

//     InOrderIterator &operator++()
//     {
//         auto node = stack.top();
//         stack.pop();
//         if (!node->children.empty())
//         {
//             pushLeft(node->children[1]);
//         }
//         return *this;
//     }

//     bool operator!=(const InOrderIterator &other) const
//     {
//         return !stack.empty() || !other.stack.empty();
//     }
// };

// // BFSIterator implementation
// template <typename T>
// class BFSIterator
// {
// private:
//     std::queue<TreeTreeNode<T> *> queue;

// public:
//     BFSIterator(TreeTreeNode<T> *root)
//     {
//         if (root)
//         {
//             queue.push(root);
//         }
//     }

//     T &operator*()
//     {
//         return queue.front()->key;
//     }

//     BFSIterator &operator++()
//     {
//         auto node = queue.front();
//         queue.pop();
//         for (auto &child : node->children)
//         {
//             queue.push(child);
//         }
//         return *this;
//     }

//     bool operator!=(const BFSIterator &other) const
//     {
//         return !queue.empty() || !other.queue.empty();
//     }
// };

// // DFSIterator implementation
// template <typename T>
// class DFSIterator
// {
// private:
//     std::stack<TreeTreeNode<T> *> stack;

// public:
//     DFSIterator(TreeTreeNode<T> *root)
//     {
//         if (root)
//         {
//             stack.push(root);
//         }
//     }

//     T &operator*()
//     {
//         if(stack.empty())
//         {
//             return NULL;
//         }                   
//         return stack.top()->key;
//     }

//     DFSIterator &operator++()
//     {
//         auto node = stack.top();
//         stack.pop();
//         for (auto it = node->children.rbegin(); it != node->children.rend(); ++it)
//         {
//             stack.push(*it);
//         }
//         return *this;
//     }

//     bool operator!=(const DFSIterator &other) const
//     {
//         return !stack.empty() || !other.stack.empty();
//     }
// };

// // HeapIterator implementation
// template <typename T>
// class HeapIterator
// {
// public:
//     HeapIterator(typename std::vector<T>::iterator ptr) : m_ptr(ptr) {}

//     T &operator*() const { return *m_ptr; }
//     typename std::vector<T>::iterator operator->() { return m_ptr; }

//     // Prefix increment
//     HeapIterator &operator++()
//     {
//         ++m_ptr;
//         return *this;
//     }

//     // Postfix increment
//     HeapIterator operator++(int)
//     {
//         HeapIterator tmp = *this;
//         ++(*this);
//         return tmp;
//     }

//     bool operator==(const HeapIterator &other)
//     {
//         return this.m_ptr == other.m_ptr;
//     }

//     bool operator!=(const HeapIterator &other)
//     {
//         return this.m_ptr != other.m_ptr;
//     }

// private:
//     typename std::vector<T>::iterator m_ptr;
// };
