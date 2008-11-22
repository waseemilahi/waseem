;;Waseem Ilahi
;;CIS 24
;;Challenge Assignment.

;;QuickSort Algorithm for list of numbers. (ascending order)

;;First we choose the pivot point.
(define (pivot mylist)
  (cond
    [(empty? mylist) 'done]
    [(empty? (cdr mylist)) 'done]
    [(<= (car mylist) (cadr mylist)) (pivot (cdr mylist))]
    [#t (car mylist)]
  )
)

; Partition the list to make recursive calls.
(define (partition mypivot mylist p1 p2)
  (if (empty? mylist) (list p1 p2)
     (if (< (car mylist) mypivot) 
         (partition mypivot (cdr mylist) (cons (car mylist) p1) p2)
	 (partition mypivot (cdr mylist) p1 (cons (car mylist) p2))
     )
  )
)

;; Thw Main Quicksort Function.
(define (quicksort mylist)
   (if (equal? (pivot mylist) 'done) mylist
       (append (quicksort (car (partition (pivot mylist) mylist empty empty))) 
               (quicksort (cadr(partition (pivot mylist) mylist empty empty)))
       )
   )
)