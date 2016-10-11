readable: lLists.c
	gcc lLists.c -o readable

run: readable
	./readable