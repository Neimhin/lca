
#define CATCH_CONFIG_MAIN
#include "C:\Users\Hp\home\catch.hpp"
#include <string>

#include "lca.h"
#include "node.h"
#include "draw.h"

#include <fstream>
#include <iterator>
#include <algorithm>

bool compareFiles(const std::string& p1, const std::string& p2) {
  std::ifstream f1(p1,
		   std::ifstream::binary|std::ifstream::ate);
  std::ifstream f2(p2,
		   std::ifstream::binary|std::ifstream::ate);

  if (f1.fail() || f2.fail()) {
    return false; //file problem
  }

  if (f1.tellg() != f2.tellg()) {
    return false; //size mismatch
  }

  //seek back to beginning and use std::equal to compare contents
  f1.seekg(0, std::ifstream::beg);
  f2.seekg(0, std::ifstream::beg);
  return
    std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
               std::istreambuf_iterator<char>(),
               std::istreambuf_iterator<char>(f2.rdbuf()));
}

/*
unsigned int factorial(unsigned int n){
  return n > 1 ? factorial(n-1)*n : 1;
}

TEST_CASE ( "factorials are computed", "[factorial]"){
  REQUIRE ( factorial(0) == 1 );
  REQUIRE ( factorial(1) == 1 );
  REQUIRE ( factorial(3) == 6 );
  REQUIRE ( factorial(4) == 24 );
}
*/

TEST_CASE ( "lowest common ancestors are computed", "[lca]"){

  Node* root = newNode(1);
  root->left = newNode(20);
  root->right = newNode(300);
  root->left->left = newNode(4000);
  root->left->right = newNode(50000);
  root->right->left = newNode(600000);
  root->right->right = newNode(7000000);

  
  std::string expected_draw_tree{
    "-1-300-7000000-?\n" 
    " | |   |\n"         
    " | |   ?\n"         
    " | |\n"             
    " | 600000-?\n"
    " | |\n"
    " | ?\n"
    " |\n"
    " 20-50000-?\n"
    " |  |\n"
    " |  ?\n"
    " |\n"
    " 4000-?\n"
    " |\n"
    " ?\n"
    " "
  };

  std::string draw_tree = ascii_tree(root);
  
  
  //std::string path1 = "expected-ascii-tree";
  //std::string path2 = "ascii-tree";
  //std::ofstream expected_out(path1);
  //expected_out << expected_draw_tree;

  //std::ofstream actual_out(path2);
  //actual_out << draw_tree;
  
  REQUIRE (findLCA( root, 1, 1 )->key == 1 );

  REQUIRE (findLCA ( root, 20, 300)->key == 1 );

  //CHECK ( draw_tree.compare(expected_draw_tree) == 0 ); 
  
  //REQUIRE ( compareFiles(path1,path2) == 0 );
}
