all:
	g++ -std=c++20 -I./googletest/googletest/include -L./googletest/build/lib -lgtest -lgtest_main main.cpp -o program.out
clean:
	rm program.out
