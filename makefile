GCC=gcc -g -Wall -Wextra -std=gnu11
LIBS=-lm -lpthread

TatooShop: main.o main_functions.o thread_wrapper.o
	$(GCC) $^ -o $@ $(LIBS)
main.o: main.c
	$(GCC) $< -c
main_functions.o: main_functions.c main_functions.h
	$(GCC) $< -c
thread_wrapper.o: thread_wrapper.c thread_wrapper.h
	$(GCC) $< -c
run: TatooShop
	./TatooShop
clean:
	rm -f *.o TatooShop; clear

rebuild:
	clean TatooShop