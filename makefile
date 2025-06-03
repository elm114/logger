all:
	g++ -std=c++17 Logger.cpp -o Logger
	g++ -std=c++17 LoggerTest.cpp -lcppunit -o LoggerTest

test:
	chmod +x Logger
	./LoggerTest

clean:
	rm Logger LoggerTest