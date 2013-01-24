%include 'system.inc'

section .data
hello	db	'Hello, World!', 0Ah
hbytes	equ	$-hello

section .text
global	start
start:
mov	rdi, stdout
mov	rsi, qword hello
mov	rdx, hbytes
sys.write

xor	rdi, rdi
sys.exit
