CC = g++
OUTDIR = bin/main
MAIN = main.cpp

UNAME := $(shell uname)
ifeq ($(UNAME),$(filter $(UNAME),Linux Darwin FreeBSD GNU/kFreeBSD))
ifeq ($(UNAME),$(filter $(UNAME),Darwin))
OS=darwin
else
ifeq ($(UNAME),$(filter $(UNAME),FreeBSD GNU/kFreeBSD))
OS=bsd
else
OS=linux
endif
endif
endif

help:
	@echo "MinGW-Windows-Bash - Compiles and runs for Windows on a bash based terminal"
	@echo "linux - Compiles and runs for Linux"
	@echo "Windows-Run-Bash - Runs a alredy compiled file on windows bash terminal"
	@echo "Linux-Run - Runs a alredy compiled file on Linux"
	@echo "clean - Removes the bin directory"

.PHONY: help

MinGW-Windows-Bash:
	mkdir -p bin/
	$(CC) -o $(OUTDIR) $(MAIN)
	./bin/main.exe

linux:
	mkdir -p bin/
	$(CC) -o $(OUTDIR) $(MAIN)

Windows-Run-Bash:
	./bin/main.exe

Linux-Run:
	./bin/main

clean:
	rm -rf bin/
