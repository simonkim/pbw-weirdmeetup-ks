#pragma once
#include <pebble.h>
struct bg_random_color_context {
  int s_color_channels[3];
};

void bg_randcol_update_time(struct tm *tick_time, TimeUnits changed);
void bg_randcol_update_layer(Layer *layer, GContext *ctx);
