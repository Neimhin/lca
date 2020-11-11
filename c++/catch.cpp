
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <iostream>
#include <algorithm>


#include "DAG.h"

bool vectorHasInt(int i, std::vector<int>* v);

TEST_CASE ( "lowest common ancestors in a directed acyclic graph are computed", "[lca-dag]"){

  DAG* myDag = new DAG;


  REQUIRE( myDag->getNode(0) == nullptr);

  myDag->addEdge(1, 2);
  myDag->addEdge(2, 3);
  myDag->addEdge(3, 4);
  myDag->addEdge(-4,4);
  myDag->addEdge(-3,-4);
  myDag->addEdge(3, 5);
  myDag->addEdge(7, 4);
  myDag->addEdge(7, 5);
  myDag->addEdge(7, 6);
  myDag->addEdge(8, 5);
  myDag->addEdge(8, 6);
  myDag->addEdge(9, 5);
  myDag->addEdge(9, 6);

  REQUIRE( myDag->getNode(1)->index == 1 );

  REQUIRE( myDag->getNode(-4)->index == -4 ); 
  REQUIRE( myDag->getNode(0) == nullptr);

  std::vector<Node*>* lca_3_2 = myDag->lca(3, 2);

  std::vector<int>* lca_3_2_answer = new std::vector<int>;
  lca_3_2_answer->push_back(2);
  
  for(Node* n : *lca_3_2){
    REQUIRE( vectorHasInt(n->index, lca_3_2_answer));
  }
  delete lca_3_2;
  delete lca_3_2_answer;
  
  REQUIRE( myDag->lca(3, 0)->size() == 0);

  std::vector<int>* lca_5_6_answer = new std::vector<int>;
  lca_5_6_answer->push_back(7);
  lca_5_6_answer->push_back(8);
  lca_5_6_answer->push_back(9);

  std::vector<Node*>* lca_5_6 = myDag->lca(5,6);
  
  for(Node * n : *lca_5_6){
    CHECK( vectorHasInt(n->index, lca_5_6_answer));
  }
}



bool vectorHasInt(int i, std::vector<int>* v){
  auto location = std::find(v->begin(), v->end(),i);
  if(location == v->end()){
    return false;
  }
  return true;

}
