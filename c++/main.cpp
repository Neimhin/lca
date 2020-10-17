#include <iostream>
#include <vector>
#include <string>

#include "lca.h"
#include "node.h"
#include "draw.h"


int main(){

    Node* root = newNode(2323);
    root->left = newNode(255433453);
    root->right = newNode(343);
    root->left->left = newNode(7484);
    root->left->right = newNode(3453445);
    root->right->left = newNode(346);
    root->right->right = newNode(7); 
    root->right->right->left = newNode(8345);

    std::string draw_tree = ascii_tree(root);
    std::cout << draw_tree;

    std::cout << "LCA(346, 8345) = " << findLCA(root, 346, 8345)->key;
    std::cout << "\nLCA(7, 343) " << findLCA(root, 7, 343)->key;
    std::cout << "\nLCA(2323, 7484) = " << findLCA(root, 2323, 7484)->key; 
    std::cout << "\nLCA(7, 346) = " << findLCA(root, 7, 346)->key << std::endl; 

}



