	.file	"test.c"
	.globl	_MOD
	.section .rdata,"dr"
	.align 4
_MOD:
	.long	100000
	.align 4
LC0:
	.ascii "Erro : malloc failed in malloc\0"
	.text
	.globl	_concat
	.def	_concat;	.scl	2;	.type	32;	.endef
_concat:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	addl	%ebx, %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L2
	movl	$LC0, (%esp)
	call	_puts
	movl	$1, (%esp)
	call	_exit
L2:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcpy
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_strcat
	movl	-12(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.globl	_add
	.def	_add;	.scl	2;	.type	32;	.endef
_add:
LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$8, (%esp)
	call	_malloc
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L5
	movl	$LC0, (%esp)
	call	_puts
	movl	$1, (%esp)
	call	_exit
L5:
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%ebp)
	movl	$0, -12(%ebp)
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.globl	_array_create
	.def	_array_create;	.scl	2;	.type	32;	.endef
_array_create:
LFB21:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE21:
	.globl	_array_free
	.def	_array_free;	.scl	2;	.type	32;	.endef
_array_free:
LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_free
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE22:
	.globl	_array_size
	.def	_array_size;	.scl	2;	.type	32;	.endef
_array_size:
LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE23:
	.globl	_array_set
	.def	_array_set;	.scl	2;	.type	32;	.endef
_array_set:
LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	12(%ebp), %edx
	sall	$2, %edx
	addl	%eax, %edx
	movl	16(%ebp), %eax
	movl	%eax, (%edx)
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE24:
	.globl	_array_inflate
	.def	_array_inflate;	.scl	2;	.type	32;	.endef
_array_inflate:
LFB25:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	$4, 4(%esp)
	movl	%eax, (%esp)
	call	_calloc
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	jne	L14
	movl	$LC0, (%esp)
	call	_puts
	movl	$1, (%esp)
	call	_exit
L14:
	movl	$0, -12(%ebp)
	jmp	L15
