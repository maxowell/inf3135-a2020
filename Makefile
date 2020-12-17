default:
	make -s tp3

tp1:	tcv.o
	gcc -Wall -Werror=vla -pedantic -std=c11 -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu tp1.c -o tp1 tcv.o -lcunit

tp3:	malib.o
	gcc -Wall -Werror=vla -pedantic -std=c11 tp3.c -o tp3 tcv.o malib.o -lm outil3.o -lm

clean:
	rm -f tp1 tcv.o tcv.h tp2 malib.o outil3.o tp3

lib:
	curl -s -LJ -o data/tp1.zip --create-dirs https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip > /dev/null && wget -O data/tp.zip -q https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp3.zip || wget -O data/tp.zip -q https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip || wget -O data/tp.zip -q https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	unzip -qq -o data/tp.zip -d ./
	find data/* -delete
	rmdir data

tcv.o:
	make lib

malib.o: outil3.o
	gcc -Wall -Werror=vla -pedantic -std=c11 -c malib.c -o malib.o

outil3.o: tcv.o
	gcc -Wall -Werror=vla -pedantic -std=c11 -c outil3.c -o outil3.o
