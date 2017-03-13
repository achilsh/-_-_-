#include "binary_tree.h"

int main() {
  BTree<int, BTreeNode<int> > aa;
  CreateBTree<int>(aa);
    
  std::cout << "pre order print binary tree: " << std::endl;
  aa.PreOrder(aa.GetRoot());
  
  std::cout << "middle order print binary tree: " << std::endl;
  aa.MiddleOrder(aa.GetRoot());

  std::cout << "post order print binary tree: " << std::endl;
  aa.PostOrder(aa.GetRoot());
  return 0;
}
