CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall
ODIR = o
OUT = a

$(OUT): $(ODIR)/ball.o $(ODIR)/main.o $(ODIR)/world.o 
	$(CXX) -o $(OUT) $(ODIR)/ball.o $(ODIR)/main.o $(ODIR)/world.o $(CFLAGS)

$(ODIR)/ball.o: ./ball.cpp ./ball.h ./pge.h
	$(CXX) -o $(ODIR)/ball.o ./ball.cpp $(CFLAGS) -c

$(ODIR)/main.o: ./main.cpp ./pge.h ./world.h ./ball.h ./pge.h
	$(CXX) -o $(ODIR)/main.o ./main.cpp $(CFLAGS) -c

$(ODIR)/world.o: ./world.cpp ./world.h ./ball.h ./pge.h
	$(CXX) -o $(ODIR)/world.o ./world.cpp $(CFLAGS) -c

clean:
	rm $(OUT) `find o -name '*.o'`

