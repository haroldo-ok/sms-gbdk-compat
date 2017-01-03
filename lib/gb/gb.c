#define TARGET_GG
#include <gb.h>
#include <stdlib.h>

/* library variables */
UBYTE smsgbdk_scrollX, smsgbdk_scrollY;

#pragma disable_warning 85
void add_VBL(int_handler h) {}
void remove_VBL(UINT8 h) {}
void add_LCD(int_handler h) {}
void remove_LCD(UINT8 h) {}
void add_TIM(int_handler h) {}
void add_SIO(int_handler h) {}
void add_JOY(int_handler h) {}

void mode(UBYTE m) {}
UBYTE	get_mode(void) { return 0; }

/* ************************************************************ */


void delay(UWORD d) {
  for (; d; d--) {
    //  TO DO: see how this compares to original delay
    __asm
      nop
    __endasm;

  }
}


/* ************************************************************ */


UBYTE joypad(void) {
  UWORD key = SMS_getKeysStatus();
  return key | ((key & GG_KEY_START) ? J_START : 0);
}

UBYTE waitpad(UBYTE mask) {
  UBYTE joy;
  while (!(joy = joypad() & mask)) {
    wait_vbl_done();
  }
  return joy;
}

void waitpadup(void) {
  while (joypad()) {
    wait_vbl_done();
  }
}


/* ************************************************************ */


void enable_interrupts(void) {}

void disable_interrupts(void) {}

void set_interrupts(UBYTE flags) {}

void reset(void) {
  __asm
    di
    ld hl,#0x0000
    jp (hl)
  __endasm;
}

void wait_vbl_done(void) {
  SMS_waitForVBlank();
  SMS_copySpritestoSAT();
  SMS_setBGScrollX(smsgbdk_scrollX+(256-160)/2);
  SMS_setBGScrollY(smsgbdk_scrollY+0xC8);
}

void display_off(void) {
  SMS_displayOff();
}


/* ************************************************************ */

void SMS_loadTiles_2bpp(UWORD first_tile, UWORD nb_tiles, unsigned char *data) {
  UWORD i;
  UBYTE j;
	unsigned char buffer[32], *o, *d;

	o = data;
	for (i = 0; i != nb_tiles; i++) {
		d = buffer;
		for (j = 0; j != 8; j++) {
			*d = *o; o++; d++;
      *d = *o; o++; d++;
			*d = 0;	d++;
			*d = 0;	d++;
		}
		SMS_loadTiles(buffer, i + first_tile, 32);
	}
}

void set_bkg_data(UBYTE first_tile, UBYTE nb_tiles, unsigned char *data) {
  SMS_loadTiles_2bpp(first_tile, nb_tiles, data);
}

void set_bkg_tiles(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char *tiles) {
  UBYTE i;
  UWORD buffer[32], *d;

  for (; h; h--, y++) {
    d = buffer;
    for (i = w; i; i--, d++, tiles++) {
      *d = *tiles;
    }
    SMS_loadTileMapArea(x, y, buffer, w, 1);
  }
}

void get_bkg_tiles(UBYTE x,
	      UBYTE y,
	      UBYTE w,
	      UBYTE h,
	      unsigned char *tiles) {
}

void move_bkg(UBYTE x, UBYTE y) {
  smsgbdk_scrollX=x;
  smsgbdk_scrollY=y;
}

void scroll_bkg(BYTE x, BYTE y) {
  smsgbdk_scrollX-=x;
  smsgbdk_scrollY-=y;
}


/* ************************************************************ */


void set_win_data(UBYTE first_tile, UBYTE nb_tiles, unsigned char *data) {}
void set_win_tiles(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char *tiles) {}
void get_win_tiles(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char *tiles) {}
void move_win(UBYTE x, UBYTE y) {}
void scroll_win(BYTE x, BYTE y) {}


/* ************************************************************ */


extern unsigned char SpriteTableY[];
extern unsigned char SpriteTableXN[];

void set_sprite_data(UBYTE first_tile, UBYTE nb_tiles, unsigned char *data) {
  SMS_loadTiles_2bpp(((UWORD) first_tile) + 256, nb_tiles, data);
}

