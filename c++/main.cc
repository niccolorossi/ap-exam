#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <vector>
#include <cmath>

#include "BST.cc"

int main() {

  BST<int,int> myTree;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  unsigned int Nmax = 10000;
  std::pair<int,int> pair;
  std::ofstream before_balance, after_balance, with_map;

/*
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
*/



  for (unsigned int i = 0; i < Nmax; i++)
  {

    pair.first = i;
    pair.second = i;
    myTree.insert(pair);

  }

  before_balance.open("before_balance.txt");

  for (unsigned int i = 0 ; i < Nmax; i+=50)
  {

   start = std::chrono::system_clock::now();
  for (unsigned int j = 0; j < i; j++)
        myTree.find(j);
   end = std::chrono::system_clock::now();
  auto el_time = end-start;

  if (before_balance)
    before_balance << i <<" "<< log2((std::chrono::duration <double, std::micro> (el_time).count())/double(i)) << std::endl;

  }

  before_balance.close();

  myTree.balance();

  after_balance.open("after_balance.txt");

  for (unsigned int i = 0 ; i < Nmax; i+=50)
  {
   start = std::chrono::system_clock::now();
  for (unsigned int j = 0; j < i; j++)
        myTree.find(j);
  end = std::chrono::system_clock::now();
  auto el_time = end-start;

  if (after_balance)
      after_balance << i <<" "<< log2((std::chrono::duration <double, std::micro> (el_time).count())/double(i)) << std::endl;

  }

  after_balance.close();
  //BST<int,int>::Iterator iter = myTree.find(18);
  //std::cout << (*iter).second << std::endl;
  return 0;
}
