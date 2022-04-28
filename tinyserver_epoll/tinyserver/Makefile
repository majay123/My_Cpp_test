SERVER_OBJECT = daemon.o main.o predefine.o task.o

SERVER_HEADERS = daemon.h predefine.h task.h processpool.h

FLAG = -g

tinyserver: $(SERVER_OBJECT)
	g++ $(SERVER_OBJECT) -o tinyserver $(FLAG)

daemon.o: daemon.cpp daemon.h
	g++ -c $(FLAG) daemon.cpp

predefine.o: predefine.cpp predefine.h
	g++ -c $(FLAG) predefine.cpp

task.o: task.cpp task.h
	g++ -c $(FLAG) task.cpp

main.o: main.cpp $(SERVER_HEADERS)
	g++ -c $(FLAG) main.cpp

clean:
	rm *.o
	rm tinyserver