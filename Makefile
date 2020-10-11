make:	tcv.h
	gcc -Wall -Werror=vla -pedantic -std=c11 -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu tp1.c -o tp1 tcv.o -lcunit

clean:
	rm -f tp1 tcv.o tcv.h

lib:
	mkdir data
	curl -LJ -o data/tp1.zip https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -o data/tp1.zip -d ./
	rm -rf data

test:
	./tp1
