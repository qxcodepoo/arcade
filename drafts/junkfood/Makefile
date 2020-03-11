CPPFLAGS = -Wall -std=c++14 -Werror -g

FOLDER = ../../_posts/
FILE = 0013-01-01-junkfood.md

all: clean solver fall
	./solver < fin.txt > fuser.txt
	diff fall.txt fuser.txt
clean:
	rm -rf solver *.txt
fall:
	@ cat $(FOLDER)$(FILE) | sed -n '/\__begin__/,/\<\__end__/p' | sed '/^\s*$$/d; /^\#/d' > fall.txt
	@ cat fall.txt | sed -n -e '/^\$$/p' | sed 's/^.//' > fin.txt
diff:
	vimdiff fall.txt fuser.txt
