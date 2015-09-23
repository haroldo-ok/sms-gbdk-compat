#ifndef _HARDWARE_H
#define _HARDWARE_H

#include <types.h>

#define NO_REG		(*(UBYTE *)0x0000)	/* Nowhere */
#define P1_REG		NO_REG	/* Joystick: 1.1.P15.P14.P13.P12.P11.P10 */
#define SB_REG		NO_REG	/* Serial IO data buffer */
#define SC_REG		NO_REG	/* Serial IO control register */
#define DIV_REG		NO_REG	/* Divider register */
#define TIMA_REG	NO_REG	/* Timer counter */
#define TMA_REG		NO_REG	/* Timer modulo */
#define TAC_REG		NO_REG	/* Timer control */
#define IF_REG		NO_REG	/* Interrupt flags: 0.0.0.JOY.SIO.TIM.LCD.VBL */
#define NR10_REG	NO_REG	/* Sound register */
#define NR11_REG	NO_REG	/* Sound register */
#define NR12_REG	NO_REG	/* Sound register */
#define NR13_REG	NO_REG	/* Sound register */
#define NR14_REG	NO_REG	/* Sound register */
#define NR21_REG	NO_REG	/* Sound register */
#define NR22_REG	NO_REG	/* Sound register */
#define NR23_REG	NO_REG	/* Sound register */
#define NR24_REG	NO_REG	/* Sound register */
#define NR30_REG	NO_REG	/* Sound register */
#define NR31_REG	NO_REG	/* Sound register */
#define NR32_REG	NO_REG	/* Sound register */
#define NR33_REG	NO_REG	/* Sound register */
#define NR34_REG	NO_REG	/* Sound register */
#define NR41_REG	NO_REG	/* Sound register */
#define NR42_REG	NO_REG	/* Sound register */
#define NR43_REG	NO_REG	/* Sound register */
#define NR44_REG	NO_REG	/* Sound register */
#define NR50_REG	NO_REG	/* Sound register */
#define NR51_REG	NO_REG	/* Sound register */
#define NR52_REG	NO_REG	/* Sound register */
#define LCDC_REG	NO_REG	/* LCD control */
#define STAT_REG	NO_REG	/* LCD status */
#define SCY_REG		NO_REG	/* Scroll Y */
#define SCX_REG		NO_REG	/* Scroll X */
#define LY_REG		NO_REG	/* LCDC Y-coordinate */
#define LYC_REG		NO_REG	/* LY compare */
#define DMA_REG		NO_REG	/* DMA transfer */
#define BGP_REG		NO_REG	/* BG palette data */
#define OBP0_REG	NO_REG	/* OBJ palette 0 data */
#define OBP1_REG	NO_REG	/* OBJ palette 1 data */
#define WY_REG		NO_REG	/* Window Y coordinate */
#define WX_REG		NO_REG	/* Window X coordinate */
#define KEY1_REG	NO_REG	/* CPU speed */
#define VBK_REG		NO_REG	/* VRAM bank */
#define HDMA1_REG	NO_REG	/* DMA control 1 */
#define HDMA2_REG	NO_REG	/* DMA control 2 */
#define HDMA3_REG	NO_REG	/* DMA control 3 */
#define HDMA4_REG	NO_REG	/* DMA control 4 */
#define HDMA5_REG	NO_REG	/* DMA control 5 */
#define RP_REG		NO_REG	/* IR port */
#define BCPS_REG	NO_REG	/* BG color palette specification */
#define BCPD_REG	NO_REG	/* BG color palette data */
#define OCPS_REG	NO_REG	/* OBJ color palette specification */
#define OCPD_REG	NO_REG	/* OBJ color palette data */
#define SVBK_REG	NO_REG	/* WRAM bank */
#define IE_REG		NO_REG	/* Interrupt enable */

#endif /* _HARDWARE_H */
