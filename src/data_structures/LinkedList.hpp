#ifndef DSA_DS_LINKEDLIST_H_
#define DSA_DS_LINKEDLIST_H_

#include <iostream>

#include "Node.hpp"

template <class T>
class LinkedList
{
  protected:
    node<T> *root;
    void deleteNext(node<T> *nodeval);

  public:
    node<T> *createNode(T);
    void insertEnd(node<T> *nodeval);
    void insertBeginning(node<T> *nodeval);
    bool deleteNodeWithVal(T val);
    bool search(T val);
    void printList();
    node<T> *getRoot();
    LinkedList();
    ~LinkedList();
};

template <class T>
node<T> *LinkedList<T>::createNode(T value)
{
  node<T> *newNode = new node<T>();
  newNode->val = value;
  newNode->next = nullptr;
  return newNode;
}

template <class T>
void LinkedList<T>::insertEnd(node<T> *nodeval)
{
  node<T> *iter = root;
  if (iter == nullptr)
  {
    root = nodeval;
    return;
  }
  while (iter->next != nullptr)
  {
    iter = iter->next;
  }
  iter->next = nodeval;
}

template <class T>
void LinkedList<T>::insertBeginning(node<T> *nodeval)
{
  nodeval->next = root;
  root = nodeval;
}

template <class T>
bool LinkedList<T>::deleteNodeWithVal(T value)
{
  if (root->val == value)
  {
    deleteNext(nullptr);
    return true;
  }
  node<T> *iter = root;
  while (iter != nullptr && iter->next != nullptr)
  {
    if (iter->next->val == value)
    {
      deleteNext(iter);
      return true;
    }
  }
  return false;
}

template <class T>
bool LinkedList<T>::search(T val)
{
  node<T> *iter = root;
  while (iter != nullptr)
  {
    if (iter->val == val)
    {
      return true;
    }
    iter = iter->next;
  }
  return false;
}

template <class T>
LinkedList<T>::LinkedList()
{
  root = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
  deleteDownNodes(root);
  delete (root);
}

template <class T>
void deleteDownNodes(node<T> *root_node)
{
  if (root_node->next == nullptr)
  {
    return;
  }
  deleteDownNodes(root_node->next);
  delete root_node->next;
}

template <class T>
void LinkedList<T>::printList()
{
  node<T> *iter = root;
  while (iter != nullptr)
  {
    std::cout << iter->val << " " << std::endl;
    iter = iter->next;
  }
}

template <class T>
node<T> *LinkedList<T>::getRoot()
{
  return root;
}

template <class T>
void LinkedList<T>::deleteNext(node<T> *nodeval)
{
  node<T> *tmp;
  if (nodeval == nullptr)
  {
    tmp = root;
    root = root->next;
    delete tmp;
    return;
  }
  tmp = nodeval->next;
  if (tmp != nullptr)
  {
    nodeval->val = tmp->val;
    nodeval->next = tmp->next;
  }
  delete tmp;
}

#endif //DSA_DS_LINKEDLIST_H_
