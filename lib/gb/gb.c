
#include <gb.h>

void add_VBL(int_handler h) {}
void add_LCD(int_handler h) {}
void add_TIM(int_handler h) {}
void add_SIO(int_handler h) {}
void add_JOY(int_handler h) {}
void mode(UBYTE m) {}
UBYTE	get_mode(void) {}

/* ************************************************************ */


void delay(UWORD d) {}


/* ************************************************************ */


UBYTE joypad(void) {
  return SMS_getKeysStatus();
}

UBYTE waitpad(UBYTE mask) {
  UBYTE joy;
  while (!(joy = joypad() & mask)) {
    SMS_waitForVBlank();
  }
  return joy;
}

void waitpadup(void) {
  while (joypad()) {
    SMS_waitForVBlank();
  }
}


/* ************************************************************ */


void enable_interrupts(void) {}

void disable_interrupts(void) {}

void set_interrupts(UBYTE flags) {}

void reset(void) {}

void wait_vbl_done(void) {
  SMS_waitForVBlank();
}

void display_off(void) {
  SMS_displayOff();
}


/* ************************************************************ */

void set_bkg_data(UBYTE first_tile, UBYTE nb_tiles, unsigned char *data) {
  SMS_loadTiles (data, first_tile, nb_tiles);
}

void set_bkg_tiles(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char *tiles) {
  SMS_loadTileMapArea(x, y, tiles, w, h);
}

void get_bkg_tiles(UBYTE x,
	      UBYTE y,
	      UBYTE w,
	      UBYTE h,
	      unsigned char *tiles) {
}

void move_bkg(UBYTE x, UBYTE y) {
  SMS_setBGScrollX(x);
  SMS_setBGScrollY(y);
}

void scroll_bkg(BYTE x, BYTE y) {

}


/* ************************************************************ */


void set_win_data(UBYTE first_tile, UBYTE nb_tiles, unsigned char *data) {}
void set_win_tiles(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char *tiles) {}
void get_win_tiles(UBYTE x, UBYTE y, UBYTE w, UBYTE h, unsigned char *tiles) {}
void move_win(UBYTE x, UBYTE y) {}
void scroll_win(BYTE x, BYTE y) {}


/* ************************************************************ */


void set_sprite_data(UBYTE first_tile, UBYTE nb_tiles, unsigned char *data) {}
void get_sprite_data(UBYTE first_tile, UBYTE nb_tiles, unsigned char *data) {}
void set_sprite_tile(UBYTE nb, UBYTE tile) {}
UBYTE get_sprite_tile(UBYTE nb) {}
void set_sprite_prop(UBYTE nb, UBYTE prop) {}
UBYTE get_sprite_prop(UBYTE nb) {}
void move_sprite(UBYTE nb, UBYTE x, UBYTE y) {}
void scroll_sprite(BYTE nb, BYTE x, BYTE y) {}
