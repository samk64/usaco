OPTIONS = -g -static-libstdc++
COMPILE_OPTIONS = $(OPTIONS) -c
GTEST_LIB = /usr/lib/libgtest.a 

friday: friday.o
		g++ friday.o -o friday $(OPTIONS)

friday.o: friday.cpp
		g++ friday.cpp $(COMPILE_OPTIONS) -o friday.o

friday_test: friday_test.o
		g++ friday_test.o -o friday_test $(OPTIONS) $(GTEST_LIB)

friday_test.o: friday_test.cpp
		g++ friday_test.cpp $(COMPILE_OPTIONS) -o friday_test.o -isystem /usr/include/

gift: gift1.o
		g++ gift1.o -o gift $(OPTIONS)

gift1.o: gift1.cpp
		g++ gift1.cpp $(COMPILE_OPTIONS) -o gift1.o

ride: ride.o
		g++ ride.o -o ride $(OPTIONS)

ride.o: ride.cpp
		g++ ride.cpp $(COMPILE_OPTIONS) -o ride.o -c

clean:
		rm -rf *.o
