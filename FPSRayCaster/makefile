CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall
ODIR = o
OUT = a

$(OUT): $(ODIR)/barrier.o $(ODIR)/main.o $(ODIR)/engine.o $(ODIR)/world.o $(ODIR)/player.o 
	$(CXX) -o $(OUT) $(ODIR)/barrier.o $(ODIR)/main.o $(ODIR)/engine.o $(ODIR)/world.o $(ODIR)/player.o $(CFLAGS)

$(ODIR)/barrier.o: ./barrier.cpp ./barrier.h ./pge.h ./traceable.h ./collision.h ./pge.h ./ray.h ./pge.h
	$(CXX) -o $(ODIR)/barrier.o ./barrier.cpp $(CFLAGS) -c

$(ODIR)/main.o: ./main.cpp ./engine.h ./pge.h ./barrier.h ./pge.h ./traceable.h ./collision.h ./pge.h ./ray.h ./pge.h
	$(CXX) -o $(ODIR)/main.o ./main.cpp $(CFLAGS) -c

$(ODIR)/engine.o: ./engine.cpp ./engine.h ./pge.h ./barrier.h ./pge.h ./traceable.h ./collision.h ./pge.h ./ray.h ./pge.h ./world.h ./pge.h ./barrier.h ./pge.h ./traceable.h ./collision.h ./pge.h ./ray.h ./pge.h ./trace.h ./pge.h ./traceable.h ./collision.h ./pge.h ./ray.h ./pge.h ./player.h ./pge.h ./world.h ./pge.h ./barrier.h ./pge.h ./traceable.h ./collision.h ./pge.h ./ray.h ./pge.h ./trace.h ./pge.h ./traceable.h ./collision.h ./pge.h ./ray.h ./pge.h
	$(CXX) -o $(ODIR)/engine.o ./engine.cpp $(CFLAGS) -c

$(ODIR)/world.o: ./world.cpp ./world.h ./pge.h ./barrier.h ./pge.h ./traceable.h ./collision.h ./pge.h ./ray.h ./pge.h ./trace.h ./pge.h ./traceable.h ./collision.h ./pge.h ./ray.h ./pge.h
	$(CXX) -o $(ODIR)/world.o ./world.cpp $(CFLAGS) -c

$(ODIR)/player.o: ./player.cpp ./player.h ./pge.h ./world.h ./pge.h ./barrier.h ./pge.h ./traceable.h ./collision.h ./pge.h ./ray.h ./pge.h ./trace.h ./pge.h ./traceable.h ./collision.h ./pge.h ./ray.h ./pge.h
	$(CXX) -o $(ODIR)/player.o ./player.cpp $(CFLAGS) -c

clean:
	rm $(OUT) `find o -name '*.o'`

