#include <iostream>

template<class T>
BTreeNode<T>::BTreeNode():_lchild(NULL), _rchild(NULL) {
  //
}

template<class T>
BTreeNode<T>::BTreeNode(const T& _data):_bt_data(_data), 
  _lchild(NULL), _rchild(NULL) {

}

template<class T>
BTreeNode<T>::~BTreeNode() {
  _lchild = _rchild = NULL;
}

template<class T>
BTreeNode<T>::BTreeNode(const T& _data, 
    BTreeNode<T>* lchild,BTreeNode<T>* rchild):_bt_data(_data),
  _lchild(lchild), _rchild(rchild) {
  //
}

//
//
//
//
template <class T, class BTNode>
BTree<T, BTNode>::BTree():_bt_root(NULL) {
  //
}
template <class T, class BTNode>
BTree<T, BTNode>::BTree(const T& data):_bt_root(new BTNode(data)) {
  //
}
  

template <class T, class BTNode>
BTree<T, BTNode>::BTree(const BTree<T,BTNode>& node) {
  _bt_root = CopyTree(node._bt_root);
}

template <class T, class BTNode>
BTree<T, BTNode>::~BTree() {
  DestoryTree(_bt_root);
}

template<class T, class BTNode>
BTNode*BTree <T,BTNode>::CopyTree(BTNode* root) {
  if (root) {
    BTNode* node = new BTNode(root->GetData());
    node->GetLeftNode() = CopyTree(root->GetLeftNode());
    node->GetRighNode() = CopyTree(root->GetRighNode());
    return node;
  } 
  return NULL;
}

template<class T, class BTNode>
void BTree<T,BTNode>::DestoryTree(BTNode* &root) {
  if (root == NULL) {
    return ;
  }
  DestoryTree(root->GetLeftNode());
  DestoryTree(root->GetRighNode());
  delete root;
  root = NULL;
}

template<class T, class BTNode>
void BTree<T,BTNode>:: MakeTree(const T& _dat,
    const BTree<T,BTNode>& _lc,const BTree<T, BTNode>& _rc) {
  _bt_root = new BTNode(_dat);
  _bt_root->GetLeftNode() = CopyTree(_lc._bt_root);
  _bt_root->GetRighNode() = CopyTree(_rc._bt_root);
}

template<class T, class BTNode>
void BTree<T,BTNode>::PreOrder(BTNode* _root) const {
  if (_root) {
    std::cout << "data: " << _root->GetData() << std::endl;
    PreOrder(_root->GetLeftNode());
    PreOrder(_root->GetRighNode());
  }
}

template<class T, class BTNode>
void BTree<T,BTNode>::MiddleOrder(BTNode* _root) const {
  if (_root) {
    MiddleOrder(_root->GetLeftNode());
    std::cout << "middle val: " << _root->GetData() << std::endl;
    MiddleOrder(_root->GetRighNode());
  }
}

template<class T, class BTNode>
void BTree<T,BTNode>::PostOrder(BTNode* _root) const {
  if (_root) {
    PostOrder(_root->GetLeftNode());
    PostOrder(_root->GetRighNode());
    std::cout << "post val: " << _root->GetData() << std::endl;
  }
}
/////////////////////////
template<class T>
void CreateBTree(BTree<T,BTreeNode<T> >& btee) {
  std::cout << "input val: " << std::endl;
  T a, b, c, d,  e,f,g;
  std::cin >> a >> b >> c >> d >> e >> f >> g;
  BTree<T,BTreeNode<T> > bb, cc, dd(d), ee(e), ff,gg(g), def_node;
  //
  bb.MakeTree(b,dd,ee);
  ff.MakeTree(f, def_node, gg);
  cc.MakeTree(c, ff, def_node);
  btee.MakeTree(a, bb, cc);
  
}







