SRC := $(wildcard *.cpp)
CFLAGS = -I. -Wall -O0 -g

all: cutSphereMove  

cutSphereMove: $(SRC)
	g++ -o $@ $^ $(CFLAGS)


doc: $(SRC)
	doxygen
	cd latex; make
	
	

clean:
	rm cutSphereMove
