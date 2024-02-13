all: desafio
	@echo "Instalação concluida!"

desafio: desafio.o
	g++ -w -o desafio desafio.o

desafio.o: desafio.cpp desafio.h
	g++ -c desafio.cpp

clean: rm *.o desafio
