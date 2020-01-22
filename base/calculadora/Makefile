CPPFLAGS = -Wall -std=c++14
SOURCE = Readme.md

cpp: solver 
	th run solver $(SOURCE) -v

java:
	javac Controller.java
	th run "java Controller" $(SOURCE) -v

list:
	th list $(SOURCE)

vpl:
	th build t.tio $(SOURCE)