#include "wt_ticks_normal.h"
#define HAND_MARGIN  10
#define NUM_TICKS  12
typedef struct {
  bool ticks_ready;
  GPoint ticks[NUM_TICKS];
  int radius;
} wt_ticks_normal_ctx_t;


/*
 * @minutes  0 ~ 59
 */
static GPoint handpoint(int minutes, int radius, GPoint center)
{
  float angle = TRIG_MAX_ANGLE * minutes / 60;
  int32_t distance =  (int32_t)(radius - HAND_MARGIN) ;
  GPoint point = (GPoint) {
    .x = (int16_t)(sin_lookup(angle) * distance / TRIG_MAX_RATIO) + center.x,
    .y = (int16_t)(-cos_lookup(angle) * distance / TRIG_MAX_RATIO) + center.y,
  };

  return point;  
}

void wt_normal_draw_ticks(wt_ticks_normal_ctx_t *pctx, GContext *ctx, int radius, GPoint center)
{
    int i;
  
    if ( !pctx->ticks_ready || pctx->radius != radius ) {
      for (i = 0; i < NUM_TICKS; i++) {
        pctx->ticks[i] = handpoint(i * 5, radius, center);
      }  
      pctx->ticks_ready = true;
    }
    
    //graphics_context_set_fill_color(ctx, GColorRed );
    graphics_context_set_stroke_color(ctx, GColorDarkGray  );
    graphics_context_set_stroke_width(ctx, 2);

    for (i = 0; i < NUM_TICKS; i++) {
      GRect rect;
      rect.origin = pctx->ticks[i];
      rect.size.w = 6;
      rect.size.h = 6;
      rect.origin.x -= 3;
      rect.origin.y -= 3;
      //graphics_fill_rect(ctx, rect, 0, GCornerNone);
      graphics_draw_rect(ctx, rect);
    } 
  
    pctx->radius = radius;
}

void wt_init(wt_ctx_t *ctx, WT_TYPE wt_type)
{
  wt_ticks_normal_ctx_t *pctx = (wt_ticks_normal_ctx_t *) malloc(sizeof(wt_ticks_normal_ctx_t));
  pctx->ticks_ready = false;
  pctx->radius = 0;
  ctx->priv = pctx;
}

void wt_deinit(wt_ctx_t *ctx)
{
  free(ctx->priv);
  ctx->priv = NULL;
}

void wt_draw(wt_ctx_t *ctx, GContext *gctx, int radius, GPoint center)
{
  wt_ticks_normal_ctx_t *pctx = (wt_ticks_normal_ctx_t *) ctx->priv;
  wt_normal_draw_ticks(pctx, gctx, radius, center);
}