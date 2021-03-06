/*
 * Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.
 *
 * (c) Copyright 1996 - 2001 Gary Henderson (gary.henderson@ntlworld.com) and
 *                           Jerremy Koot (jkoot@snes9x.com)
 *
 * Super FX C emulator code 
 * (c) Copyright 1997 - 1999 Ivar (ivar@snes9x.com) and
 *                           Gary Henderson.
 * Super FX assembler emulator code (c) Copyright 1998 zsKnight and _Demo_.
 *
 * DSP1 emulator code (c) Copyright 1998 Ivar, _Demo_ and Gary Henderson.
 * C4 asm and some C emulation code (c) Copyright 2000 zsKnight and _Demo_.
 * C4 C code (c) Copyright 2001 Gary Henderson (gary.henderson@ntlworld.com).
 *
 * DOS port code contains the works of other authors. See headers in
 * individual files.
 *
 * Snes9x homepage: http://www.snes9x.com
 *
 * Permission to use, copy, modify and distribute Snes9x in both binary and
 * source form, for non-commercial purposes, is hereby granted without fee,
 * providing that this license information and copyright notice appear with
 * all copies and any derived work.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event shall the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Snes9x is freeware for PERSONAL USE only. Commercial users should
 * seek permission of the copyright holders first. Commercial use includes
 * charging money for Snes9x or software derived from Snes9x.
 *
 * The copyright holders request that bug fixes and improvements to the code
 * should be forwarded to them so everyone can benefit from the modifications
 * in future versions.
 *
 * Super NES and Super Nintendo Entertainment System are trademarks of
 * Nintendo Co., Limited and its subsidiary companies.
 */

#include <string.h>
// #include "tchar.h"
#include "font.h"

//
// Font: THIN8X8.pf
// Exported from PixelFontEdit 2.7.0

