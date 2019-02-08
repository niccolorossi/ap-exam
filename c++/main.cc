#include <iostream>

#include "BST.cc"

int main() {

  BST<int,int> myTree;
  std::pair<int,int> m{10,10};
  std::pair<int,int> n{11,11};
  std::pair<int,int> i{1,1};
  std::pair<int,int> j{5,5};
  std::pair<int,int> k{18,18};

  myTree.insert(m);
  myTree.insert(n);
  myTree.insert(i);
  myTree.insert(j);
  myTree.insert(k);

  for(const auto& x : myTree)
    std::cout << x << std::endl;

  return 0;
}
