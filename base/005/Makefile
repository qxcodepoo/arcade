CFLAGS = -Wall -g -std=gnu99
CPPFLAGS = -Wall -g -std=c++14
SOURCE = Readme.md
all: cpp java

cpp: solver
	th run solver $(SOURCE) -v
	rm solver

java:
	javac Solver.java
	th run "java Solver" $(SOURCE) -v
	rm *.class
	
base:
#	sed '/\/\/\_B/,\/\/\_E/d' solver.c > base_c.c
	sed '/\/\/\_B/,\/\/\_E/d' solver.cpp > base.cpp
	sed '/\/\/\_B/,\/\/\_E/d'Solver.java > Solver.java