L16:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-16(%ebp), %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	sall	$2, %ecx
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	addl	$1, -12(%ebp)
L15:
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	cmpl	%eax, %edx
	jne	L16
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	_free
	movl	8(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	$0, -16(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE25:
	.globl	_D_value
	.def	_D_value;	.scl	2;	.type	32;	.endef
_D_value:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	12(%ebp), %eax
	addl	$1073741823, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	$1, -8(%ebp)
	jmp	L18
L20:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	addl	$1073741823, %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	cmpl	-4(%ebp), %eax
	jge	L19
	movl	-12(%ebp), %eax
	movl	%eax, -4(%ebp)
L19:
	addl	$1, -8(%ebp)
L18:
	cmpl	$70, -8(%ebp)
	jne	L20
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.globl	_isLeap
	.def	_isLeap;	.scl	2;	.type	32;	.endef
_isLeap:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$7, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$400, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	testl	%eax, %eax
	jne	L23
	movl	$1, %eax
	jmp	L24
L23:
	movl	12(%ebp), %eax
	andl	$3, %eax
	testl	%eax, %eax
	jne	L25
	movl	12(%ebp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$100, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	testl	%eax, %eax
	je	L25
	movl	$1, %eax
	jmp	L24
L25:
	movl	$0, %eax
L24:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE27:
	.globl	_numberOfDays
	.def	_numberOfDays;	.scl	2;	.type	32;	.endef
_numberOfDays:
LFB28:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$12, %esp
	movl	$2, 8(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	call	_isLeap
	testb	%al, %al
	je	L27
	movl	$29, %eax
	jmp	L28
L27:
	movl	$28, %eax
L28:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE28:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "22:18:52\0"
LC2:
	.ascii "May 13 2018\0"
LC3:
	.ascii "Compiled on %s at %s\12\0"
	.align 4
LC4:
	.ascii "Enter today's date (mm dd yyyy): \0"
LC5:
	.ascii "%i %i %i\0"
	.align 4
LC6:
	.ascii "Tomorrrow's date is %i-%i-%i. \12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB29:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	andl	$-16, %esp
	subl	$48, %esp
	.cfi_offset 3, -12
	call	___main
	movl	$LC1, 8(%esp)
	movl	$LC2, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$LC4, (%esp)
	call	_printf
	leal	36(%esp), %eax
	addl	$4, %eax
	movl	%eax, 12(%esp)
	leal	36(%esp), %eax
	addl	$8, %eax
	movl	%eax, 8(%esp)
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_scanf
	movl	44(%esp), %ebx
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	movl	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	44(%esp), %eax
	movl	%eax, 8(%esp)
	call	_numberOfDays
	cmpl	%eax, %ebx
	je	L30
	movl	44(%esp), %eax
	addl	$1, %eax
	movl	%eax, 32(%esp)
	movl	36(%esp), %eax
	movl	%eax, 24(%esp)
	movl	40(%esp), %eax
	movl	%eax, 28(%esp)
	jmp	L31
L30:
	movl	36(%esp), %eax
	cmpl	$12, %eax
	jne	L32
	movl	$1, 32(%esp)
	movl	$1, 24(%esp)
	movl	40(%esp), %eax
	addl	$1, %eax
	movl	%eax, 28(%esp)
	jmp	L31
L32:
	movl	$1, 32(%esp)
	movl	36(%esp), %eax
	addl	$1, %eax
	movl	%eax, 24(%esp)
	movl	40(%esp), %eax
	movl	%eax, 24(%esp)
L31:
	movl	28(%esp), %ecx
	movl	32(%esp), %edx
	movl	24(%esp), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$0, %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE29:
	.globl	_quick
	.def	_quick;	.scl	2;	.type	32;	.endef
_quick:
LFB30:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jge	L46
	jmp	L37
L39:
	subl	$1, 16(%ebp)
L37:
	movl	12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jge	L38
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	cmpl	-12(%ebp), %eax
	jge	L39
L38:
	movl	12(%ebp), %eax
	cmpl	16(%ebp), %eax
	je	L47
	movl	12(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, 12(%ebp)
	movl	8(%ebp), %edx
	movl	16(%ebp), %ecx
	movl	(%edx,%ecx,4), %ecx
	movl	8(%ebp), %edx
	movl	%ecx, (%edx,%eax,4)
	jmp	L42
L44:
	addl	$1, 12(%ebp)
L42:
	movl	12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jge	L43
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	cmpl	-12(%ebp), %eax
	jle	L44
L43:
	movl	12(%ebp), %eax
	cmpl	16(%ebp), %eax
	je	L48
	movl	16(%ebp), %eax
	leal	-1(%eax), %edx
	movl	%edx, 16(%ebp)
	movl	8(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	(%edx,%ecx,4), %ecx
	movl	8(%ebp), %edx
	movl	%ecx, (%edx,%eax,4)
	jmp	L37
L47:
	nop
	jmp	L41
L48:
	nop
L41:
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	-12(%ebp), %ecx
	movl	%ecx, (%eax,%edx,4)
	movl	16(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_quick
	movl	-24(%ebp), %eax
	leal	1(%eax), %edx
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_quick
	jmp	L34
L46:
	nop
L34:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE30:
	.globl	_PerfectNum
	.def	_PerfectNum;	.scl	2;	.type	32;	.endef
_PerfectNum:
LFB31:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$1, -4(%ebp)
	movl	$2, -8(%ebp)
	jmp	L50
L52:
	movl	8(%ebp), %eax
	cltd
	idivl	-8(%ebp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	L51
	movl	8(%ebp), %eax
	cltd
	idivl	-8(%ebp)
	movl	%eax, %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	addl	%eax, -4(%ebp)
L51:
	addl	$1, -8(%ebp)
L50:
	movl	-8(%ebp), %eax
	imull	-8(%ebp), %eax
	cmpl	8(%ebp), %eax
	jle	L52
	movl	-4(%ebp), %eax
	cmpl	8(%ebp), %eax
	sete	%al
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE31:
	.section .rdata,"dr"
LC7:
	.ascii " %c\0"
	.text
	.globl	_ReverseWrod
	.def	_ReverseWrod;	.scl	2;	.type	32;	.endef
_ReverseWrod:
LFB32:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%ebx
	subl	$112, %esp
	.cfi_offset 7, -12
	.cfi_offset 3, -16
	movl	$0, -12(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -20(%ebp)
	leal	-99(%ebp), %eax
	movl	$71, %ecx
	movl	$0, %ebx
	movl	%ebx, (%eax)
	movl	%ebx, -4(%eax,%ecx)
	leal	4(%eax), %edx
	andl	$-4, %edx
	subl	%edx, %eax
	addl	%eax, %ecx
	andl	$-4, %ecx
	shrl	$2, %ecx
	movl	%edx, %edi
	movl	%ebx, %eax
	rep stosl
	jmp	L55
L58:
	cmpl	$70, -12(%ebp)
	jg	L68
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -12(%ebp)
	movzbl	-21(%ebp), %edx
	movb	%dl, -99(%ebp,%eax)
L55:
	call	_getchar
	movb	%al, -21(%ebp)
	cmpb	$10, -21(%ebp)
	jne	L58
	jmp	L57
L68:
	nop
L57:
	leal	-99(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	movl	-12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -28(%ebp)
	jmp	L59
L65:
	leal	-99(%ebp), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$46, %al
	je	L60
	leal	-99(%ebp), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$63, %al
	je	L60
	leal	-99(%ebp), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$44, %al
	jne	L61
L60:
	leal	-99(%ebp), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -21(%ebp)
	jmp	L62
L61:
	leal	-99(%ebp), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	je	L62
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movzbl	-99(%ebp,%eax), %eax
	cmpb	$32, %al
	jne	L62
	leal	-99(%ebp), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -16(%ebp)
L63:
	movl	-16(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
	call	_putchar
	movl	-16(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, -16(%ebp)
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L63
L62:
	leal	-99(%ebp), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$32, %al
	jne	L64
	leal	-99(%ebp), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
L64:
	subl	$1, -28(%ebp)
L59:
	cmpl	$0, -28(%ebp)
	jg	L65
	movl	$0, -12(%ebp)
	jmp	L66
L67:
	leal	-99(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
	call	_putchar
	addl	$1, -12(%ebp)
L66:
	leal	-99(%ebp), %edx
	movl	-12(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %edx
	movl	-20(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	%al, %dl
	jne	L67
	movsbl	-21(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	nop
	addl	$112, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE32:
	.globl	_PrimeSum
	.def	_PrimeSum;	.scl	2;	.type	32;	.endef
_PrimeSum:
LFB33:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	movb	$1, -17(%ebp)
	fldz
	fstpl	-32(%ebp)
	movl	$3, -12(%ebp)
	jmp	L70
L76:
	movl	$2, -16(%ebp)
	jmp	L71
L74:
	movl	-12(%ebp), %eax
	cltd
	idivl	-16(%ebp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	L72
	movb	$0, -17(%ebp)
	jmp	L73
L72:
	movb	$1, -17(%ebp)
	addl	$1, -16(%ebp)
L71:
	fildl	-16(%ebp)
	fstpl	-48(%ebp)
	fildl	-12(%ebp)
	fstpl	(%esp)
	call	_sqrt
	fldl	-48(%ebp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jnb	L74
L73:
	cmpb	$0, -17(%ebp)
	je	L75
	fildl	-12(%ebp)
	fstpl	(%esp)
	call	_sqrt
	fldl	-32(%ebp)
	faddp	%st, %st(1)
	fstpl	-32(%ebp)
L75:
	addl	$1, -12(%ebp)
L70:
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jle	L76
	fldl	-32(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE33:
	.globl	_find_char
	.def	_find_char;	.scl	2;	.type	32;	.endef
_find_char:
LFB34:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	jmp	L79
L83:
	movl	12(%ebp), %eax
	movzbl	(%eax), %edx
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	%al, %dl
	jne	L81
	movl	8(%ebp), %eax
	jmp	L82
L81:
	addl	$1, 8(%ebp)
L80:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L83
	addl	$1, 12(%ebp)
L79:
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L80
	movl	$0, %eax
L82:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE34:
	.globl	_match
	.def	_match;	.scl	2;	.type	32;	.endef
_match:
LFB35:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	jmp	L86
L88:
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, 8(%ebp)
	movzbl	(%eax), %ecx
	movl	12(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, 12(%ebp)
	movzbl	(%eax), %eax
	cmpb	%al, %cl
	je	L86
	movl	$0, %eax
	jmp	L87
L86:
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L88
	movl	8(%ebp), %eax
L87:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE35:
	.globl	_del_substr
	.def	_del_substr;	.scl	2;	.type	32;	.endef
_del_substr:
LFB36:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	jmp	L90
L93:
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_match
	movl	%eax, -4(%ebp)
	cmpl	$0, -4(%ebp)
	jne	L97
	addl	$1, 8(%ebp)
L90:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L93
	jmp	L92
L97:
	nop
L92:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L98
	movl	$0, %eax
	jmp	L95
L98:
	nop
L96:
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, 8(%ebp)
	movl	-4(%ebp), %edx
	leal	1(%edx), %ecx
	movl	%ecx, -4(%ebp)
	movzbl	(%edx), %edx
	movb	%dl, (%eax)
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L96
	movl	$1, %eax
L95:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE36:
	.globl	_find_two_largest
	.def	_find_two_largest;	.scl	2;	.type	32;	.endef
_find_two_largest:
LFB37:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jle	L100
	movl	-8(%ebp), %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
	movl	-8(%ebp), %eax
	movl	4(%eax), %edx
	movl	20(%ebp), %eax
	movl	%edx, (%eax)
	jmp	L101
L100:
	movl	-8(%ebp), %eax
	movl	4(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
	movl	-8(%ebp), %eax
	movl	(%eax), %edx
	movl	20(%ebp), %eax
	movl	%edx, (%eax)
L101:
	movl	$2, -4(%ebp)
	jmp	L102
L105:
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jle	L103
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	20(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
	jmp	L104
L103:
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	20(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jle	L104
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	20(%ebp), %eax
	movl	%edx, (%eax)
L104:
	addl	$1, -4(%ebp)
L102:
	movl	-4(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L105
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE37:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
	.def	_strcpy;	.scl	2;	.type	32;	.endef
	.def	_strcat;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_calloc;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_getchar;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	_sqrt;	.scl	2;	.type	32;	.endef
