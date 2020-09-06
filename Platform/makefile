CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall
ODIR = o
OUT = a

$(OUT): $(ODIR)/main.o $(ODIR)/platform_Linux.o $(ODIR)/engine.o 
	$(CXX) -o $(OUT) $(ODIR)/main.o $(ODIR)/platform_Linux.o $(ODIR)/engine.o $(CFLAGS)

$(ODIR)/main.o: ./main.cpp ./maths.h ./platform_Linux.h ./platform.h
	$(CXX) -o $(ODIR)/main.o ./main.cpp $(CFLAGS) -c

$(ODIR)/platform_Linux.o: ./platform_Linux.cpp ./platform_Linux.h ./platform.h
	$(CXX) -o $(ODIR)/platform_Linux.o ./platform_Linux.cpp $(CFLAGS) -c

$(ODIR)/engine.o: ./engine.cpp ./engine.h
	$(CXX) -o $(ODIR)/engine.o ./engine.cpp $(CFLAGS) -c

clean:
	rm $(OUT) `find o -name '*.o'`

