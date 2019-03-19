org 0000h
    mov r0,#40h
    mov b,25
    mov a,5
    clr c
    subb a,b
    mov b,#00h
skip : movx @r0,a
    jnc r0
    movx @r0,a
here : sjpm here
    end