CXX = g++
CXXFLAGS = -std=c++14 -O2

run: FORCE
	$(CXX) -o $@ $(CXXFLAGS) performance.cpp ../src/random/Random.cpp

FORCE: ;

clean:
	rm test
