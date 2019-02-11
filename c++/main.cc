#include <iostream>

#include "BST.cc"

int main() {

<<<<<<< HEAD
  BST<int,int> myTree, myTree1;
  std::pair<int,int> n{7,7};
  std::pair<int,int> m{8,8};
  std::pair<int,int> i{1,1};
  std::pair<int,int> j{5,5};
  std::pair<int,int> k{18,18};
=======
  BST<int,int> myTree;

  std::pair<int,int> m{10,100};
  std::pair<int,int> n{11,110};
  std::pair<int,int> i{1,10};
  std::pair<int,int> j{5,50};
  std::pair<int,int> k{18,180};
>>>>>>> master



  myTree.insert(n);
  myTree.insert(m);
  myTree.insert(i);
  myTree.insert(j);
  myTree.insert(k);

  myTree1 = myTree;

<<<<<<< HEAD
  std::cout << myTree1;

  myTree.balance(myTree);

=======
  BST<int,int>::Iterator iter = myTree.find(10);
  std::cout << (*iter).second << std::endl;
>>>>>>> master
  return 0;
}
