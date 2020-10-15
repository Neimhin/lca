
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

    std::cout << ascii_tree(root);

    std::cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
    std::cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
    std::cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key; 
    std::cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key << std::endl; 

}



