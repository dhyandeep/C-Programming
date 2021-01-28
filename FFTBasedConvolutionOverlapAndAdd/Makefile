CC=g++
CFLAGS=-lpthread -lrt -lfftw3

hellomake: DataGenerationBlock.o DataInterpretationBlock.o BlockBase.o Runner.o SmQueue.o FFTConv.o CSVManager.o
	$(CC) -o out Runner.o DataInterpretationBlock.o DataGenerationBlock.o SmQueue.o BlockBase.o FFTConv.o CSVManager.o  $(CFLAGS)  
clean:
	rm -f *.o
	rm -f out
	rm -f /dev/shm/OS
	rm -f /dev/shm/sem.full
	rm -f /dev/shm/sem.empty
	rm -f out.txt 

