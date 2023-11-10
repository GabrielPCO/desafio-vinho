
desafio: desafio.o
	g++ desafio.o -o desafio

desafio.o: desafio.cpp desafio.h
	g++ -c desafio.cpp

clean: rm *.o desafio
