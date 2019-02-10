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
  BST<int, int> myTree2;
  
  myTree2 = myTree;
  std::cout << "myTree2\n";
  std::cout << myTree2;
  BST<int, int>myTree3 = myTree2;
  std::cout << "myTree3\n";
  std::cout << myTree3;
  return 0;
}
