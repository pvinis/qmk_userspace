#pragma once


#ifdef PRODUCT
  #undef PRODUCT
  #define PRODUCT "Unicorne - pvinis"
#endif

#ifdef AUDIO_ENABLE
#    undef STARTUP_SONG
#    define STARTUP_SONG SONG(COIN_SOUND)
#endif

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_LEFT
