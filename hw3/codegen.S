.global codegen
codegen:
    //BEGIN FUNCTION PROLOGUE
    sw s0, -4(sp)      // save sp
    addi sp, sp ,-4
    addi s0, sp, 0     // set new sp
    sw sp, -4(s0)
    sw s1, -8(s0)
    sw s2, -12(s0)
    sw s3, -16(s0)
    sw s4, -20(s0)
    sw s5, -24(s0)
    sw s6, -28(s0)
    sw s7, -32(s0)
    sw s8, -36(s0)
    sw s9, -40(s0)
    sw s10, -44(s0)
    sw s11, -48(s0)
    addi sp, s0, -48   // update sp
    //END FUNCTION PROLOGUE

    li t0, 3
    addi sp, sp, -4
    sw t0, 0(sp)
    li t0, 4
    addi sp, sp, -4
    sw t0, 0(sp)
    lw t0, 4(sp)
    lw t1, 0(sp)
    add t0, t0, t1
    addi sp, sp, 4
    sw t0, 0(sp)
a
    lw t0, -48(sp)
    addi sp, sp, -4
    sw t0, 0(sp)

    // delay(0)
    addi sp, sp, -4
    sw ra, 0(sp)
    li a0, 0
    jal ra, delay
    lw ra, 0(sp)
    addi sp, sp, 4


    //BEGIN FUNCTION EPILOGUE
    lw s11, -48(s0)
    lw s10, -44(s0)
    lw s9, -40(s0)
    lw s8, -36(s0)
    lw s7, -32(s0)
    lw s6, -28(s0)
    lw s5, -24(s0)
    lw s4, -20(s0)
    lw s3, -16(s0)
    lw s2, -12(s0)
    lw s1, -8(s0)
    lw sp, -4(s0)
    addi sp, sp, 4
    lw s0, -4(sp)
    //END FUNCTION EPILOGUE

    jalr zero, 0(ra)   // return
