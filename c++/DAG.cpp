#include <vector>
#include "DAG.h"
#include <algorithm>
#include <climits>

#include <iostream>

std::vector<Node*>* DAG::lca(int index1, int index2){
  std::vector<Node*>* lcas = new std::vector<Node*>;
  
  Node * n1 = getNode(index1);
  Node * n2 = getNode(index2);
  
  std::vector<Node*>* ancestors1 = getAncestors(index1);
  std::vector<Node*>* ancestors2 = getAncestors(index2);


  if(ancestors1 == nullptr || ancestors2 == nullptr){
    return lcas;
  }

  std::vector<Node*>* commonAncestors = getCommon(ancestors1, ancestors2);

  if(vectorHasNode(n1, commonAncestors)){
    lcas->push_back(n1);
    return lcas;
  }

  if(vectorHasNode(n2, commonAncestors)){
    lcas->push_back(n2);
    return lcas;
  }

  unsigned int nearest = heightToLowest(UINT_MAX, n1, commonAncestors);

  getNodesAtHeight(nearest, n1, commonAncestors, lcas);

  return lcas;
}

void DAG::getNodesAtHeight(unsigned int height, Node * node, std::vector<Node*>* commonAncestors, std::vector<Node*>* lcas){
  
  if(height == 0){
    if(vectorHasNode(node, commonAncestors)){
        lcas->push_back(node);
    }
  }

  if((node->parents) == nullptr)    return;

  for(Node * n : *(node->parents))  getNodesAtHeight (height - 1, n, commonAncestors, lcas); 

  return;
}

unsigned int DAG::heightToLowest(unsigned int height, Node * node, std::vector<Node*>* ancestors){
  
  if(vectorHasNode(node, ancestors)){
    return height + 1;
  }

  if(node->parents == nullptr){
    return UINT_MAX;
  }
  
  unsigned int newheight;
  
  unsigned int lowest_found = UINT_MAX;
  
  for(Node * n : *(node->parents)){
    newheight = heightToLowest(height + 1, n, ancestors);
    if(newheight < lowest_found){
      lowest_found = newheight;
    }
  }
  
  return lowest_found;
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
std::vector<Node*>* DAG::getCommon(std::vector<Node*>* ancestors1, std::vector<Node*>* ancestors2){
  std::vector<Node*>* common = new std::vector<Node*>;

  for( Node * n : *ancestors1){
    if(vectorHasNode(n, ancestors2)){
            common->push_back(n); 
    }
  }
  return common;
}

DAG::DAG(){
  roots = new std::vector<Node*>;
}



