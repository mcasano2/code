# x86_desc.S - Set up x86 segment descriptors, descriptor tables 
# vim:ts=4 noexpandtab

#define ASM     1
#include "x86_desc.h"

.text

.globl  ldt_size, tss_size
.globl  gdt_desc, ldt_desc, tss_desc
.globl  tss, tss_desc_ptr, ldt, ldt_desc_ptr
.globl  gdt_ptr
.globl  idt_desc_ptr, idt
.globl pd0, pd1, pd2, pd3, pd4, pd5, pd6, pd7, pd8, pd9, pt0
.globl _exception_handler0
.globl _exception_handler1
.globl _exception_handler2
.globl _exception_handler3
.globl _exception_handler4
.globl _exception_handler5
.globl _exception_handler6
.globl _exception_handler7
.globl _exception_handler8
.globl _exception_handler9
.globl _exception_handler10
.globl _exception_handler11
.globl _exception_handler12
.globl _exception_handler13
.globl _exception_handler14
.globl _exception_handler15
.globl _exception_handler16
.globl _exception_handler17
.globl _exception_handler18
.globl _exception_handler19
.globl _exception_handler20
.globl _exception_handler21
.globl _exception_handler22
.globl _exception_handler23
.globl _exception_handler24
.globl _exception_handler25
.globl _exception_handler26
.globl _exception_handler27
.globl _exception_handler28
.globl _exception_handler29
.globl _exception_handler30
.globl _exception_handler31

.globl _rtc_handler
.globl _keyboard_handler
.globl _syscall_handler

.align 4


tss_size:
	.long tss_bottom - tss - 1

ldt_size:
	.long ldt_bottom - ldt - 1

	.word 0 # Padding
ldt_desc:
	.word KERNEL_LDT
	.long ldt

	.align 4
tss:
_tss:
	.rept 104
	.byte 0
	.endr
tss_bottom:

	.align  16
	
gdt_desc:
	.word gdt_bottom - gdt -1
	.long gdt
	.align 4
	
gdt:
_gdt:

	# First GDT entry cannot be used
	.quad 0
	
	# NULL entry
	.quad 0
	
	# Segmentation will not be used
	# CS and DS both are 0-4GB r/w segments
	#
	# The layout is (from Intel IA-32 reference manual):
	#  31        24 23  22  21  20  19   16 15  14 13 12  11   8 7          0
	# |----------------------------------------------------------------------|
	# |            |   | D |   | A |  Seg  |   |  D  |   |      |            |
	# | Base 31:24 | G | / | 0 | V | Limit | P |  P  | S | Type | Base 23:16 |
	# |            |   | B |   | L | 19:16 |   |  L  |   |      |            |
	# |----------------------------------------------------------------------|
	#
	# |----------------------------------------------------------------------|
	# |                                    |                                 |
	# | Base 15:0                          | Segment Limit 15:0              |
	# |                                    |                                 |
	# |----------------------------------------------------------------------|
	
gdt_ptr:
	# Set up an entry for kernel CS
	.quad 0x00CF9A000000FFFF

	# Set up an entry for kernel DS
	.quad 0x00CF92000000FFFF

	# Set up an entry for user CS
	.quad 0x00CFFA000000FFFF

	# Set up an entry for user DS
	.quad 0x00CFF2000000FFFF

	# Set up an entry for TSS
tss_desc_ptr:
	.quad 0

	# Set up one LDT
ldt_desc_ptr:
	.quad 0

gdt_bottom:

	.align 16
ldt:
	.rept 4
	.quad 0
	.endr
ldt_bottom:

.align 4
	.word 0 # Padding
idt_desc_ptr:
	.word idt_bottom - idt - 1
	.long idt
	

	.align  16
idt:
_idt:
	.rept NUM_VEC
	.quad 0
	.endr

idt_bottom:

	.align 4096
pd0:
	.long pt0+3
	.long 0x00400193
	.rept NUM_PAGES -2
	.long 0
	.endr
	
	.align 4096
pd1: 
	.long pt0+3
	.long 0x00400193
	.rept NUM_PAGES -2
	.long 0
	.endr
	
	.align 4096
pd2:
	.long pt0+3
	.long 0x00400193
	.rept NUM_PAGES -2
	.long 0
	.endr
	
	.align 4096
pd3:
	.long pt0+3
	.long 0x00400193
	.rept NUM_PAGES -2
	.long 0
	.endr
	
	.align 4096
pd4:
	.long pt0+3
	.long 0x00400193
	.rept NUM_PAGES -2
	.long 0
	.endr
	
	.align 4096
