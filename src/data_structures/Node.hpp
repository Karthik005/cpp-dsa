#ifndef DSA_DS_NODE_H_
#define DSA_DS_NODE_H_

template <class T>
struct node
{
    T val;
    struct node<T> *next;
};

template <class T>
struct b_node
{
    T data;
    b_node<T> *left;
    b_node<T> *right;

    b_node(T data_val)
    {
        data = data_val;
        left = nullptr;
        right = nullptr;
    }
};

#endif //  DSA_DS_NODE_H_
