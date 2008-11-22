;;Waseem Ilahi
;;CIS 24
;;HomeWork # 1

;;Reversing the list of symbols.

;;i) The main subroutine.
(define (rotate mylist)
  (reverse-list mylist empty))

;;ii) The auxillary function.
(define (reverse-list mylist result)
  (cond
    [(empty? mylist) result]
    [else 
     (reverse-list (cdr mylist) (cons (car mylist) result))]))
    