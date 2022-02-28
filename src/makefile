CXX = g++
CFLAGS = -I.
DEPS = Stack.h
OBJ = main.o Stack.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm *.o