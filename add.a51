org 0000h
    mov r0,#40h 
    mov b,#10
    mov a,#15
    add a,b
    mov b,#00
    jnc skip
    mov b,#01h
skip : movx @r0, a
    jnc r0
    mov a,b
    movx @r0,a
here : sjmp here
    end