CPPFLAGS = -Wall -std=c++14

FOLDER = ../../_posts/
FILE = 0011-01-01-contato.md

all: clean solver fall
	./solver < fin.txt > fuser.txt
	diff fall.txt fuser.txt

clean:
	rm -rf solver *.txt

fall:
	@ cat $(FOLDER)$(FILE) | sed -n '/\__begin__/,/\<\__end__/p' | sed '/^\s*$$/d; /^\#/d' > fall.txt
	@ cat fall.txt | sed -n -e '/^\$$/p' | sed 's/^.//' > fin.txt