#pragma once


#ifdef PRODUCT
  #undef PRODUCT
  #define PRODUCT "Boardsource Unicorne Keyboard - pvinis"
#endif

#ifdef AUDIO_ENABLE
#    undef STARTUP_SONG
#    define STARTUP_SONG SONG(COIN_SOUND)
#endif
