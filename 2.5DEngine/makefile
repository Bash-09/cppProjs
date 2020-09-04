CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall
ODIR = o
OUT = a

$(OUT): $(ODIR)/main.o $(ODIR)/collideables.o $(ODIR)/player.o 
	$(CXX) -o $(OUT) $(ODIR)/main.o $(ODIR)/collideables.o $(ODIR)/player.o $(CFLAGS)

$(ODIR)/main.o: ./main.cpp ./pge.h ./player.h ./pge.h ./collideables.h ./pge.h ./ray.h ./pge.h ./collideables.h ./pge.h ./ray.h ./pge.h
	$(CXX) -o $(ODIR)/main.o ./main.cpp $(CFLAGS) -c

$(ODIR)/collideables.o: ./collideables.cpp ./collideables.h ./pge.h ./ray.h ./pge.h ./ray.h ./pge.h
	$(CXX) -o $(ODIR)/collideables.o ./collideables.cpp $(CFLAGS) -c

$(ODIR)/player.o: ./player.cpp ./player.h ./pge.h ./collideables.h ./pge.h ./ray.h ./pge.h
	$(CXX) -o $(ODIR)/player.o ./player.cpp $(CFLAGS) -c

clean:
	rm $(OUT) `find o -name '*.o'`

