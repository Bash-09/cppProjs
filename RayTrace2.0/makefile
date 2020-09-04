CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall
ODIR = o
OUT = a

$(OUT): $(ODIR)/renderer.o $(ODIR)/main.o $(ODIR)/collideables.o 
	$(CXX) -o $(OUT) $(ODIR)/renderer.o $(ODIR)/main.o $(ODIR)/collideables.o $(CFLAGS)

$(ODIR)/renderer.o: ./renderer.cpp ./renderer.h ./pge.h ./ray.h ./maths.h ./collideables.h ./ray.h ./maths.h
	$(CXX) -o $(ODIR)/renderer.o ./renderer.cpp $(CFLAGS) -c

$(ODIR)/main.o: ./main.cpp ./pge.h ./renderer.h ./pge.h ./ray.h ./maths.h ./collideables.h ./ray.h ./maths.h
	$(CXX) -o $(ODIR)/main.o ./main.cpp $(CFLAGS) -c

$(ODIR)/collideables.o: ./collideables.cpp ./collideables.h ./ray.h ./maths.h
	$(CXX) -o $(ODIR)/collideables.o ./collideables.cpp $(CFLAGS) -c

clean:
	rm $(OUT) `find o -name '*.o'`

