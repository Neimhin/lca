#include <string>
#include "node.h"
#include "draw.h"

const int ROOT = 0;
const int LEFT = 1;
const int RIGHT = 2;

std::string ascii_tree(struct Node * root){
	std::string drawing{""};
	std::string prefix{};
	return ascii_tree_rec(prefix,drawing,RIGHT, root);
}
std::string ascii_tree_rec(std::string &prefix, 
			std::string &trunk,
            int context,
			struct Node* root){
	
	if (root == NULL){
		trunk += (context==LEFT? " ":"-");
        trunk += "?\n" + prefix;
		return trunk;
	}

	trunk += (context==LEFT? " ":"-") + std::to_string(root->key);

	std::string new_prefix = prefix + " |";
	trunk = ascii_tree_rec(	new_prefix,
				trunk,
                RIGHT,
				(root->right));

	trunk += "\n" + prefix;
	
	trunk = ascii_tree_rec(	prefix,
				trunk,
                LEFT,
				root->left);
	return trunk;
}



