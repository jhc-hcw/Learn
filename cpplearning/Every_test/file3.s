	.text
	.file	"file3.c"
	.globl	scale                           # -- Begin function scale
	.p2align	4, 0x90
	.type	scale,@function
scale:                                  # @scale
	.cfi_startproc
# %bb.0:
	leaq	(%rdi,%rsi,4), %rax
	leaq	(%rdx,%rdx,2), %rcx
	leaq	(%rax,%rcx,4), %rax
	retq
.Lfunc_end0:
	.size	scale, .Lfunc_end0-scale
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 14.0.0-1ubuntu1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
