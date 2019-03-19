org 0000h
    mov r0,#40h
    mov b,#2
    mov c,#12
    div ab
    movx @r0,a
    inc r0
    mov a,b
    movx @r0,a
here : sjmp here
    end