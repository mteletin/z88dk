
; ===============================================================
; Mar 2014
; ===============================================================
; 
; void *wv_stack_top(wv_stack_t *s)
;
; Return word at top of stack without removing it.
; If the stack is empty, return -1.
;
; ===============================================================

XLIB asm_wv_stack_top

LIB asm_w_array_back

asm_wv_stack_top:

   jp asm_w_array_back

;defc asm_wv_stack_top = asm_w_array_back

   ; enter : hl = stack *
   ;
   ; exit  : success
   ;
   ;            de = & last word in stack
   ;            hl = last word in stack
   ;            carry reset
   ;
   ;         fail if stack is empty
   ;
   ;            hl = -1
   ;            carry set, errno = EINVAL
   ;
   ; uses  : af, bc, de, hl
