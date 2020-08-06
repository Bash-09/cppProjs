CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall

OD = o
OUT = a

$(OUT): $(OD)/main.o $(OD)/collideables.o $(OD)/player.o
	$(CXX) -o $(OUT) $(OD)/main.o $(OD)/player.o $(OD)/collideables.o $(CFLAGS) 

$(OD)/main.o: main.cpp pge.h player.h collideables.h
	$(CXX) -o $(OD)/main.o main.cpp $(CFLAGS) -c


$(OD)/player.o: player.cpp player.h collideables.h $(OD)/collideables.o
	$(CXX) -o $(OD)/player.o player.cpp $(CFLAGS) -c

$(OD)/collideables.o: collideables.cpp collideables.h ray.h
	$(CXX) -o $(OD)/collideables.o collideables.cpp $(CFLAGS) -c


clean:
	rm $(OUT) $(OD)/*.o