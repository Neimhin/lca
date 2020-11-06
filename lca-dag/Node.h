#include <vector>

class Node {
  public:
    int index;

    Node(int index);
    
    std::vector<Node*>* parents;
    std::vector<Node*>* children;

    Node * getNode(int index);

    void addChild(Node *  child);
    
    void addParent(Node * parent);

};

