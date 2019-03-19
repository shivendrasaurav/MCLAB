org 0000h
    mov r0,#40h
    mov a,#5
    mov b,#5
    mul ab
    movx @r0,a
    inc r0
    mov a,b
    movx @r0,a
here : sjmp here
    end