freq: freq.c
	cc -o freq.o freq.c

wc: wc.c
	cc -o wc.o wc.c

astyle: wc.c freq.c
	astyle wc.c
	astyle freq.c 

clean:
	rm -f freq.o
	rm -f wc.o
	rm -f freq.c.orig
	rm -f wc.c.orig
