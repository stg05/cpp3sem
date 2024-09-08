CXX = g++
CXXFLAGS = -Wall -g


blah: blah.o
	$(CXX) $(CXXFLAGS) blah.o -o blah

blah.o: blah.cpp
	$(CXX) $(CXXFLAGS) -c blah.cpp -o blah.o

blah.cpp:
	echo int main() { return 0; } > blah.cpp

clean: blah.o
	del blah.o