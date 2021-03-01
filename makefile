name = main
deps = matrix.o screen.o

all: run

run: $(name).out
	./$(name).out
	-display $(name).ppm
	echo $(name).ppm

$(name).out: $(name).o $(deps)
	g++ -o $(name).out $(name).o $(deps)

$(name).o: $(name).cpp
	g++ -c $(name).cpp

screen.o: screen.cpp screen.hpp matrix.o
	g++ -c screen.cpp matrix.cpp

matrix.o: matrix.cpp matrix.hpp
	g++ -c matrix.cpp

clean:
	rm $(name).out
	rm $(name).ppm
	rm *.o
	
