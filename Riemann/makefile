CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall

OD = o
OUT = a

$(OUT): $(OD)/main.o $(OD)/camera.o $(OD)/riemann.o
	$(CXX) -o $(OUT) $(OD)/main.o $(OD)/camera.o $(OD)/riemann.o $(CFLAGS)

$(OD)/main.o: main.cpp
	$(CXX) -o $(OD)/main.o main.cpp $(CFLAGS) -c

$(OD)/camera.o: camera.cpp camera.h
	$(CXX) -o $(OD)/camera.o camera.cpp $(CFLAGS) -c

$(OD)/riemann.o: riemann.cpp riemann.h
	$(CXX) -o $(OD)/riemann.o riemann.cpp $(CFLAGS) -c

clean:
	rm $(OUT) $(OD)/*.o
