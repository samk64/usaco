OPTIONS = -g 
COMPILE_OPTIONS = $(OPTIONS) -c
GTEST_OPTIONS = $(COMPILE_OPTIONS) -DGTEST
GTEST_LIB = -l gtest

friday: friday.o
		g++ friday.o -o friday $(OPTIONS)

friday.o: friday.cpp
		g++ friday.cpp $(COMPILE_OPTIONS) -o friday.o

test: test.o
		g++ test.o -o test $(OPTIONS) $(GTEST_LIB)

test.o: test.cpp friday.cpp
		g++ test.cpp $(GTEST_OPTIONS) -o test.o

clean:
		rm -rf *.o test friday
