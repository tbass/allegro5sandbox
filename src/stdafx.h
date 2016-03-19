#ifndef STDAFX_H
#define STDAFX_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#ifdef WIN32
    // VC13 seems to not have the type def "uint"
    #define uint unsigned int
#endif

#endif // STDAFX_H

