
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

  printNodeVector(myDag->roots);
  printNodeVector(myDag->getAncestors(4));

}



void printNodeVector(std::vector<Node*>* v){
  for(Node* n : *v){
    std::cout << n->index << " ";
  }
  std::cout << std::endl;
}
