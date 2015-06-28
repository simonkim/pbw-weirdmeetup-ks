#include "bg_randcol.h"

static struct bg_random_color_context s_bg_randcol_ctx;

void bg_randcol_update_time(struct tm *tick_time, TimeUnits changed)
{
    for(int i = 0; i < 3; i++) {
      s_bg_randcol_ctx.s_color_channels[i] = rand() % 256;
    }
}


void bg_randcol_update_layer(Layer *layer, GContext *ctx)
{
  // Color background?
    graphics_context_set_fill_color(ctx, GColorFromRGB(s_bg_randcol_ctx.s_color_channels[0], s_bg_randcol_ctx.s_color_channels[1], s_bg_randcol_ctx.s_color_channels[2]));
    graphics_fill_rect(ctx, GRect(0, 0, 144, 168), 0, GCornerNone);
}

