(import (rnrs))

(define (leap-year? year)
    (cond
      ((= (modulo year 400) 0) #t)
      ((= (modulo year 100) 0) #f)
      ((= (modulo year 4) 0) #t)
      (else #f)
    )
)
