
all : shmClear shmLib.o shmRead shmWrite
shmLib.o: shmLib.c 
			gcc -c shmLib.c -o shmLib.o

shmClear: shmClear.c shmLib.o
			gcc shmClear.c shmLib.o -o shmClear

shmRead: shmRead.c shmLib.o
			gcc shmRead.c shmLib.o -o shmRead

shmWrite: shmWrite.c shmLib.o
			gcc shmWrite.c shmLib.o -o shmWrite