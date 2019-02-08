#include <iostream>

#include "BST.cc"

int main() {

  BST<int,int> myTree;
  std::pair<int,int> n{7,7};
  std::pair<int,int> m{8,8};
  std::pair<int,int> i{1,1};
  std::pair<int,int> j{5,5};
  std::pair<int,int> k{18,18};



  myTree.insert(n);
  myTree.insert(m);
  myTree.insert(i);
  myTree.insert(j);
  myTree.insert(k);

  std::cout << myTree;


  return 0;
}
