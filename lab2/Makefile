all: main

main_static: main.o libdb.a libclient.a
	g++ main.o -o main -L. -ldb -lclient

main.o: main.cpp
	g++ -c main.cpp

libdb.a: Database.o
	ar cr libdb.a Database.o

libclient.a: Client.o
	ar cr libclient.a Client.o

Database.o: Database.cpp
	g++ -c -fPIC Database.cpp

Client.o: Client.cpp
	g++ -c -fPIC Client.cpp

main_dyn: main.o libdb.so libclient.so
	g++ main.o  -o main -L. -ldb -lclient -Wl,-rpath,.

libdb.so: Database.o
	g++ -shared -o libdb.so Database.o

libclient.so: Client.o
	g++ -shared -o libclient.so Client.o

clean:
	rm -f *.o *.a *.so main