HEADERS=polynomial.h matrix.h
OBJECTS=cycleEmbeddings.cpp
ur:$(OBJECTS) $(HEADERS) 
	g++ -std=c++11 -g -o $@ $^ -lgmp -lgmpxx
clean:
	rm -i *.o ur 
