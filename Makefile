all: Drive

Drive: SortedListDr.o
	g++ -o Drive SortedListDr.o

SortedListDr.o: SortedListDr.cpp
	g++ -c SortedListDr.cpp  
	g++ -c SortedList.cpp

clean:
	rm -f SortedList.o
	rm -f SortedList.o~
	rm -f SortedList.cpp~
	rm -f Drive
	rm -f Makefile~
	rm -f SortedList.h~
	rm -f README.md~
	rm -f Student.o
	rm -f Student.o~
	rm -f Student.h~
	rm -f SortedListDr.o
	rm -f SortedListDr.cpp~
	rm -f SortedListDr.o~
	rm -f outfile.txt
	rm -f outFile.txt
	rm -f intcommands.txt~
	rm -f studcommands.txt~
	rm -f chcommands.txt~
	rm -f Student.cpp~
	rm -f outFile.txt~