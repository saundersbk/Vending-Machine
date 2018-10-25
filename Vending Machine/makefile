CC=g++

main.exe : main.o VendingMachine.o
	${CC} -o main.exe main.o VendingMachine.o
	
main.o : main.cpp VendingMachine.cpp VendingMachine.h
	${CC} -c -o main.o main.cpp
	
VendingMachine.o : VendingMachine.cpp VendingMachine.h
	${CC} -c -o VendingMachine.o VendingMachine.cpp
	
clean :
	rm *.o
	rm *.exe