%define	stdin	      0
%define	stdout	    1
%define	stderr	    2

%define CLASS       0x2000000     ;this is a class needed from syscall_sw.h
%define SYS_nosys   (CLASS + 0)
%define	SYS_exit    (CLASS + 1)
%define	SYS_fork    (CLASS + 2)
%define	SYS_read    (CLASS + 3)
%define	SYS_write   (CLASS + 4)

section	.text
align 4
access.the.osx.kernel:
    syscall
    ret

%macro	system	1
    mov	rax, %1
    call    access.the.osx.kernel
%endmacro

%macro	sys.exit    0
    system  SYS_exit
%endmacro

%macro	sys.write   0
    system  SYS_write
%endmacro
