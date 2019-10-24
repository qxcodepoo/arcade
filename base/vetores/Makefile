CFLAGS = -Wall -g -std=gnu99
CPPFLAGS = -Wall -g -std=c++14
SOURCE = ../../_posts/0001-02-01-vetores.md 
all: vpl c cpp tbase

c: solver
	th.py run solver $(SOURCE) -v

cpp: solver_cpp
	th.py run solver_cpp $(SOURCE) -v

java_solver:
	cp Controller_solver.java Controller.java
	javac Controller.java
	th.py run "java Controller" $(SOURCE) -v

java_base: base
	javac Controller.java
	th.py run "java Controller" $(SOURCE) -v

vpl: $(SOURCE)
	th.py build t.vpl $(SOURCE)
	sed -n '/^```bash/,/^```/p' $(SOURCE) > t.md

base:
	sed '/\/\/\_B/,\/\/\_E/d' solver_c.c > base_c.c
	sed '/\/\/\_B/,\/\/\_E/d' solver_cpp.cpp > base_cpp.cpp
	sed '/\/\/\_B/,\/\/\_E/d' Controller_solver.java > Controller.java

tbase: mbase base base_cpp
	th.py run base $(SOURCE) -q
	th.py run base_cpp $(SOURCE) -q
