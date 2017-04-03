CC = gcc
CFLAGS = "-Wall" "-Wextra" "-std=c99" "-g"
MISCFLAG = "-c"



sqsort: sqsort.o scanner.o integer.o real.o string.o sll.o dll.o stack.o queue.o parser.o comparator.o
		$(CC) $(CFLAGS) sqsort.o scanner.o integer.o real.o string.o sll.o dll.o stack.o queue.o parser.o comparator.o -o sqsort

test: sqsort
		./sqsort -d ints.txt
		./sqsort -s strings.txt
		./sqsort -r reals.txt
clean:
		rm -f *.o sqsort
