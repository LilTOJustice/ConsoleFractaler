a.out: main.cc Complex.o Imaginary.o
	g++ main.cc Complex.o Imaginary.o

Complex.o: Complex.cc Complex.h
	g++ -c Complex.cc

Imaginary.o: Imaginary.cc Imaginary.h
	g++ -c Imaginary.cc

clean:
	rm -f *.o *.out
