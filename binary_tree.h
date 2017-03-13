#pragma once 
#include <iostream>

template<class T>
class BTreeNode {
  public:
    BTreeNode();
    BTreeNode(const T& _data);
    BTreeNode(const T& _data, BTreeNode<T>* lchild, 
        BTreeNode<T>* rchild);
    //
    virtual ~BTreeNode();
    T GetData() const {return _bt_data;}
    void SetData(const T& data) { _bt_data = data;}
    //
    BTreeNode<T>* &GetLeftNode() { 
      return _lchild;
    }
    BTreeNode<T>* &GetRighNode() {
      return _rchild;
    }
    //
    T _bt_data;
    BTreeNode<T>* _lchild;
    BTreeNode<T>* _rchild;
};

template <class T, class BTNode>
class BTree {
  public:
    BTree();
    BTree(const T& data);
    BTree(const BTree<T,BTNode>& node);
    virtual ~BTree();
    //
    bool IsEmpty() const { bool ret = _bt_root==NULL?true:false;
      return ret;
    }
    BTNode* GetRoot() const {return _bt_root;}
    void MakeTree(const T& _dat,const BTree<T,BTNode>& _lc,
        const BTree<T, BTNode>& _rc);
    //
    void PreOrder(BTNode* _root) const;
    void MiddleOrder(BTNode* _root) const;
    void PostOrder(BTNode* _root) const;
    //
  protected:
    BTNode* _bt_root;    
    BTNode* CopyTree(BTNode* root);
    void DestoryTree(BTNode* &root);
};

template<class T>
void CreateBTree(BTree<T, BTreeNode<T> > & btee);



#include "binary_tree.inl"
