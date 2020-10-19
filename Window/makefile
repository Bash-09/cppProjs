CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall -lSDL2 -lSDL2_image
ODIR = o
OUT = a

$(OUT): $(ODIR)/Engine/Input/Keyboard.o $(ODIR)/Engine/GameLoop.o $(ODIR)/main.o $(ODIR)/Platform/SDL/Window.o $(ODIR)/Renderer/OpenGL/Renderer.o $(ODIR)/Apps/Test1/Test1.o $(ODIR)/Apps/DefaultApp/App.o 
	$(CXX) -o $(OUT) $(ODIR)/Engine/Input/Keyboard.o $(ODIR)/Engine/GameLoop.o $(ODIR)/main.o $(ODIR)/Platform/SDL/Window.o $(ODIR)/Renderer/OpenGL/Renderer.o $(ODIR)/Apps/Test1/Test1.o $(ODIR)/Apps/DefaultApp/App.o $(CFLAGS)

$(ODIR)/Engine/Input/Keyboard.o: ./Engine/Input/Keyboard.cpp ./Engine/Input/Keyboard.h
	$(CXX) -o $(ODIR)/Engine/Input/Keyboard.o ./Engine/Input/Keyboard.cpp $(CFLAGS) -c

$(ODIR)/Engine/GameLoop.o: ./Engine/GameLoop.cpp ./Engine/Engine.h ./Engine/../Platform/Window.h ./Engine/../Platform/../Engine/Input/Keyboard.h ./Engine/../Renderer/Renderer.h ./Engine/../Renderer/../Platform/Window.h ./Engine/../Renderer/../Platform/../Engine/Input/Keyboard.h ./Engine/Input/Keyboard.h
	$(CXX) -o $(ODIR)/Engine/GameLoop.o ./Engine/GameLoop.cpp $(CFLAGS) -c

$(ODIR)/main.o: ./main.cpp ./Apps/Test1/Test1.h ./Apps/Test1/../../Engine/Engine.h ./Apps/Test1/../../Engine/../Platform/Window.h ./Apps/Test1/../../Engine/../Platform/../Engine/Input/Keyboard.h ./Apps/Test1/../../Engine/../Renderer/Renderer.h ./Apps/Test1/../../Engine/../Renderer/../Platform/Window.h ./Apps/Test1/../../Engine/../Renderer/../Platform/../Engine/Input/Keyboard.h ./Apps/Test1/../../Engine/Input/Keyboard.h
	$(CXX) -o $(ODIR)/main.o ./main.cpp $(CFLAGS) -c

$(ODIR)/Platform/SDL/Window.o: ./Platform/SDL/Window.cpp ./Platform/SDL/../Window.h ./Platform/SDL/../../Engine/Input/Keyboard.h
	$(CXX) -o $(ODIR)/Platform/SDL/Window.o ./Platform/SDL/Window.cpp $(CFLAGS) -c

$(ODIR)/Renderer/OpenGL/Renderer.o: ./Renderer/OpenGL/Renderer.cpp ./Renderer/OpenGL/../Renderer.h ./Renderer/OpenGL/../../Platform/Window.h ./Renderer/OpenGL/../../Platform/../Engine/Input/Keyboard.h
	$(CXX) -o $(ODIR)/Renderer/OpenGL/Renderer.o ./Renderer/OpenGL/Renderer.cpp $(CFLAGS) -c

$(ODIR)/Apps/Test1/Test1.o: ./Apps/Test1/Test1.cpp ./Apps/Test1/Test1.h ./Apps/Test1/../../Engine/Engine.h ./Apps/Test1/../../Engine/../Platform/Window.h ./Apps/Test1/../../Engine/../Platform/../Engine/Input/Keyboard.h ./Apps/Test1/../../Engine/../Renderer/Renderer.h ./Apps/Test1/../../Engine/../Renderer/../Platform/Window.h ./Apps/Test1/../../Engine/../Renderer/../Platform/../Engine/Input/Keyboard.h ./Apps/Test1/../../Engine/Input/Keyboard.h
	$(CXX) -o $(ODIR)/Apps/Test1/Test1.o ./Apps/Test1/Test1.cpp $(CFLAGS) -c

$(ODIR)/Apps/DefaultApp/App.o: ./Apps/DefaultApp/App.cpp ./Apps/DefaultApp/App.h ./Apps/DefaultApp/../../Engine/Engine.h ./Apps/DefaultApp/../../Engine/../Platform/Window.h ./Apps/DefaultApp/../../Engine/../Platform/../Engine/Input/Keyboard.h ./Apps/DefaultApp/../../Engine/../Renderer/Renderer.h ./Apps/DefaultApp/../../Engine/../Renderer/../Platform/Window.h ./Apps/DefaultApp/../../Engine/../Renderer/../Platform/../Engine/Input/Keyboard.h ./Apps/DefaultApp/../../Engine/Input/Keyboard.h
	$(CXX) -o $(ODIR)/Apps/DefaultApp/App.o ./Apps/DefaultApp/App.cpp $(CFLAGS) -c

clean:
	rm $(OUT) `find o -name '*.o'`

