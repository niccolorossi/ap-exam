#include <iostream>

#include "BST.cc"

int main() {
  BST<int,int> myTree;
  std::pair<int,int> n{7,7};
  std::pair<int,int> m{8,8};
  myTree.Insert(n);
  myTree.Insert(m);


  return 0;
}
