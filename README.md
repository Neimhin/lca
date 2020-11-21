# Lowest Common Ancestor in a Directed Acyclic Graph
Neimhin Robinson Gunning
nrobinso@tcd.ie
Student Number: 16321701

## Requirements
g++
(Any other c++ compiler will probably work, but they are not specified in the makefile)

## Compilation
The normal program can be compiled with:
```bash
cd c++
make prog
```

The testsuite can be compiled with:
```bash
cd c++
make testsuite
```

## Known issuse
This implementation does not check if the graph provided is a DAG. It will probably break in certain scenarios where the graph is cyclic.

