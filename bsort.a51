org 0000h
    mov r0,#05h
l1 : mov dptr
    mov a,r0
    mov r1,a
l2 : mov a,@dptr
    mov b,a
    inc dptr
    movx a,@dptr
    clr c
    mov r2,a
    subb a,b
    jnc noxch
    mov a,b
    movx @dptr,a
    dce dpl
    mov a,r2
    movx @dptr,a
    inc dptr
noxch : djnz r1,l2
    djnc r0,l1
here : sjmp here
    end