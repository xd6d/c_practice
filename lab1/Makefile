all: main

main: main.o db.o client.o
	g++ main.o Database.o Client.o -o main

main.o: main.cpp
	g++ -c main.cpp

db.o: Database.cpp
	g++ -c Database.cpp

client.o: Client.cpp
	g++ -c Client.cpp

clean:
	rm -rf *.o main