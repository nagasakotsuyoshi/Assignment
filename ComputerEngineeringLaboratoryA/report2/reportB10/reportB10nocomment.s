		.data
result:		.word	0:40
enter:		.asciiz	"\n"
		.text
		.align	2
		.globl	main
main:
		li	$t0,0
		li	$t5,1
		sw	$t5,result($zero)
		li	$t1,2
kakeloop:
		li	$t2,0
		li	$t3,0
iloop:
		sll	$t6,$t3,2
		lw	$t5,result($t6)
		mult	$t5,$t1
		mflo	$t4
		add	$t4,$t4,$t2
		li	$t5,10000
		div	$t4,$t5
		mflo	$t2
		mfhi	$t6
		sll	$t7,$t3,2
		sw	$t6,result($t7)
		addi	$t3,$t3,1
		ble	$t3,$t0,iloop
		ble	$t2,$zero,else
		addi	$t0,$t0,1
		sll	$t5,$t0,2
		sw	$t2,result($t5)
else:
		addi	$t1,$t1,1
		li	$t5,100
		ble	$t1,$t5,kakeloop
		move	$t3,$t0
printloop:
		sll	$t5,$t3,2
		lw	$a0,result($t5)
		li	$v0,1
		syscall
		addi	$t3,$t3,-1
		bge	$t3,$zero,printloop
		la	$a0,enter
		li	$v0,4
		syscall
		li	$v0,10
		syscall
