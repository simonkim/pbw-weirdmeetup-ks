#pragma once
#include <pebble.h>

typedef struct {
  void *priv;
} wt_ctx_t;

typedef enum {
  WT_TICKS_NORMAL
} WT_TYPE;

void wt_init(wt_ctx_t *ctx, WT_TYPE wt_type);
void wt_deinit(wt_ctx_t *ctx);
void wt_draw(wt_ctx_t *ctx, GContext *gctx, int radius, GPoint center);