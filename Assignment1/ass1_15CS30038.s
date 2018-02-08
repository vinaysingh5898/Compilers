	.file	"test.c"   				#source file name
	.text
	.globl	func       				#func is global
	.type	func, @function
func:								#func starts here
.LFB0:
	.cfi_startproc					#Call frame information for exception handling and debugging
	pushq	%rbp					#pushing into the stack(base pointer)
	.cfi_def_cfa_offset 16			#call frame information for exception handling and debugging
	.cfi_offset 6, -16				#call frame information for exception handling and debugging
	movq	%rsp, %rbp				#saving base pointer
	.cfi_def_cfa_register 6			#call frame information for exception handling and debugging
	pushq	%rbx					#pushing into stack
	subq	$56, %rsp				#space created of 56 byte for array,cfa,parameters
	.cfi_offset 3, -24				#cfi for debugging
	movl	%edi, -52(%rbp)			#massign value of %edi to %[rbp-52] 
	movq	%fs:40, %rax			#rax<-- fs:40 Canaray prototype from fs:40 into register rax
	movq	%rax, -24(%rbp)			#assign value of %rax to %[rbp-24] 
	xorl	%eax, %eax				#eax=0
	movq	%rsp, %rax				#assigning value of %rsp into %rax
	movq	%rax, %rsi				#assigning value of %rsp into %rsi
	movl	-52(%rbp), %eax			#assign value of %[rbp-52] to %eax
	addl	$1, %eax				#eax <-- eax+1
	movslq	%eax, %rdx				#assigning the value of %rbp to eax
	subq	$1, %rdx				#space created of 1 byte for array,cfa,parameters
	movq	%rdx, -40(%rbp)			#assign value of %rdx to %[rbp-40] 
	movslq	%eax, %rdx				#assigning the value of %eax to %rdx
	movq	%rdx, %r8				#assigning the value of %eax to %r8
	movl	$0, %r9d				#assigning 0 to %r9d 
	movslq	%eax, %rdx				#assigning the value of %eax to %rdx
	movq	%rdx, %rcx				#assigning the value of %eax to %rcx
	movl	$0, %ebx				#assigning 0 to %ebx
	cltq							
	salq	$2, %rax				
	leaq	3(%rax), %rdx			#address of array is assigned to %rdx 
	movl	$16, %eax				#assigning 16 to %eax
	subq	$1, %rax                #decrease %rax by 1
	addq	%rdx, %rax				#increase %rax by %rdx
	movl	$16, %edi				#assigning 16 to %ebi	
	movl	$0, %edx				#assigning 0 to %ebx
	divq	%rdi	                #divide %rdi by %edi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp				#decrease %rsp by %rax
	movq	%rsp, %rax				#assigning the value of %rsp to %rax
	addq	$3, %rax                #increase %rax by 3
	shrq	$2, %rax				#logically right shift by 2
	salq	$2, %rax				#logically left shift 
	movq	%rax, -32(%rbp)			#assign value of %rax to %[rbp-32]
	movq	-32(%rbp), %rax			#assign value of %[rbp-32] to %rax
 	movl	$0, (%rax)				#assigning 0 to %rax
	movq	-32(%rbp), %rax			#assign value of %[rbp-32] to %rax
	movl	$1, 4(%rax)             #assign value 1 to %[rax+32]
	movl	$2, -44(%rbp)			#assign value 2 to %[rbp-44]
	jmp	.L2
.L3:
	movl	-44(%rbp), %eax         #assign value of %[rbp-44] to %eax
	leal	-1(%rax), %edx          #assign value of %[rax-1] to %edx
	movq	-32(%rbp), %rax         #assign value of %[rbp-32] to %rax
	movslq	%edx, %rdx              #assign %edx to %rdx
	movl	(%rax,%rdx,4), %ecx
	movl	-44(%rbp), %eax         #assign value of %[rbp-44] to %eax
	leal	-2(%rax), %edx
	movq	-32(%rbp), %rax         #assign value of %[rbp-32] to %rax
	movslq	%edx, %rdx              #assign %edx to %rdx	
	movl	(%rax,%rdx,4), %eax
	addl	%eax, %ecx              #increase %ecx by %eax
	movq	-32(%rbp), %rax         #assign value of %[rbp-32] to %rax
	movl	-44(%rbp), %edx         #assign value of %[rbp-44] to %edx
	movslq	%edx, %rdx              #assigning %edx to %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -44(%rbp)           #increment %[rbp-44] by 1
.L2:
	movl	-44(%rbp), %eax			#assign value of %[rbp-44] to %edx
	cmpl	-52(%rbp), %eax         #assign value of %[rbp-44] to %edx
	jle	.L3							#jump to L3 if less than or equal to condition
	movq	-32(%rbp), %rax			#assign value of %[rbp-32] to %rax
	movl	-52(%rbp), %edx			#assign value of %[rbp-52] to %edx
	movslq	%edx, %rdx          	#assign %edx value to %rdx
	movl	(%rax,%rdx,4), %eax     #
	movq	%rsi, %rsp          	#assign %edx value to %rdx
	movq	-24(%rbp), %rbx			#
	xorq	%fs:40, %rbx			# assign 0 to %rbx
	je	.L5							#jump to L5 if equal to condition
	call	__stack_chk_fail@PLT	#
.L5:	
	movq	-8(%rbp), %rbx			#assign value of %[rbp-8] to %rbx
	leave                       	#clear stack
	.cfi_def_cfa 7, 8				#fi for debugging
	ret                         		#return from this function
	.cfi_endproc			    	#Call-Frame-Information for exception-handling and debugging
.LFE0:
	.size	func, .-func
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	main                	#main is global
	.type	main, @function
main:								#main starts here
.LFB1:	
	.cfi_startproc 					#call frame information
	pushq	%rbp					#save rbp on stack
	.cfi_def_cfa_offset 16			#cfi for debugging
	.cfi_offset 6, -16				#cfi for debugging
	movq	%rsp, %rbp				#rsp:new stack base pointer,rsp=rbp
	.cfi_def_cfa_register 6		
	subq	$16, %rsp				#space created for array,parameters,CFA
	movl	$9, -4(%rbp)			#assign value 9 to  %[rbp-4] 
	movl	-4(%rbp), %eax			#assign value of %[rbp-4] to %eax
	movl	%eax, %edi				#edi<-- -4(rbp)
	call	func 					#call function func
	movl	%eax, %esi				#esi<-- -4(rbp)
	leaq	.LC0(%rip), %rdi     	#printing function invoked with value of %rdi
	movl	$0, %eax				#assign 0 to eax
	call	printf@PLT				#calls printf function
	call	getchar@PLT				#calls getchar function
	movl	$0, %eax				#return value is 0
	leave							#clear stack
	.cfi_def_cfa 7, 8				#cfi for debugging
	ret 							#return from this function
	.cfi_endproc					#Call frame information for exception handling and debugging
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 7.1.1 20170630"
	.section	.note.GNU-stack,"",@progbits




#The given program prints the 9th term of fibonacci series which is 34.
#Main function calls the function "func" and passes '9' as argument.
#In main function the a variable is assigned value of 9.
#Then "func" function is called with '9' as argument and its value is stored in a pointer.
#In 'func' function first we initialize an array 'arr' and a variable 'i' which is declared as null.
#Then first element of array is initialized to 1.
#Then second element of array is also initialized to 1.
#Then in a while loop with condition of (i<9) we do the following:
#		while(i<9){
#		arr[i]=arr[i-1]+1;
#		i=i+1;
#		}
#finally returns the arr;
#Now the control comes to main function and its prints the value returns.
#The output of program is 34.
