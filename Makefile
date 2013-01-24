test: hello
	./hello
hello:
	yasm -f macho64 hello.asm	
	ld -o hello hello.o
clean:
	rm *.o *.core hello
