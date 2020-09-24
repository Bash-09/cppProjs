CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall -lSDL2
ODIR = o
OUT = a

$(OUT): $(ODIR)/Engine/Loop.o $(ODIR)/Engine/Platform/Keyboard.o $(ODIR)/Engine/Platform/Mouse.o $(ODIR)/Engine/Platform/Platform.o $(ODIR)/main.o 
	$(CXX) -o $(OUT) $(ODIR)/Engine/Loop.o $(ODIR)/Engine/Platform/Keyboard.o $(ODIR)/Engine/Platform/Mouse.o $(ODIR)/Engine/Platform/Platform.o $(ODIR)/main.o $(CFLAGS)

$(ODIR)/Engine/Loop.o: ./Engine/Loop.cpp ./Engine/Loop.h ./Engine/Platform/Platform.h ./Engine/Platform/Keyboard.h ./Engine/Platform/Mouse.h ./Engine/Main.h
	$(CXX) -o $(ODIR)/Engine/Loop.o ./Engine/Loop.cpp $(CFLAGS) -c

$(ODIR)/Engine/Platform/Keyboard.o: ./Engine/Platform/Keyboard.cpp ./Engine/Platform/Keyboard.h
	$(CXX) -o $(ODIR)/Engine/Platform/Keyboard.o ./Engine/Platform/Keyboard.cpp $(CFLAGS) -c

$(ODIR)/Engine/Platform/Mouse.o: ./Engine/Platform/Mouse.cpp ./Engine/Platform/Mouse.h
	$(CXX) -o $(ODIR)/Engine/Platform/Mouse.o ./Engine/Platform/Mouse.cpp $(CFLAGS) -c

$(ODIR)/Engine/Platform/Platform.o: ./Engine/Platform/Platform.cpp ./Engine/Platform/Platform.h ./Engine/Platform/Keyboard.h ./Engine/Platform/Mouse.h
	$(CXX) -o $(ODIR)/Engine/Platform/Platform.o ./Engine/Platform/Platform.cpp $(CFLAGS) -c

$(ODIR)/main.o: ./main.cpp ./Engine/Engine.h ./Engine/Platform/Platform.h ./Engine/Platform/Keyboard.h ./Engine/Platform/Mouse.h ./Engine/Loop.h ./Engine/Platform/Platform.h ./Engine/Platform/Keyboard.h ./Engine/Platform/Mouse.h ./Engine/Main.h ./Engine/Main.h
	$(CXX) -o $(ODIR)/main.o ./main.cpp $(CFLAGS) -c

clean:
	rm $(OUT) `find o -name '*.o'`

