#ifndef _AVLTree_H
#define _AVLTree_H

#define debug

template <typename T>
struct Node {
    T key;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    int height;
};

template <typename T>
class AVLTree {
public:
    Node<T>* root;

    // Constructions
    AVLTree() {
        this->root = NULL;
    }
    AVLTree(Node<T>*& root) {
        this->root = root;
    }

    // Destruction
    static void destroy(Node<T>* node) {
      if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
      }
    }
    ~AVLTree() {
      destroy(this->root);
    }

    // Methods
    void Insert(T key) {
      Node<T>* child = new Node<T>();
      child->key = key;
      child->left = NULL;
      child->right = NULL;
      if (!this->root) {
        this->root = child;
        child->parent = NULL;
      }
      else {
        Node<T>* p = this->root;
        while (p) {
          if (key < p->key) {
            if (!p->left) {
              p->left = child;
              child->parent = p;
              break;
            }
            else {  p = p->left;  }
          }
          else {
            if (!p->right) {
              p->right = child;
              child->parent = p;
              break;
            }
            else {  p = p->right;  }
          }
        }
      }
      // Debugging
      #ifdef Debug
      cout << "Insert: " << key << endl;
      #endif
    }
    void Insert(Node<T>*& child) {
      if (!this->root) {
        this->root = child;
        child->parent = NULL;
      }
      else {
        Node<T>* p = this->root;
        while (p) {
          if (child->key < p->key) {
            if (!p->left) {
              p->left = child;
              child->parent = p;
              break;
            }
            else {  p = p->left;  }
          }
          else {
            if (!p->right) {
              p->right = child;
              child->parent = p;
              break;
            }
            else {  p = p->right;  }
          }
        }
      }
    }
    Node<T>* Search(T x) {
      Node<T>* p = this->root;
      while (p && (p->key != x)) {
        if (x < p->key) {
          p = p->left;
        }
        else {
          p = p->right;
        }
      }
      return p;
    }
    Node<T>* Min() {
      Node<T>* p = this->root;
      while (p->left) {
        p = p->left;
      }
      return p;
    }
    Node<T>* Max() {
      Node<T>* p = this->root;
      while (p->right) {
        p = p->right;
      }
      return p;
    }
    Node<T>* SuccessorOf(T x) {
      Node<T>* node = Search(x);
      if (node->right) {
        Node<T>* rootOfSubtree = node->right;
        AVLTree<T>* subTree = new AVLTree<T>(rootOfSubtree);
        return subTree->Min();
      }
      else {
        Node<T>* p = node->parent;
        while (p && p->key < node->key) {
          p = p->parent;
        }
        return p;
      }
    }
    Node<T>* PredecessorOf(T x) {
      Node<T>* node = Search(x);
      if (node->left) {
        Node<T>* rootOfSubtree = node->left;
        AVLTree<T>* subTree = new AVLTree<T>(rootOfSubtree);
        return subTree->Max();
      }
      else {
        Node<T>* p = node->parent;
        while (p && p->key > node->key) {
          p = p->parent;
        }
        return p;
      }
    }
    bool isLeaf(T x) {
      Node<T>* node = Search(x);
      if (node) {
        if (!node->left && !node->right) {
          return true;
        }
        else {
          return false;
        }
      }
      else {
        return false;
      }
    }
    Node<T>* treeMin(Node<T>* node) {
      Node<T>* p = node->right;
      if (node != NULL) {
        while (p->left != NULL) {
          p = p->left;
        }
        return p;
      }
      return NULL;
    }
    void transPlant(Node<T>* u, Node<T>* v) {
      if (u->parent == NULL) {
        this->root = v;
      }
      else if (u == u->parent->left) {
        u->parent->left = v;
      }
      else {
        u->parent->right = v;
      }
      if (v != NULL) {
        v->parent = u->parent;
      }
    }
    void Remove(T x) {
      Node<T>* node = Search(x);
      if (node->left == NULL) {
        transPlant(node, node->right);
      }
      else if (node->right == NULL) {
        transPlant(node, node->left);
      }
      else {
        Node<T>* p = treeMin(node);
        if (p->parent != node) {
          transPlant(p,p->right);
          p->right = node->right;
          p->right->parent = p;
        }
        transPlant(node,p);
        p->left = node->left;
        p->left->parent = p;
      }
    }

};



#endif
