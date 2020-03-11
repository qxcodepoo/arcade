CPPFLAGS = -Wall -std=c++14
SOURCE = Readme.md

all: cpp java

open:
	code $(SOURCE)

cpp: solver 
	th run solver $(SOURCE) -v
	rm solver

java:
	javac Solver.java
	th run "java Solver" $(SOURCE) -v
	rm Solver.class
