#include "Node.h"


Node::Node(int i){
  this->index = i;
  this->children = nullptr;
  this->parents = nullptr;
}

void Node::addChild(Node * child){
 if(children == nullptr){

  children = new std::vector<Node*>;
 } 

 children->push_back(child);

}

void Node::addParent(Node * parent){
  if(parents == nullptr){
    parents = new std::vector<Node*>;
  }
  
  parents->push_back(parent);
}

Node * Node::getNode(int i){
    if(index == i){
      return this;
    }
    
    if(children == nullptr){
      return nullptr;
    }

    Node * temp;
    for( Node* n : *children ){
      temp = n->getNode(i);
      if( temp != nullptr ){
        return temp;
      }
    }

    return nullptr;
}