void get_sprite_data(UBYTE first_tile, UBYTE nb_tiles, unsigned char *data) {}

void set_sprite_tile(UBYTE nb, UBYTE tile) {
  SpriteTableXN[(nb << 1) + 1] = tile;
}

UBYTE get_sprite_tile(UBYTE nb) {
    return SpriteTableXN[(nb << 1) + 1];
}

void set_sprite_prop(UBYTE nb, UBYTE prop) {}

UBYTE get_sprite_prop(UBYTE nb) { return 0; }

void move_sprite(UBYTE nb, UBYTE x, UBYTE y) {
  SpriteTableXN[nb << 1] = x+((256-160)/2-8);
  SpriteTableY[nb] = y+((192-144)/2-16-1);
}

void scroll_sprite(BYTE nb, BYTE x, BYTE y) {
  move_sprite(nb, SpriteTableXN[nb << 1] + x, SpriteTableY[nb] + y);
}


/* ************************************************************ */


void cgb_compatibility(void) {
  GG_setBGPaletteColor (0, 0xDEF);
  GG_setSpritePaletteColor (0, 0xDEF);
  GG_setBGPaletteColor (1, 0x89A);
  GG_setSpritePaletteColor (1, 0x89A);
  GG_setBGPaletteColor (2, 0x455);
  GG_setSpritePaletteColor (2, 0x455);
  GG_setBGPaletteColor (3, 0x022);
  GG_setSpritePaletteColor (3, 0x022);
}

/* ************************************************************ */

void smsgbdk_init(UBYTE mode) {
  unsigned char k;
  move_bkg(0, 0);
  SMS_initSprites ();
  for (k=0;k<128;k++)
    SMS_reserveSprite ();
  SMS_finalizeSprites ();
  if (mode==SMSGBDK_MODE_GBC)
    cgb_compatibility();
  else if (mode==SMSGBDK_MODE_GRAYSCALE) {
    GG_setBGPaletteColor (0, RGBHTML(0xEFEFEF));
    GG_setSpritePaletteColor (0, RGBHTML(0xEFEFEF));
    GG_setBGPaletteColor (1, RGBHTML(0xAEAEAE));
    GG_setSpritePaletteColor (1, RGBHTML(0xAEAEAE));
    GG_setBGPaletteColor (2, RGBHTML(0x535353));
    GG_setSpritePaletteColor (2, RGBHTML(0x535353));
    GG_setBGPaletteColor (3, RGBHTML(0x0C0C0C));
    GG_setSpritePaletteColor (3, RGBHTML(0x0C0C0C));
  } else {   // normal 'green' mode
    GG_setBGPaletteColor (0, RGBHTML(0xDFF9CE));
    GG_setSpritePaletteColor (0, RGBHTML(0xDFF9CE));
    GG_setBGPaletteColor (1, RGBHTML(0x86C16C));
    GG_setSpritePaletteColor (1, RGBHTML(0x86C16C));
    GG_setBGPaletteColor (2, RGBHTML(0x326856));
    GG_setSpritePaletteColor (2, RGBHTML(0x326856));
    GG_setBGPaletteColor (3, RGBHTML(0x071820));
    GG_setSpritePaletteColor (3, RGBHTML(0x071820));
  }
  wait_vbl_done();
}

/* ************************************************************ */


void initrand(UWORD seed) {
  srand(seed);
}

UWORD randw(void) {
  return rand();
}

/*
 * Random generator using the linear lagged additive method
 *
 * Author: Luc Van den Borre
 *
 * Note that 'initarand()' calls 'initrand()' with the same seed value, and
 * uses 'rand()' to initialize the random generator.
 */

void initarand(UWORD seed) {
  srand(seed);
}

UBYTE arand(void) {
  return rand();
}

/* ************************************************************ */

void draw_image(void *image) {
  unsigned int k=0,c,r;
  SMS_loadTiles_2bpp(0, 360, (unsigned char *)image);
  for (r=0;r<18;r++) {
    SMS_setNextTileatXY (0,r);
    c=0;
    do {
      SMS_setTile (k++);
    } while (++c<20);
  }
}

void gotogxy(UBYTE x, UBYTE y) {}

void gprintf(char* s, ...) {}

/* ************************************************************ */