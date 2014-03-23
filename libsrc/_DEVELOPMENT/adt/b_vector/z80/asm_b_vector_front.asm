
; ===============================================================
; Mar 2014
; ===============================================================
; 
; int b_vector_front(b_vector_t *v)
;
; Return char stored at front of vector.
;
; ===============================================================

XLIB asm_b_vector_front

LIB asm_b_array_front

asm_b_vector_front:

   jp asm_b_array_front

;defc asm_b_vector_front = asm_b_array_front

   ; enter : hl = vector *
   ;
   ; exit  : de = vector.data
   ;         bc = vector.size
   ;
   ;         success
   ;
   ;            hl = char at front of vector
   ;            carry reset
   ;
   ;         fail if vector is empty
   ;
   ;            hl = -1
   ;            carry set, errno = EINVAL
   ;
   ; uses  : af, bc, de, hl
