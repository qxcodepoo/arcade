CPPFLAGS = -Wall -std=c++14
SOURCE = Readme.md

all: cpp java

cpp: solver 
	th run solver $(SOURCE) -v
	rm solver

java:
	javac Controller.java
	th run "java Controller" $(SOURCE) -v
	rm -f *.class
