CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall

OD = o
OUT = a

$(OUT): $(OD)/main.o
	$(CXX) -o $(OUT) $(OD)/main.o $(CFLAGS)

$(OD)/main.o: main.cpp maths.h pge.h
	$(CXX) -o $(OD)/main.o main.cpp $(CFLAGS) -c



clean:
	rm $(OUT) $(OD)/*.o
