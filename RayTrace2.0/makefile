CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall

OD = o
OUT = a

$(OUT): $(OD)/main.o $(OD)/renderer.o $(OD)/collideables.o
	$(CXX) -o $(OUT) $(OD)/main.o $(OD)/renderer.o $(OD)/collideables.o $(CFLAGS)

$(OD)/main.o: main.cpp maths.h
	$(CXX) -o $(OD)/main.o main.cpp $(CFLAGS) -c

$(OD)/renderer.o: renderer.cpp renderer.h collideables.h
	$(CXX) -o $(OD)/renderer.o renderer.cpp $(CFLAGS) -c

$(OD)/collideables.o: collideables.cpp collideables.h ray.h
	$(CXX) -o $(OD)/collideables.o collideables.cpp $(CFLAGS) -c

clean:
	rm $(OUT) $(OD)/*.o
