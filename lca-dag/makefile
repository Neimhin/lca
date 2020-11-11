CC=g++

prog: main.cpp DAG.cpp Node.cpp
	$(CC) -o prog -Wall -Wextra -pedantic Node.cpp DAG.cpp main.cpp -I.

testsuite: catch.cpp DAG.cpp Node.cpp
	$(CC) -o testsuite -Wall -Wextra -pedantic Node.cpp DAG.cpp catch.cpp -I.
