CXX = g++-10
CFLAGS = -g -Wall -lGL -lpthread -lstdc++fs -std=c++17 -lSDL2 -lSDL2 -I/home/ethan/c++Proj/Engy/src
ODIR = bin
OUT = a

$(OUT): $(ODIR)/Applications/Example/Example.o $(ODIR)/src/Event/Keyboard/Keyboard.o $(ODIR)/Main.o 
	$(CXX) -o $(OUT) $(ODIR)/Applications/Example/Example.o $(ODIR)/src/Event/Keyboard/Keyboard.o $(ODIR)/Main.o $(CFLAGS)

$(ODIR)/Applications/Example/Example.o: ./Applications/Example/Example.cpp ./Applications/Example/Example.h ./Applications/Example/../../src/Engine.h ./Applications/Example/../../src/Event/Events.h ./Applications/Example/../../src/Event/Keyboard/Keyboard.h
	$(CXX) -o $(ODIR)/Applications/Example/Example.o ./Applications/Example/Example.cpp $(CFLAGS) -c

$(ODIR)/src/Event/Keyboard/Keyboard.o: ./src/Event/Keyboard/Keyboard.cpp ./src/Event/Keyboard/Keyboard.h
	$(CXX) -o $(ODIR)/src/Event/Keyboard/Keyboard.o ./src/Event/Keyboard/Keyboard.cpp $(CFLAGS) -c

$(ODIR)/Main.o: ./Main.cpp ./Applications/Example/Example.h ./Applications/Example/../../src/Engine.h ./Applications/Example/../../src/Event/Events.h ./Applications/Example/../../src/Event/Keyboard/Keyboard.h
	$(CXX) -o $(ODIR)/Main.o ./Main.cpp $(CFLAGS) -c

clean:
	rm $(OUT) `find bin -name '*.o'`

