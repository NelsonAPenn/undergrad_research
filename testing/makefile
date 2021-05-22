HEADERS=polynomial.h matrix.h
OBJECTS=cycleEmbeddings.cpp main.cpp
all:$(OBJECTS) $(HEADERS)
	g++ -std=c++11 -g -o generatingFunction main.cpp -lgmp -lgmpxx
	g++ -std=c++11 -g -o cycleEmbeddings cycleEmbeddings.cpp -lgmp -lgmpxx
clean:
	rm -i *.o generatingFunction cycleEmbeddings 
