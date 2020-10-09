
#include <iostream>
#include <vector>
#include <string>



struct Node{
    int key;
    struct Node *left, *right;
};

Node* newNode(int key){
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *findLCA(struct Node* root, int n1, int n2){

    if (root == NULL) return NULL;

    if (root->key == n1 || root->key == n2)
        return root;

    Node *left_lca = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca) return root;

    return (left_lca != NULL)? left_lca: right_lca;
}

std::string ascii_tree_rec(std::string &prefix, 
			std::string &trunk,
			struct Node* root){
	
	if (root == NULL){
		trunk += + "-X\n" + prefix;
		return trunk;
	}

	trunk += "-" + std::to_string(root->key);

	std::string new_prefix = prefix + " |";
	trunk = ascii_tree_rec(	new_prefix,
				trunk,
				(root->right));

	trunk += "\n" + prefix + " ";
	
	trunk = ascii_tree_rec(	prefix,
				trunk,
				root->left);
	return trunk;
}
std::string ascii_tree(struct Node * root){
	std::string drawing{""};
	std::string prefix{};
	return ascii_tree_rec(prefix,drawing, root);
}


int main(){

    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7); 
    std::cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key;
    std::cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->key;
    std::cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->key; 
    std::cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->key << std::endl; 

    std::cout << ascii_tree(root);
}



