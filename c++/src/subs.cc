#include <iostream>

#include "BST.cc"

int main ()
{

  BST<int,int> myTree;

  std::pair<int,int> n(10,100);
  std::pair<int,int> m(11,11);
  std::pair<int,int> o(12,12);
  std::pair<int,int> i(1,1);
  std::pair<int,int> j(100,100);
  std::pair<int,int> k(130,130);
  std::pair<int,int> l(8,8);

  myTree.insert(n);
  myTree.insert(m);
  myTree.insert(o);
  myTree.insert(i);
  myTree.insert(j);
  myTree.insert(k);
  myTree.insert(l);

  int a = myTree[111];
  std::cout << a << std::endl;







  return 0;
}
