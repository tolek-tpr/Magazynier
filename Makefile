CC = g++
OUTDIR = bin/main
MAIN = main.cpp

build:
	mkdir -p bin/
	$(CC) -o $(OUTDIR) $(MAIN)
	./bin/main.exe

run:
	./bin/main.exe

clean:
	rm -rf bin/