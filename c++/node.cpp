#include <cstddef>
#include "node.h"

Node* newNode(int key){
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
