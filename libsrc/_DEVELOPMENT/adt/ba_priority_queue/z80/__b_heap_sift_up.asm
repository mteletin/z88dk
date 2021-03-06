SECTION code_clib
SECTION code_adt_ba_priority_queue

PUBLIC __b_heap_sift_up

EXTERN l_compare_de_hl, error_znc

__b_heap_sift_up:

   ; assumes 1-based array
   ;
   ; enter : de = start_index in bytes
   ;         hl = & array[start_index]
   ;         bc = array
   ;         ix = compare
   ;
   ; exit  ; hl = 0
   ;         carry reset
   ;
   ; uses  : af, bc, de, hl

   ld a,e
   and $fe
   or d
   jp z, error_znc             ; if start_index <= 1, root reached so return success
   
   srl d
   rr e                        ; de = parent_index(start_index)
   
   push de                     ; save parent_index
   
   ex de,hl                    ; de = & array[start_index]
   add hl,bc                   ; hl = & array[parent_index]

   call l_compare_de_hl        ; (compar)(de = void *child, hl = void *parent)
   jp p, error_znc - 1         ; if array[child] >= array[parent], finished so return success

   push bc                     ; save array

   ; swap(array[child], array[parent])
   
   ; de = & array[child]
   ; hl = & array[parent]
   ; stack = parent_index, array

   ld c,(hl)
   ld a,(de)
   ld (hl),a
   ld a,c
   ld (de),a

   pop bc                      ; bc = array
   pop de                      ; de = parent_index
   
   ; hl = & array[parent]
   ; de = parent_index
   ; bc = array
   
   jr __b_heap_sift_up
