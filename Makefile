tp1:	tcv.h
	gcc -Wall -Werror=vla -pedantic -std=c11 -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu tp1.c -o tp1 tcv.o -lcunit

tp2:	tp2.c
	gcc -Wall -Werror=vla -pedantic -std=c11 tp2.c -o tp2

clean:
	rm -f tp1 tcv.o tcv.h tp2

lib:
	mkdir data
	curl -LJ -o data/tp1.zip https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -o data/tp1.zip -d ./
	rm -rf data

test-tp1a:	tp1
	./tp1

test-tp1b:	tp1
	./tp1 | bash liste.sh

test-tp2:	tp2
	./tp2

tcv.h:
	make lib
