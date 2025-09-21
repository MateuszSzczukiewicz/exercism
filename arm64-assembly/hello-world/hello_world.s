.data
msg: .asciz "Hello, World!"

.text
.global _hello
_hello:
        adrp    x0, msg@PAGE
        add     x0, x0, msg@PAGEOFF
        ret
