#include <iostream>

#include "BST.cc"

int main() {

  BST<int,int> myTree;

  std::pair<int,int> m{10,100};
  std::pair<int,int> n{11,110};
  std::pair<int,int> i{1,10};
  std::pair<int,int> j{5,50};
  std::pair<int,int> k{18,180};



  myTree.insert(n);
  myTree.insert(m);
  myTree.insert(i);
  myTree.insert(j);
  myTree.insert(k);

  std::cout << myTree;


  return 0;
}
