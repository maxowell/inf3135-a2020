default: tp3

tp1:	tcv.o
	gcc -Wall -Werror=vla -pedantic -std=c11 -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu tp1.c -o tp1 tcv.o -lcunit

tp2:	malib.o
	gcc -Wall -Werror=vla -pedantic -std=c11 tp2.c -o tp2 tcv.o malib.o -lm

tp3:	malib.o
	gcc -Wall -Werror=vla -pedantic -std=c11 tp3.c -o tp3 tcv.o malib.o -lm

clean:
	rm -f tp1 tcv.o tcv.h tp2 malib.o tp3

lib:
	curl -LJ -o data/tp1.zip --create-dirs https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -o data/tp1.zip -d ./
	find data/* -delete
	rmdir data

test-tp1a:	tp1
	./tp1

test-tp1b:	tp1
	./tp1 | bash liste.sh

test-tp2:	tp2
	./tp2

tcv.o:
	make lib

malib.o: tcv.o
	gcc -Wall -Werror=vla -pedantic -std=c11  -c malib.c -o malib.o
