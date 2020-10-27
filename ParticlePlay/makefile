CXX = g++-10
CFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -g -Wall -lSDL2 -lSDL2_image
ODIR = o
OUT = a

$(OUT): $(ODIR)/main.o $(ODIR)/Particle.o $(ODIR)/Particles/Grav.o $(ODIR)/Particles/Basic.o 
	$(CXX) -o $(OUT) $(ODIR)/main.o $(ODIR)/Particle.o $(ODIR)/Particles/Grav.o $(ODIR)/Particles/Basic.o $(CFLAGS)

$(ODIR)/main.o: ./main.cpp ./pge.h ./Particles/Basic.h ./Particles/../Particle.h ./Particles/../pge.h ./Particles/../maths.h
	$(CXX) -o $(ODIR)/main.o ./main.cpp $(CFLAGS) -c

$(ODIR)/Particle.o: ./Particle.cpp ./Particle.h ./pge.h ./maths.h
	$(CXX) -o $(ODIR)/Particle.o ./Particle.cpp $(CFLAGS) -c

$(ODIR)/Particles/Grav.o: ./Particles/Grav.cpp
	$(CXX) -o $(ODIR)/Particles/Grav.o ./Particles/Grav.cpp $(CFLAGS) -c

$(ODIR)/Particles/Basic.o: ./Particles/Basic.cpp ./Particles/Basic.h ./Particles/../Particle.h ./Particles/../pge.h ./Particles/../maths.h
	$(CXX) -o $(ODIR)/Particles/Basic.o ./Particles/Basic.cpp $(CFLAGS) -c

clean:
	rm $(OUT) `find o -name '*.o'`