static unsigned char gui_font[2048] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 000 (.)
	0x7E, 0x81, 0xA5, 0x81, 0xBD, 0x99, 0x81, 0x7E,	// Char 001 (.)
	0x7E, 0xFF, 0xDB, 0xFF, 0xC3, 0xE7, 0xFF, 0x7E,	// Char 002 (.)
	0x6C, 0xFE, 0xFE, 0xFE, 0x7C, 0x38, 0x10, 0x00,	// Char 003 (.)
	0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x10, 0x00,	// Char 004 (.)
	0x38, 0x7C, 0x38, 0xFE, 0xFE, 0x7C, 0x38, 0x7C,	// Char 005 (.)
	0x10, 0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x7C,	// Char 006 (.)
	0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00,	// Char 007 (.)
	0xFF, 0xFF, 0xE7, 0xC3, 0xC3, 0xE7, 0xFF, 0xFF,	// Char 008 (.)
	0x00, 0x3C, 0x66, 0x42, 0x42, 0x66, 0x3C, 0x00,	// Char 009 (.)
	0xFF, 0xC3, 0x99, 0xBD, 0xBD, 0x99, 0xC3, 0xFF,	// Char 010 (.)
	0x0F, 0x07, 0x0F, 0x7D, 0xCC, 0xCC, 0xCC, 0x78,	// Char 011 (.)
	0x3C, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x7E, 0x18,	// Char 012 (.)
	0x3F, 0x33, 0x3F, 0x30, 0x30, 0x70, 0xF0, 0xE0,	// Char 013 (.)
	0x7F, 0x63, 0x7F, 0x63, 0x63, 0x67, 0xE6, 0xC0,	// Char 014 (.)
	0x99, 0x5A, 0x3C, 0xE7, 0xE7, 0x3C, 0x5A, 0x99,	// Char 015 (.)
	0x80, 0xE0, 0xF8, 0xFE, 0xF8, 0xE0, 0x80, 0x00,	// Char 016 (.)
	0x02, 0x0E, 0x3E, 0xFE, 0x3E, 0x0E, 0x02, 0x00,	// Char 017 (.)
	0x18, 0x3C, 0x7E, 0x18, 0x18, 0x7E, 0x3C, 0x18,	// Char 018 (.)
	0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x00,	// Char 019 (.)
	0x7F, 0xDB, 0xDB, 0x7B, 0x1B, 0x1B, 0x1B, 0x00,	// Char 020 (.)
	0x3E, 0x63, 0x38, 0x6C, 0x6C, 0x38, 0xCC, 0x78,	// Char 021 (.)
	0x00, 0x00, 0x00, 0x00, 0x7E, 0x7E, 0x7E, 0x00,	// Char 022 (.)
	0x18, 0x3C, 0x7E, 0x18, 0x7E, 0x3C, 0x18, 0xFF,	// Char 023 (.)
	0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x00,	// Char 024 (.)
	0x18, 0x18, 0x18, 0x18, 0x7E, 0x3C, 0x18, 0x00,	// Char 025 (.)
	0x00, 0x18, 0x0C, 0xFE, 0x0C, 0x18, 0x00, 0x00,	// Char 026 (.) right arrow
	0x00, 0x30, 0x60, 0xFE, 0x60, 0x30, 0x00, 0x00,	// Char 027 (.)
	0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xFE, 0x00, 0x00,	// Char 028 (.)
	0x00, 0x24, 0x66, 0xFF, 0x66, 0x24, 0x00, 0x00,	// Char 029 (.)
	0x00, 0x18, 0x3C, 0x7E, 0xFF, 0xFF, 0x00, 0x00,	// Char 030 (.)
	0x00, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00, 0x00,	// Char 031 (.)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 032 ( )
	0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x40, 0x00,	// Char 033 (!)
	0x90, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 034 (")
	0x50, 0x50, 0xF8, 0x50, 0xF8, 0x50, 0x50, 0x00,	// Char 035 (#)
	0x20, 0x78, 0xA0, 0x70, 0x28, 0xF0, 0x20, 0x00,	// Char 036 ($)
	0xC8, 0xC8, 0x10, 0x20, 0x40, 0x98, 0x98, 0x00,	// Char 037 (%)
	0x70, 0x88, 0x50, 0x20, 0x54, 0x88, 0x74, 0x00,	// Char 038 (&)
	0x60, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 039 (')
	0x20, 0x40, 0x80, 0x80, 0x80, 0x40, 0x20, 0x00,	// Char 040 (()
	0x20, 0x10, 0x08, 0x08, 0x08, 0x10, 0x20, 0x00,	// Char 041 ())
	0x00, 0x20, 0xA8, 0x70, 0x70, 0xA8, 0x20, 0x00,	// Char 042 (*)
	0x00, 0x00, 0x20, 0x20, 0xF8, 0x20, 0x20, 0x00,	// Char 043 (+)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x20, 0x40,	// Char 044 (,)
	0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00,	// Char 045 (-)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x00,	// Char 046 (.)
	0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00,	// Char 047 (/)
	0x70, 0x88, 0x98, 0xA8, 0xC8, 0x88, 0x70, 0x00,	// Char 048 (0)
	0x40, 0xC0, 0x40, 0x40, 0x40, 0x40, 0xE0, 0x00,	// Char 049 (1)
	0x70, 0x88, 0x08, 0x10, 0x20, 0x40, 0xF8, 0x00,	// Char 050 (2)
	0x70, 0x88, 0x08, 0x10, 0x08, 0x88, 0x70, 0x00,	// Char 051 (3)
	0x08, 0x18, 0x28, 0x48, 0xFC, 0x08, 0x08, 0x00,	// Char 052 (4)
	0xF8, 0x80, 0x80, 0xF0, 0x08, 0x88, 0x70, 0x00,	// Char 053 (5)
	0x20, 0x40, 0x80, 0xF0, 0x88, 0x88, 0x70, 0x00,	// Char 054 (6)
	0xF8, 0x08, 0x10, 0x20, 0x40, 0x40, 0x40, 0x00,	// Char 055 (7)
	0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x70, 0x00,	// Char 056 (8)
	0x70, 0x88, 0x88, 0x78, 0x08, 0x08, 0x70, 0x00,	// Char 057 (9)
	0x00, 0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x00,	// Char 058 (:)
	0x00, 0x00, 0x60, 0x60, 0x00, 0x60, 0x60, 0x20,	// Char 059 (;)
	0x10, 0x20, 0x40, 0x80, 0x40, 0x20, 0x10, 0x00,	// Char 060 (<)
	0x00, 0x00, 0xF8, 0x00, 0xF8, 0x00, 0x00, 0x00,	// Char 061 (=)
	0x80, 0x40, 0x20, 0x10, 0x20, 0x40, 0x80, 0x00,	// Char 062 (>)
	0x78, 0x84, 0x04, 0x08, 0x10, 0x00, 0x10, 0x00,	// Char 063 (?)
	0x70, 0x88, 0x88, 0xA8, 0xB8, 0x80, 0x78, 0x00,	// Char 064 (@)
	0x20, 0x50, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x00,	// Char 065 (A)
	0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0xF0, 0x00,	// Char 066 (B)
	0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70, 0x00,	// Char 067 (C)
	0xF0, 0x88, 0x88, 0x88, 0x88, 0x88, 0xF0, 0x00,	// Char 068 (D)
	0xF8, 0x80, 0x80, 0xE0, 0x80, 0x80, 0xF8, 0x00,	// Char 069 (E)
	0xF8, 0x80, 0x80, 0xE0, 0x80, 0x80, 0x80, 0x00,	// Char 070 (F)
	0x70, 0x88, 0x80, 0x80, 0x98, 0x88, 0x78, 0x00,	// Char 071 (G)
	0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88, 0x00,	// Char 072 (H)
	0xE0, 0x40, 0x40, 0x40, 0x40, 0x40, 0xE0, 0x00,	// Char 073 (I)
	0x38, 0x10, 0x10, 0x10, 0x10, 0x90, 0x60, 0x00,	// Char 074 (J)
	0x88, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x88, 0x00,	// Char 075 (K)
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xF8, 0x00,	// Char 076 (L)
	0x82, 0xC6, 0xAA, 0x92, 0x82, 0x82, 0x82, 0x00,	// Char 077 (M)
	0x84, 0xC4, 0xA4, 0x94, 0x8C, 0x84, 0x84, 0x00,	// Char 078 (N)
	0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00,	// Char 079 (O)
	0xF0, 0x88, 0x88, 0xF0, 0x80, 0x80, 0x80, 0x00,	// Char 080 (P)
	0x70, 0x88, 0x88, 0x88, 0xA8, 0x90, 0x68, 0x00,	// Char 081 (Q)
	0xF0, 0x88, 0x88, 0xF0, 0xA0, 0x90, 0x88, 0x00,	// Char 082 (R)
	0x70, 0x88, 0x80, 0x70, 0x08, 0x88, 0x70, 0x00,	// Char 083 (S)
	0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00,	// Char 084 (T)
	0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00,	// Char 085 (U)
	0x88, 0x88, 0x88, 0x50, 0x50, 0x20, 0x20, 0x00,	// Char 086 (V)
	0x82, 0x82, 0x82, 0x82, 0x92, 0x92, 0x6C, 0x00,	// Char 087 (W)
	0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x00,	// Char 088 (X)
	0x88, 0x88, 0x88, 0x50, 0x20, 0x20, 0x20, 0x00,	// Char 089 (Y)
	0xF8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8, 0x00,	// Char 090 (Z)
	0xE0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xE0, 0x00,	// Char 091 ([)
	0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00,	// Char 092 (\)
	0xE0, 0x20, 0x20, 0x20, 0x20, 0x20, 0xE0, 0x00,	// Char 093 (])
	0x20, 0x50, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 094 (^)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00,	// Char 095 (_)
	0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 096 (`)
	0x00, 0x00, 0x70, 0x08, 0x78, 0x88, 0x74, 0x00,	// Char 097 (a)
	0x80, 0x80, 0xB0, 0xC8, 0x88, 0xC8, 0xB0, 0x00,	// Char 098 (b)
	0x00, 0x00, 0x70, 0x88, 0x80, 0x88, 0x70, 0x00,	// Char 099 (c)
	0x08, 0x08, 0x68, 0x98, 0x88, 0x98, 0x68, 0x00,	// Char 100 (d)
	0x00, 0x00, 0x70, 0x88, 0xF8, 0x80, 0x70, 0x00,	// Char 101 (e)
	0x30, 0x48, 0x40, 0xE0, 0x40, 0x40, 0x40, 0x00,	// Char 102 (f)
	0x00, 0x00, 0x34, 0x48, 0x48, 0x38, 0x08, 0x30,	// Char 103 (g)
	0x80, 0x80, 0xB0, 0xC8, 0x88, 0x88, 0x88, 0x00,	// Char 104 (h)
	0x20, 0x00, 0x60, 0x20, 0x20, 0x20, 0x70, 0x00,	// Char 105 (i)
	0x10, 0x00, 0x30, 0x10, 0x10, 0x10, 0x90, 0x60,	// Char 106 (j)
	0x80, 0x80, 0x88, 0x90, 0xA0, 0xD0, 0x88, 0x00,	// Char 107 (k)
	0xC0, 0x40, 0x40, 0x40, 0x40, 0x40, 0xE0, 0x00,	// Char 108 (l)
	0x00, 0x00, 0xEC, 0x92, 0x92, 0x92, 0x92, 0x00,	// Char 109 (m)
	0x00, 0x00, 0xB0, 0xC8, 0x88, 0x88, 0x88, 0x00,	// Char 110 (n)
	0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00,	// Char 111 (o)
	0x00, 0x00, 0xB0, 0xC8, 0xC8, 0xB0, 0x80, 0x80,	// Char 112 (p)
	0x00, 0x00, 0x68, 0x98, 0x98, 0x68, 0x08, 0x08,	// Char 113 (q)
	0x00, 0x00, 0xB0, 0xC8, 0x80, 0x80, 0x80, 0x00,	// Char 114 (r)
	0x00, 0x00, 0x78, 0x80, 0x70, 0x08, 0xF0, 0x00,	// Char 115 (s)
	0x40, 0x40, 0xE0, 0x40, 0x40, 0x50, 0x20, 0x00,	// Char 116 (t)
	0x00, 0x00, 0x88, 0x88, 0x88, 0x98, 0x68, 0x00,	// Char 117 (u)
	0x00, 0x00, 0x88, 0x88, 0x88, 0x50, 0x20, 0x00,	// Char 118 (v)
	0x00, 0x00, 0x82, 0x82, 0x92, 0x92, 0x6C, 0x00,	// Char 119 (w)
	0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00,	// Char 120 (x)
	0x00, 0x00, 0x88, 0x88, 0x98, 0x68, 0x08, 0x70,	// Char 121 (y)
	0x00, 0x00, 0xF8, 0x10, 0x20, 0x40, 0xF8, 0x00,	// Char 122 (z)
	0x10, 0x20, 0x20, 0x40, 0x20, 0x20, 0x10, 0x00,	// Char 123 ({)
	0x40, 0x40, 0x40, 0x00, 0x40, 0x40, 0x40, 0x00,	// Char 124 (|)
	0x40, 0x20, 0x20, 0x10, 0x20, 0x20, 0x40, 0x00,	// Char 125 (})
	0x76, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 126 (~)
	0x00, 0x10, 0x38, 0x6C, 0xC6, 0xC6, 0xFE, 0x00	// Char 127 (.)
};

static char *font[] = {
"           .      . .                    .                ..       .      .                                                     ",
"          .#.    .#.#.    . .     ...   .#. .     .      .##.     .#.    .#.     . .       .                                .   ",
"          .#.    .#.#.   .#.#.   .###.  .#..#.   .#.     .#.     .#.      .#.   .#.#.     .#.                              .#.  ",
"          .#.    .#.#.  .#####. .#.#.    ..#.   .#.#.   .#.      .#.      .#.    .#.     ..#..           ....             .#.   ",
"          .#.     . .    .#.#.   .###.   .#..    .#.     .       .#.      .#.   .###.   .#####.   ..    .####.    ..     .#.    ",
"           .            .#####.   .#.#. .#..#.  .#.#.            .#.      .#.    .#.     ..#..   .##.    ....    .##.   .#.     ",
"          .#.            .#.#.   .###.   . .#.   .#.#.            .#.    .#.    .#.#.     .#.    .#.             .##.    .      ",
"           .              . .     ...       .     . .              .      .      . .       .    .#.               ..            ",
"                                                                                                 .                              ",
"  .       .       ..     ....      .     ....     ..     ....     ..      ..                                              .     ",
" .#.     .#.     .##.   .####.    .#.   .####.   .##.   .####.   .##.    .##.     ..      ..       .             .       .#.    ",
".#.#.   .##.    .#..#.   ...#.   .##.   .#...   .#..     ...#.  .#..#.  .#..#.   .##.    .##.     .#.    ....   .#.     .#.#.   ",
".#.#.    .#.     . .#.   .##.   .#.#.   .###.   .###.     .#.    .##.   .#..#.   .##.    .##.    .#.    .####.   .#.     ..#.   ",
".#.#.    .#.      .#.    ...#.  .####.   ...#.  .#..#.    .#.   .#..#.   .###.    ..      ..    .#.      ....     .#.    .#.    ",
".#.#.    .#.     .#..   .#..#.   ..#.   .#..#.  .#..#.   .#.    .#..#.    ..#.   .##.    .##.    .#.    .####.   .#.      .     ",
" .#.    .###.   .####.   .##.     .#.    .##.    .##.    .#.     .##.    .##.    .##.    .#.      .#.    ....   .#.      .#.    ",
"  .      ...     ....     ..       .      ..      ..      .       ..      ..      ..    .#.        .             .        .     ",
"                                                                                         .                                      ",
"  ..      ..     ...      ..     ...     ....    ....     ..     .  .    ...        .    .  .    .       .   .   .   .    ..    ",
" .##.    .##.   .###.    .##.   .###.   .####.  .####.   .##.   .#..#.  .###.      .#.  .#..#.  .#.     .#. .#. .#. .#.  .##.   ",
".#..#.  .#..#.  .#..#.  .#..#.  .#..#.  .#...   .#...   .#..#.  .#..#.   .#.       .#.  .#.#.   .#.     .##.##. .##..#. .#..#.  ",
".#.##.  .#..#.  .###.   .#. .   .#..#.  .###.   .###.   .#...   .####.   .#.       .#.  .##.    .#.     .#.#.#. .#.#.#. .#..#.  ",
".#.##.  .####.  .#..#.  .#. .   .#..#.  .#..    .#..    .#.##.  .#..#.   .#.     . .#.  .##.    .#.     .#...#. .#.#.#. .#..#.  ",
".#...   .#..#.  .#..#.  .#..#.  .#..#.  .#...   .#.     .#..#.  .#..#.   .#.    .#..#.  .#.#.   .#...   .#. .#. .#..##. .#..#.  ",
" .##.   .#..#.  .###.    .##.   .###.   .####.  .#.      .###.  .#..#.  .###.    .##.   .#..#.  .####.  .#. .#. .#. .#.  .##.   ",
"  ..     .  .    ...      ..     ...     ....    .        ...    .  .    ...      ..     .  .    ....    .   .   .   .    ..    ",
"                                                                                                                                ",
" ...      ..     ...      ..     ...     .   .   .   .   .   .   .  .    . .     ....    ...             ...      .             ",
".###.    .##.   .###.    .##.   .###.   .#. .#. .#. .#. .#. .#. .#..#.  .#.#.   .####.  .###.    .      .###.    .#.            ",
".#..#.  .#..#.  .#..#.  .#..#.   .#.    .#. .#. .#. .#. .#...#. .#..#.  .#.#.    ...#.  .#..    .#.      ..#.   .#.#.           ",
".#..#.  .#..#.  .#..#.   .#..    .#.    .#. .#. .#. .#. .#.#.#.  .##.   .#.#.     .#.   .#.      .#.      .#.    . .            ",
".###.   .#..#.  .###.    ..#.    .#.    .#. .#. .#. .#. .#.#.#. .#..#.   .#.     .#.    .#.       .#.     .#.                   ",
".#..    .##.#.  .#.#.   .#..#.   .#.    .#...#.  .#.#.  .##.##. .#..#.   .#.    .#...   .#..       .#.   ..#.            ....   ",
".#.      .##.   .#..#.   .##.    .#.     .###.    .#.   .#. .#. .#..#.   .#.    .####.  .###.       .   .###.           .####.  ",
" .        ..#.   .  .     ..      .       ...      .     .   .   .  .     .      ....    ...             ...             ....   ",
"            .                                                                                                                   ",
" ..              .                  .              .             .        .        .     .       ..                             ",
".##.            .#.                .#.            .#.           .#.      .#.      .#.   .#.     .##.                            ",
" .#.      ...   .#..      ..      ..#.    ..     .#.#.    ...   .#..     ..        .    .#..     .#.     .. ..   ...      ..    ",
"  .#.    .###.  .###.    .##.    .###.   .##.    .#..    .###.  .###.   .##.      .#.   .#.#.    .#.    .##.##. .###.    .##.   ",
"   .    .#..#.  .#..#.  .#..    .#..#.  .#.##.  .###.   .#..#.  .#..#.   .#.      .#.   .##.     .#.    .#.#.#. .#..#.  .#..#.  ",
"        .#.##.  .#..#.  .#..    .#..#.  .##..    .#.     .##.   .#..#.   .#.     ..#.   .#.#.    .#.    .#...#. .#..#.  .#..#.  ",
"         .#.#.  .###.    .##.    .###.   .##.    .#.    .#...   .#..#.  .###.   .#.#.   .#..#.  .###.   .#. .#. .#..#.   .##.   ",
"          . .    ...      ..      ...     ..      .      .###.   .  .    ...     .#.     .  .    ...     .   .   .  .     ..    ",
"                                                          ...                     .                                             ",
"                                  .                                                        .      .      .        . .           ",
"                                 .#.                                                      .#.    .#.    .#.      .#.#.          ",
" ...      ...    ...      ...    .#.     .  .    . .     .   .   .  .    .  .    ....    .#.     .#.     .#.    .#.#.           ",
".###.    .###.  .###.    .###.  .###.   .#..#.  .#.#.   .#...#. .#..#.  .#..#.  .####.  .##.     .#.     .##.    . .            ",
".#..#.  .#..#.  .#..#.  .##..    .#.    .#..#.  .#.#.   .#.#.#.  .##.   .#..#.   ..#.    .#.     .#.     .#.                    ",
".#..#.  .#..#.  .#. .    ..##.   .#..   .#..#.  .#.#.   .#.#.#.  .##.    .#.#.   .#..    .#.     .#.     .#.                    ",
".###.    .###.  .#.     .###.     .##.   .###.   .#.     .#.#.  .#..#.    .#.   .####.    .#.    .#.    .#.                     ",
".#..      ..#.   .       ...       ..     ...     .       . .    .  .    .#.     ....      .      .      .                      ",
" .          .                                                             .                                                     ",
};

static int font_width = 8;
static int font_height = 9;

void DisplayChar (uint16 *Screen, uint8 c, uint16 resW)
{
	int line = (((c & 0x7f) - 32) >> 4) * font_height;
	int offset = (((c & 0x7f) - 32) & 15) * font_width;

	int h, w;
	uint16 *s = (uint16 *) Screen;

	for (h = 0; h < font_height; h++, line++,
		s += resW - font_width)
	{
		for (w = 0; w < font_width; w++, s++)
		{
			uint8 p = font [line][offset + w];

			if (p == '#')
				*s = 0xffff;
			else
				if (p == '.')
					*s = 0x0000;//BLACK;
		}
	}
}

void DrawString (const char *string, uint16 *screen, uint8 x, uint8 y, uint16 resW)
{
	uint16 *Screen = screen + 2 + x + y * resW;
	int len = strnlen (string,50);
	int max_chars = resW / (font_width - 2);
	int char_count = 0;
	int i;
	
	if (len > 47) len = 47;
	
	for (i = 0; i < len; i++, char_count++)
	{
		if (char_count >= max_chars || string [i] < 32)
		{
			Screen -= (font_width - 1) * max_chars;
			Screen += font_height * resW/*pitch*/;
			if (Screen >= screen + resW/*pitch*/ * 240)
				break;
			char_count -= max_chars;
		}
		if (string [i] < 32)
			continue;
		DisplayChar (Screen, string [i], resW);
		Screen += (font_width - 2);// * sizeof (uint16); 
	}
}

void DrawRect ( uint16 *screen, int x, int y, int w, int h, int c , uint16 resW)
{
	uint16 cc = (c & 0x00F80000) >> 8 | (c & 0x0000F800) >> 5 | (c & 0x000000F8) >> 3;
	uint16 *Screen = screen + x + y * resW;
	uint16 * ss;
	int ww, hh = h;
	while ( --hh > 0) {
		ww = w;
		ss = Screen;
		Screen += resW;
		while ( --ww > 0) {
			*ss = cc;
			ss ++;
		}
	}
}


/*
	Prints char on a menu surface
*/
void DrawChar(SDL_Surface *sfc, int x, int y, unsigned char a, int fg_color, int bg_color)
{
	Uint16 *dst;
	int w, h;

	if(SDL_MUSTLOCK(sfc)) SDL_LockSurface(sfc);
	for(h = 8; h; h--) {
		dst = (Uint16 *)sfc->pixels + (y+8-h)*sfc->w + x;
		for(w = 8; w; w--) {
			Uint16 color = bg_color; // background
			if((gui_font[a*8 + (8-h)] >> w) & 1) color = fg_color; // test bits 876543210
			*dst++ = color;
		}
	}
	if(SDL_MUSTLOCK(sfc)) SDL_UnlockSurface(sfc);
}

/*
	Draws a string on a menu surface
*/
void DrawString2(SDL_Surface *sfc, const char *s, unsigned short fg_color, unsigned short bg_color, int x, int y)
{
	int i, j = strlen(s);
	for (i = 0; i < j; i++, x += 8) {
		if (s[i] == NULL || x >= sfc->w - 9) return;
		DrawChar(sfc, x, y, s[i], fg_color, bg_color);
	}
}
