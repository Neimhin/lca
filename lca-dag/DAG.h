#include <vector>
#include "Node.h"

class DAG {
  public:
    DAG();

    std::vector<Node*>* roots;

    bool addEdge(int index1, int index2);


    Node* getNode(int index);

    Node* newNode(int index);
    
    std::vector<Node*>* getAncestors(int index);

    std::vector<Node*>* lca(int i1, int i2);
  
  private:
    void getAncestorsRecursive(Node* node, std::vector<Node*>* ancestors);

    bool vectorHasNode(Node* node, std::vector<Node*>* v);

    std::vector<Node*>* getCommon(std::vector<Node*>* ancestors1, std::vector<Node*>* ancestors2);
    

    unsigned int heightToLowest(unsigned int height, Node * node,  std::vector<Node*>* ancestors);

    void getNodesAtHeight(unsigned int height, Node * node, std::vector<Node*>* commonAncestors, std::vector<Node*>* lcas);

};


