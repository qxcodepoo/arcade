CPPFLAGS = -Wall -std=c++14
SOURCE = Readme.md

all: cpp java vpl

open:
	code $(SOURCE)

cpp: solver 
	th run solver $(SOURCE) -v

java:
	javac Solver.java
	th run "java Solver" $(SOURCE) -v

list:
	th list $(SOURCE)

vpl:
	th build tests.vpl $(SOURCE)