#include <vector>
#include "DAG.h"
#include <algorithm>


#include <iostream>





vector<Node*>* DAG::lca(int index1, int index2){
  Node * n1 = getNode(index1);
  Node * n2 = getNode(index2);
  
  std::vector<Node*>* ancestors1 = getAncestors(index1);
  std::vector<Node*>* ancestors2 = getAncestors(index2);


  if(ancestors1 == nullptr || ancestors2 == nullptr){
    return nullptr;
  }

  std::vector<Node*>* commonAncestors = getCommon(ancestors1, ancestors2);
  
  int nearest = heightToLowest(0, ancestors1, commonAncestors);

  
}

int heightToLowest(int height, Node * node, std::vector<Node*>* ancestors){
  
  if(vectorHasNode(node, ancestors){
      return height;
  }
  height++;

  for(Node
}


std::vector<Node*>* DAG::getAncestors(int index){
  
  Node * node = getNode(index);
  if(node == nullptr){
    return nullptr;
  }

  std::vector<Node *>* ancestors = new std::vector<Node*>;


  ancestors->push_back(node);
  
  std::vector<Node*>* parents = node->parents;

  if(parents == nullptr){
    return ancestors;
  }

  for(Node * n : *parents ){
    
    getAncestorsRecursive(n, ancestors);

  }

  return ancestors;

}

void DAG::getAncestorsRecursive( Node* node, std::vector<Node*>* ancestors){
 
  if(vectorHasNode(node, ancestors)){
    return;
  }

  ancestors->push_back(node);

  if( node->parents == nullptr){
    return;
  }

  for(Node * n : *(node->parents)){
      getAncestorsRecursive(n, ancestors);
  }
}

bool DAG::vectorHasNode(Node* node, std::vector<Node*>* v){
  if( std::find(v->begin(),
                v->end(),
                node) != v->end()){
    return true;
  }
  return false;
}


bool DAG::addEdge(int index1, int index2){
  
  std::cout << "making edge " << index1 << " " << index2;  

  Node* parent = getNode(index1);
  Node* child = getNode(index2);
  
  if (parent == nullptr){
    parent = newNode(index1);
    roots->push_back(parent);
  }

  if (child == nullptr){
    child = newNode(index2);
  }
  // if child is one of the roots, it's no longer one of the roots 

  auto i = std::find(roots->begin(), roots->end(),child);
  if(i != roots->end()){
    roots->erase(i);
  }

  parent->addChild(child);
  child->addParent(parent);
 
  std::cout << " done" << std::endl;

  return true;
}


Node* DAG::newNode(int index){
  Node * temp = new Node(index);

  return temp;
}


Node * DAG::getNode(int index){
  Node * temp = nullptr;
  for( Node* n : *roots ){
    temp = n->getNode(index);
    if(temp != nullptr){
      return temp;
    }
  }
  return nullptr;
}
std::vector<Node*>* getCommon(std::vector<Node*>* ancestors1, std::vector<Node*>* ancestors2){
  vector<Node*>* common = new vector<Node*>;

  for( Node * n : *ancestors1){
    if(vectorHasNode(n, ancestors2){
            common->push_back(n); 
    }
  }
  return common;
}

DAG::DAG(){
  roots = new std::vector<Node*>;
}



