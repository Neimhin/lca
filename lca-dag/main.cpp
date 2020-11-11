
#include "DAG.h"
#include <iostream>

void printNodeVector(std::vector<Node*>* v);

int main(){

  DAG* myDag = new DAG;

  if(myDag != nullptr){
    std::cout << "myDag exists" << std::endl; 
  }

  myDag->addEdge(1, 2);
  myDag->addEdge(2, 3);
  myDag->addEdge(3, 4);
  myDag->addEdge(-4, 4);
  myDag->addEdge(-3, -4);
  myDag->addEdge(3, 5);
  myDag->addEdge(7, 4);
  myDag->addEdge(7, 5);

  printNodeVector(myDag->roots);
  printNodeVector(myDag->getAncestors(4));
  
  std::vector<Node*>* lcas = myDag->lca(5, 4);

  printNodeVector(lcas);

  lcas = myDag->lca(5, 0);

  printNodeVector(lcas);

  lcas = myDag->lca(5, 1);

  printNodeVector(lcas);
}



void printNodeVector(std::vector<Node*>* v){
  for(Node* n : *v){
    std::cout << n->index << " ";
  }
  std::cout << std::endl;
}
