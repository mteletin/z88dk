
; ===============================================================
; Mar 2014
; ===============================================================
; 
; void w_array_destroy(w_array_t *a)
;
; Zero the array structure.
; array.capacity = 0 ensures no array operations can be performed.
;
; ===============================================================

XLIB asm_w_array_destroy

LIB asm_b_array_destroy

asm_w_array_destroy:

   jp asm_b_array_destroy

;defc asm_w_array_destroy = asm_b_array_destroy

   ; enter : hl = array *
   ;
   ; uses  : af, hl