pd5:
	.long pt0+3
	.long 0x00400193
	.rept NUM_PAGES -2
	.long 0
	.endr
	
	.align 4096
pd6:
	.long pt0+3
	.long 0x00400193
	.rept NUM_PAGES -2
	.long 0
	.endr
	
	.align 4096
pd7:
	.long pt0+3
	.long 0x00400193
	.rept NUM_PAGES -2
	.long 0
	.endr
	
	.align 4096
pd8:
	.long pt0+3
	.long 0x00400193
	.rept NUM_PAGES -2
	.long 0
	.endr

	.align 4096
pd9:
	.long pt0+3
	.long 0x00400193
	.rept NUM_PAGES -2
	.long 0
	.endr
	
	.align 4096
#pt0:
#	.rept NUM_PAGES
#	.long 0
#	.endr
	
# ISR handlers modeled off http://www.osdever.net/bkerndev/Docs/isrs.htm 

_exception_handler0:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $0
    jmp exception_handler_general
	
_exception_handler1:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $1
    jmp exception_handler_general
	
	
_exception_handler2:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $2
    jmp exception_handler_general
	
	
_exception_handler3:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $3
    jmp exception_handler_general
	
	
_exception_handler4:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $4
    jmp exception_handler_general
	
	
_exception_handler5:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $5
    jmp exception_handler_general
	
	
_exception_handler6:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $6
    jmp exception_handler_general
	
	
_exception_handler7:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $7
    jmp exception_handler_general
	
	
_exception_handler8:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $8
    jmp exception_handler_general
	
	
_exception_handler9:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $9
    jmp exception_handler_general
	
	
_exception_handler10:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $10
    jmp exception_handler_general
	
	
_exception_handler11:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $11
    jmp exception_handler_general
	
	
_exception_handler12:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $12
    jmp exception_handler_general
	
	
_exception_handler13:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $13
    jmp exception_handler_general
	
	
_exception_handler14:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $14
    jmp exception_handler_general
	
	
_exception_handler15:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $15
    jmp exception_handler_general
	
	
_exception_handler16:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $16
    jmp exception_handler_general
	
_exception_handler17:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $17
    jmp exception_handler_general
	
_exception_handler18:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $18
    jmp exception_handler_general
	
_exception_handler19:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $19
    jmp exception_handler_general
	
_exception_handler20:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $20
    jmp exception_handler_general
	
_exception_handler21:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $21
    jmp exception_handler_general
	
_exception_handler22:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $22
    jmp exception_handler_general
	
_exception_handler23:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $23
    jmp exception_handler_general
	
_exception_handler24:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $24
    jmp exception_handler_general
	
_exception_handler25:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $25
    jmp exception_handler_general
	
_exception_handler26:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $26
    jmp exception_handler_general
	
_exception_handler27:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $27
    jmp exception_handler_general
	
_exception_handler28:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $28
    jmp exception_handler_general
	
_exception_handler29:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $29
    jmp exception_handler_general
	
_exception_handler30:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $30
    jmp exception_handler_general
	
_exception_handler31:
    CLI
	pusha
	pushl %ds
	pushl %es
	pushl %fs
	pushl %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
    pushl $31
    jmp exception_handler_general

	
exception_handler_general:

	movl $exception_print,%eax
	call *%eax
	addl $4,%esp
	popl %gs
	popl %fs
	popl %es
	popl %ds
	popa
	iret

_keyboard_handler:
	pusha
	pushf
	pushw %ds
	pushw %es
	pushw %fs
	pushw %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
	# get char from keyboard
	inb $0x60,%al
	push %eax
	call keyboard_interrupt
	pop %eax
	popw %gs
	popw %fs
	popw %es
	popw %ds
	popf
	popa
	iret
	
_rtc_handler:
	pusha
	pushf
	pushw %ds
	pushw %es
	pushw %fs
	pushw %gs
	# move KERNEL_DS into eax
	movl $0x18,%eax 
	movl %eax,%ds 
	movl %eax,%es 
	movl %eax,%fs 
	movl %eax,%gs 
	call rtc_interrupt
	popw %gs
	popw %fs
	popw %es
	popw %ds
	popf
	popa
	iret
	
_syscall_handler:
	pushal
	pushfl
	pushw %ds
	pushw %es
	pushw %fs
	pushw %gs
	# move KERNEL_DS into eax
	pushl %eax
	movl $0x18,%eax 
	movw %ax,%ds 
	movw %ax,%es 
	movw %ax,%fs 
	movw %ax,%gs 
	popl %eax
	call syscall_handler_finish
	popw %gs
	popw %fs
	popw %es
	popw %ds
	popfl
	movl %eax, 28(%esp)
	popal
	iret
