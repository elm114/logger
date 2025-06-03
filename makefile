all:
    g++ -std=c++17 Logger.cpp -o Logger

clean:
	$(RM) Logger