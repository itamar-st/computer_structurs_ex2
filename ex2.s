        .file   "ex2.c"
        .align 8
        .section .rodata
        .text
        .globl even
        .type even, @function

even:
        movq    %rsi, %rcx #shift has to be preformed from cl
        movq    %rdi, %rax
        salq    %cl, %rax #num<<i
        ret
        
        .globl go
        .type go, @function

go:
        pushq   %rbp    #setup
        movq    %rsp, %rbp  #setup
        subq    $8, %rsp #2*sizeof int
        xorq    %rax, %rax  #sum = 0
        movq    %rax, %r12  #save sum
        xorq    %rbx, %rbx  #i = 0
        movq    %rdi, %r13  #save A in a callee saved register
        xorq    %rdi, %rdi
L12:
        movl    (%r13, %rbx,4), %edi #A[i] = A+i*4 1st arg register
        movq    %rbx, %rsi  # 2nd arg register
        movl    %edi, %r14d  #tmp save
        and     $1, %r14d    #get the lsb
        cmp     $0, %r14d    #chekc if its 0(devides by 2)
        movl    %edi, %eax  #the value for leaq unless change by even
        jne      L13
        call    even
L13:    
        #call even
        leaq    (%rax, %r12), %r12  #sum+=num
        incq    %rbx    #i++
        cmpq    $9, %rbx    #comapre i:9 rbx-9
        jle      L12    #loop for 10 times
        movq    %r12, %rax  #finish
        movq    %rbp, %rsp  #finish
        popq    %rbp    #finish
        ret

        



