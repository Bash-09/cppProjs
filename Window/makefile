CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall -lSDL2 -lSDL2_image
ODIR = o
OUT = a

$(OUT): $(ODIR)/main.o $(ODIR)/Platform/SDL/Window.o $(ODIR)/Renderer/OpenGL/Renderer.o 
	$(CXX) -o $(OUT) $(ODIR)/main.o $(ODIR)/Platform/SDL/Window.o $(ODIR)/Renderer/OpenGL/Renderer.o $(CFLAGS)

$(ODIR)/main.o: ./main.cpp ./Platform/Window.h
	$(CXX) -o $(ODIR)/main.o ./main.cpp $(CFLAGS) -c

$(ODIR)/Platform/SDL/Window.o: ./Platform/SDL/Window.cpp ./Platform/SDL/../Window.h
	$(CXX) -o $(ODIR)/Platform/SDL/Window.o ./Platform/SDL/Window.cpp $(CFLAGS) -c

$(ODIR)/Renderer/OpenGL/Renderer.o: ./Renderer/OpenGL/Renderer.cpp ./Renderer/OpenGL/../Renderer.h
	$(CXX) -o $(ODIR)/Renderer/OpenGL/Renderer.o ./Renderer/OpenGL/Renderer.cpp $(CFLAGS) -c

clean:
	rm $(OUT) `find o -name '*.o'`

