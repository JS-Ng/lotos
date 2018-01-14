#ifndef _BUFFER_H__
#define _BUFFER_H__
#include "misc.h"
#include <stdio.h>

typedef char *BUFFER;

/* usually 2M, a request buffer may increase refering to this */
#define BUFFER_LIMIT (BUFSIZ * 250)

typedef struct {
  int len;    /* used space length in buf */
  int free;   /* free space length in buf */
  char buf[]; /* store data */
} buffer_t;

extern buffer_t *buffer_init();
extern buffer_t *buffer_new(size_t initlen);
extern void buffer_free(buffer_t *pb);
extern void buffer_clear(buffer_t *pb);
extern buffer_t *buffer_cat(buffer_t *pb, BUFFER buf, size_t nbyte);
extern void buffer_print(buffer_t *pb);

static inline size_t buffer_len(const buffer_t *pb) { return pb->len; }

static inline size_t buffer_avail(const buffer_t *pb) { return pb->free; }

static inline buffer_t *buffer_buffer(const BUFFER buf) {
  return (buffer_t *)(buf - (sizeof(buffer_t)));
}

static inline BUFFER buffer_end(const buffer_t *pb) {
  return ((BUFFER)(pb->buf) + pb->len);
}

#endif
