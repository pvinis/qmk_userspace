#pragma once

#include "musical_notes.h"

// preview
// https://getreuer.info/posts/keyboards/qmk-song-player/index.html?AABPEGyAUBBsEFJAbBBQEGxATxBsQEsQbBBIYNLb

#define COIN_SOUND E__NOTE(_A5), HD_NOTE(_E6),

#define ONE_UP_SOUND Q__NOTE(_E6), Q__NOTE(_G6), Q__NOTE(_E7), Q__NOTE(_C7), Q__NOTE(_D7), Q__NOTE(_G7),

#define SONIC_RING E__NOTE(_E6), E__NOTE(_G6), HD_NOTE(_C7),

#define OLD_SPICE Q__NOTE(_A4 ), Q__NOTE(_A4 ),  H__NOTE(_B4 ), H__NOTE(_D5 ), H__NOTE(_CS5), Q__NOTE(_E5 ), H__NOTE(_FS5), H__NOTE(_D5 ),

#define LP_NUMB H__NOTE(_CS5), H__NOTE(_E5), H__NOTE(_CS5), WD_NOTE(_FS5), WD_NOTE(_A5), WD_NOTE(_GS5),   WD_NOTE(_REST),  H__NOTE(_CS5), H__NOTE(_E5), H__NOTE(_CS5), WD_NOTE(_A5), WD_NOTE(_GS5), WD_NOTE(_E5),

// https://www.youtube.com/watch?v=Wwye2nOKMjI
#define KATAMARI_ROLLING_STAR \
  Q__NOTE(_G6),               \
  B__NOTE(_REST),             \
  Q__NOTE(_GS6),              \
  Q__NOTE(_REST),             \
  W__NOTE(_AS6),              \
  Q__NOTE(_REST),             \
  Q__NOTE(_GS6),              \
  W__NOTE(_REST),             \
  Q__NOTE(_G6),               \
  W__NOTE(_REST),             \
  Q__NOTE(_DS6),              \
  Q__NOTE(_REST),             \
  WD_NOTE(_C6)
