CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall

OD = o
OUT = a

$(OUT): $(OD)/main.o $(OD)/maths.o
	$(CXX) -o $(OUT) $(OD)/main.o $(CFLAGS)

$(OD)/main.o: main.cpp
	$(CXX) -o $(OD)/main.o main.cpp $(CFLAGS) -c

$(OD)/maths.o: lib/maths.cpp maths.h
	$(CXX) -o $(OD)/maths.o lib/maths.cpp $(CFLAGS) -c



clean:
	rm $(OUT) $(OD)/*.o
