
#define CATCH_CONFIG_MAIN
#include "/mnt/c/Users/Hp/home/catch.hpp"

/*
#include "lca.h"
#include "node.h"
#include "draw.h"
*/

unsigned int factorial(unsigned int n){
  return n > 1 ? factorial(n-1)*n : 1;
}


TEST_CASE ( "factorials are computed", "[factorial]"){
  REQUIRE ( factorial(0) == 1 );
  REQUIRE ( factorial(1) == 1 );
  REQUIRE ( factorial(3) == 6 );
  REQUIRE ( factorial(4) == 24 );
}
