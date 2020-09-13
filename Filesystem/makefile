CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall
ODIR = o
OUT = a

$(OUT): $(ODIR)/main.o 
	$(CXX) -o $(OUT) $(ODIR)/main.o $(CFLAGS)

$(ODIR)/main.o: ./main.cpp ./exportable.h
	$(CXX) -o $(ODIR)/main.o ./main.cpp $(CFLAGS) -c

clean:
	rm $(OUT) `find o -name '*.o'`

