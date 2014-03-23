
; ===============================================================
; Feb 2014
; ===============================================================
; 
; size_t w_vector_erase_range(w_vector_t *v, size_t idx_first, size_t idx_last)
;
; Remove words at indices [idx_first, idx_last) from the vector.
;
; ===============================================================

XLIB asm_w_vector_erase_range

LIB asm_w_array_erase_range

asm_w_vector_erase_range:

   jp asm_w_array_erase_range

;defc asm_w_vector_erase_range = asm_w_array_erase_range

   ; enter : hl = idx_last
   ;         bc = idx_first
   ;         de = vector *
   ;
   ; exit  : success
   ;
   ;            de = & vector.data[idx]
   ;            hl = idx_first = idx of first word following erased
   ;            carry reset
   ;
   ;         fail if block does not lie within vector.data
   ;
   ;            hl = -1
   ;            carry set, errno = EINVAL
   ;
   ; uses  : af, bc, de, hl
