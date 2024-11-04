#pragma once


#ifdef PRODUCT
  #undef PRODUCT
  #define PRODUCT "Unicorne - pvinis"
#endif

#ifdef AUDIO_ENABLE
#    undef STARTUP_SONG
#    define STARTUP_SONG SONG(COIN_SOUND)
#endif


#define POINTING_DEVICE_INVERT_Y

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_COMBINED
#define POINTING_DEVICE_ROTATION_90_RIGHT
