#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <vector>
#include <cmath>
#include <map>

#include "BST.cc"

template <class TM, class K, class V>
void Timing (std::ofstream& nome_file, TM tree, std::vector<std::pair<K,V>> v){


  for (unsigned int i = 0 ; i < v.size(); i+=50)
  {

   auto start = std::chrono::system_clock::now();
  for (unsigned int j = 0; j < i; j++)
        tree.find(v[j].first);
   auto end = std::chrono::system_clock::now();

  auto el_time = end-start;
  //double eltime = (std::chrono::duration <double, std::micro> (el_time).count())/double(i);
  double log_el_time = log2((std::chrono::duration <double, std::micro> (el_time).count())/double(i));

  if (nome_file)
    nome_file << i << " " <<  log_el_time << std::endl;

  }



}

int main() {

  unsigned int Nmax = 10000;
  BST<int,int> myTree;
  std::map<int,int> myMap;

  std::vector<std::pair<int, int>> v(Nmax);
  std::ofstream before_balance, after_balance, time_map;

  for (unsigned int i = 0; i < Nmax; i++)
  {
    v[i].first = i;
    v[i].second = i;
    myTree.insert(v[i]);
    myMap.insert(v[i]);
  }

  before_balance.open("before_balance.txt");
  Timing(before_balance, myTree, v);
  before_balance.close();

  myTree.balance();

  after_balance.open("after_balance.txt");
  Timing(after_balance, myTree, v);
  after_balance.close();

  time_map.open("time_map.txt");
  Timing(time_map, myMap, v);
  time_map.close();

  BST<double,double> doubleTree;
  std::map<int,int> doubleMap;

  std::vector<std::pair<double, double>> doublev(Nmax);
  std::ofstream before_balance_double, after_balance_double, time_map_double;

  for (unsigned int i = 0; i < Nmax; i++)
  {
    doublev[i].first = i;
    doublev[i].second = i;
    doubleTree.insert(v[i]);
    doubleMap.insert(v[i]);
  }

  before_balance_double.open("before_balance_double.txt");
  Timing(before_balance_double, doubleTree, v);
  before_balance_double.close();

  doubleTree.balance();

  after_balance_double.open("after_balance_double.txt");
  Timing(after_balance_double, doubleTree, v);
  after_balance_double.close();

  time_map_double.open("time_map_double.txt");
  Timing(time_map_double, doubleMap, v);
  time_map_double.close();
  return 0;
}
