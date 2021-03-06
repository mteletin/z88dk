
// automatically generated by m4 from headers in proto subdir


#ifndef _ADT_BA_PRIORITY_QUEUE_H
#define _ADT_BA_PRIORITY_QUEUE_H

#include <stddef.h>

// DATA STRUCTURES

typedef struct ba_priority_queue_s
{

   void       *compar;
   void       *data;
   size_t      size;
   size_t      capacity;

} ba_priority_queue_t;

extern size_t ba_priority_queue_capacity(ba_priority_queue_t *q) __preserves_regs(b,c,d,e);
extern size_t ba_priority_queue_capacity_fastcall(ba_priority_queue_t *q) __preserves_regs(b,c,d,e) __z88dk_fastcall;
#define ba_priority_queue_capacity(a) ba_priority_queue_capacity_fastcall(a)


extern void ba_priority_queue_clear(ba_priority_queue_t *q) __preserves_regs(b,c,d,e);
extern void ba_priority_queue_clear_fastcall(ba_priority_queue_t *q) __preserves_regs(a,b,c,d,e) __z88dk_fastcall;
#define ba_priority_queue_clear(a) ba_priority_queue_clear_fastcall(a)


extern void *ba_priority_queue_data(ba_priority_queue_t *q) __preserves_regs(b,c,d,e);
extern void *ba_priority_queue_data_fastcall(ba_priority_queue_t *q) __preserves_regs(b,c,d,e) __z88dk_fastcall;
#define ba_priority_queue_data(a) ba_priority_queue_data_fastcall(a)


extern void ba_priority_queue_destroy(ba_priority_queue_t *q) __preserves_regs(b,c,d,e);
extern void ba_priority_queue_destroy_fastcall(ba_priority_queue_t *q) __preserves_regs(b,c,d,e) __z88dk_fastcall;
#define ba_priority_queue_destroy(a) ba_priority_queue_destroy_fastcall(a)


extern int ba_priority_queue_empty(ba_priority_queue_t *q) __preserves_regs(b,c,d,e);
extern int ba_priority_queue_empty_fastcall(ba_priority_queue_t *q) __preserves_regs(b,c,d,e) __z88dk_fastcall;
#define ba_priority_queue_empty(a) ba_priority_queue_empty_fastcall(a)


extern ba_priority_queue_t *ba_priority_queue_init(void *p,void *data,size_t capacity,void *compar);
extern ba_priority_queue_t *ba_priority_queue_init_callee(void *p,void *data,size_t capacity,void *compar) __z88dk_callee;
#define ba_priority_queue_init(a,b,c,d) ba_priority_queue_init_callee(a,b,c,d)


extern int ba_priority_queue_pop(ba_priority_queue_t *q);
extern int ba_priority_queue_pop_fastcall(ba_priority_queue_t *q) __z88dk_fastcall;
#define ba_priority_queue_pop(a) ba_priority_queue_pop_fastcall(a)


extern int ba_priority_queue_push(ba_priority_queue_t *q,int c);
extern int ba_priority_queue_push_callee(ba_priority_queue_t *q,int c) __z88dk_callee;
#define ba_priority_queue_push(a,b) ba_priority_queue_push_callee(a,b)


extern int ba_priority_queue_resize(ba_priority_queue_t *q,size_t n);
extern int ba_priority_queue_resize_callee(ba_priority_queue_t *q,size_t n) __z88dk_callee;
#define ba_priority_queue_resize(a,b) ba_priority_queue_resize_callee(a,b)


extern size_t ba_priority_queue_size(ba_priority_queue_t *q) __preserves_regs(b,c,d,e);
extern size_t ba_priority_queue_size_fastcall(ba_priority_queue_t *q) __preserves_regs(b,c,d,e) __z88dk_fastcall;
#define ba_priority_queue_size(a) ba_priority_queue_size_fastcall(a)


extern int ba_priority_queue_top(ba_priority_queue_t *q);
extern int ba_priority_queue_top_fastcall(ba_priority_queue_t *q) __z88dk_fastcall;
#define ba_priority_queue_top(a) ba_priority_queue_top_fastcall(a)



#endif
