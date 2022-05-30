CCFLAGS:=-g -std=c++11
CXX:=g++ $(CCFLAGS)

all:
	$(CC) -o main

clean:
    rm -f main main.exe
