all:
	g++ -std=c++20 main.cpp -lgtest -lgtest_main -o program.out
clean:
	rm program.out
