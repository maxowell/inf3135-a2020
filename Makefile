make:	tcv.h
	gcc -Wall -Werror=vla -pedantic -std=c11 tp1.c -o tp1

clean:
	rm -f tp1 tcv.o tcv.h

lib:
	mkdir data
	curl -LJ -o data/tp1.zip https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -o data/tp1.zip -d ./
	rm -rf data

test:
	./tp1
