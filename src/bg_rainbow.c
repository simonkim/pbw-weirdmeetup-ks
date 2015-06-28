#include "bg_rainbow.h"
  // red, orange, yellow, green, blue, violet
static GColor s_colors[6];
static bool s_initialized = false;
#define NUM_COLORS (sizeof(s_colors)/sizeof(GColor))
  
void bg_rainbow_update_time(struct tm *tick_time, TimeUnits changed)
{
  if ( !s_initialized ) {
    s_colors[0] = GColorDarkCandyAppleRed;
    s_colors[1] = GColorOrange;
    s_colors[2] = GColorYellow;
    s_colors[3] = GColorDarkGreen;
    s_colors[4] = GColorBlue;
    s_colors[5] = GColorVividViolet;

    s_initialized = true;
  }
}

void bg_rainbow_update_layer(Layer *layer, GContext *ctx)
{
  int i;
  GRect bounds = layer_get_bounds(layer);
  int row_height = bounds.size.h / NUM_COLORS;
  int y = 0;

  for( i = 0; i < (int)NUM_COLORS; i++ ) {
    graphics_context_set_fill_color(ctx, s_colors[i]);
    graphics_fill_rect(ctx, GRect(0, y, bounds.size.w, row_height), 0, GCornerNone);
    y += row_height;
  }
}


