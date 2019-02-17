#include <iostream>

#include "BST.h"

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

  std::cout << "myTree\n" << myTree << std::endl;
  BST<int,int> myTree2 = myTree;
  std::cout << "myTree2 after copy ctor\n" << myTree2 << std::endl;
  myTree2.insert(i);
  std::cout << "myTree after pair inserted in myTree2\n" << myTree << std::endl;
  BST<int,int> myTree3;
  myTree3 = myTree2;
  std::cout << "myTree3 after copy assignment\n" << myTree3 << std::endl;
  int a = myTree[10];
  std::cout << "testing []: should be 100\n" << a << std::endl;

  myTree.clear();
  std::cout << "myTree after clear()\n" << myTree;



  myTree3.insert(i);
  myTree3.insert(j);
  myTree3.insert(k);
  myTree3.insert(l);
  std::cout << "myTree3 after various insertions\n" << myTree3 << std::endl;







  return 0;
}
