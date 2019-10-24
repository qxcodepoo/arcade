CPPFLAGS = -Wall -std=c++14
SOURCE = ../../_posts/0002-01-01-tamagotchi.md 

all: solver 
	th.py run solver $(SOURCE) -v

list:
	th.py list $(SOURCE)

vpl:
	th.py build t.vpl $(SOURCE)
	../bin/filter_md.sh $(SOURCE) > t.md
