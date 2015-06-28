#pragma once
#include <pebble.h>
  
void bg_rainbow_update_time(struct tm *tick_time, TimeUnits changed);
void bg_rainbow_update_layer(Layer *layer, GContext *ctx);

