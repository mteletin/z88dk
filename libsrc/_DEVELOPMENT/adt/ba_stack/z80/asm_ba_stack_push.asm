
; ===============================================================
; Mar 2014
; ===============================================================
; 
; int ba_stack_push(ba_stack_t *s, int c)
;
; Push item onto stack.
;
; ===============================================================

XLIB asm_ba_stack_push

LIB asm_b_array_append

asm_ba_stack_push:

   jp asm_b_array_append

;defc asm_ba_stack_push = asm_b_array_append

   ; enter : hl = stack *
   ;         bc = int c
   ;
   ; exit  : bc = int c
   ;
   ;         success
   ;
   ;            de = & stack.data[idx]
   ;            hl = idx of appended char
   ;            carry reset
   ;
   ;         fail
   ;
   ;            hl = -1
   ;            carry set, errno = ENOMEM
   ;
   ; uses  : af, de, hl
