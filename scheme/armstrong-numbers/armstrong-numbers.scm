(import (rnrs))

(define (armstrong-number? n)
    (define (loop s)
        (null? s)
            0
            (sum (expt (string->number(cdr s) (length (string-length s)))
    )
    (if (equal? n (loop number->string n))))))
