CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall
ODIR = o
OUT = a

$(OUT): $(ODIR)/main.o $(ODIR)/maths.o 
	$(CXX) -o $(OUT) $(ODIR)/main.o$(ODIR)/maths.o$(CFLAGS)

$(ODIR)/main.o: main.cpp 
	$(CXX) -o $(OD)/main.o main.cpp $(CFLAGS) -c

$(ODIR)/maths.o: maths.cpp 
	$(CXX) -o $(OD)/maths.o maths.cpp $(CFLAGS) -c

clean:
	rm $(OUT) $(ODIR)/*.o

