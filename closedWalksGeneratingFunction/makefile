HEADERS=polynomial.h matrix.h
OBJECTS=cycleEmbeddings.cpp
ur:$(OBJECTS) $(HEADERS) 
	g++ -std=c++11 -o $@ $^ -lgmp -lgmpxx
clean:
	rm -i *.o ur 
