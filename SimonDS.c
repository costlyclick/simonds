#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>
#include "soundbank.h"
#include "soundbank_bin.h"
#include "blank.h"
#include "blue.h"
#include "dead.h"
#include "green.h"
#include "red.h"
#include "yellow.h"
#include "intro1.h"
#include "intro2.h"
#include "intro3.h"
#include "intro4.h"
#include "intro5.h"
#include "intro6.h"
#include "intro7.h"
#include "intro8.h"

int main() {
	videoSetMode(MODE_5_2D);
    vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
	
	mmInitDefaultMem((mm_addr)soundbank_bin);
	mmLoad(MOD_EM2);
	mmLoadEffect(SFX_BLUE);
	mmLoadEffect(SFX_FAIL);
	mmLoadEffect(SFX_GREEN);
	mmLoadEffect(SFX_RED);
	mmLoadEffect(SFX_YELLOW);
	mmSetModuleVolume(200);
	mmStart(MOD_EM2, MM_PLAY_LOOP);
	
	mm_sound_effect blue = {{SFX_BLUE}, (int)(1.0f * (1<<10)), 0, 255, 255,};
	mm_sound_effect fail = {{SFX_FAIL}, (int)(1.0f * (1<<10)), 0, 255, 255,};
	mm_sound_effect green = {{SFX_GREEN}, (int)(1.0f * (1<<10)), 0, 255, 255,};
	mm_sound_effect red = {{SFX_RED}, (int)(1.0f * (1<<10)), 0, 255, 255,};
	mm_sound_effect yellow = {{SFX_YELLOW}, (int)(1.0f * (1<<10)), 0, 255, 255,};

	int hscore = 0;

while(1) {
	consoleDemoInit();
	long long int ticks = 0;
	char seq[20];
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	int cnt4 = 0;
	int score = 0;
	int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0,0);

	iprintf("\n\n");
	iprintf("        _                    \n");
	iprintf("    ___(_)_ __ __ ____ _ ___ \n");
	iprintf("   |   | | '  '  |    | '_  |\n");
	iprintf("   | __| | || || |  _ | | | |\n");
	iprintf("   |__ | | || || | |_|| | | |\n");
	iprintf("   |   | | || || |    | | | |\n");
	iprintf("   |___|_|_||_||_|____|_| |_|\n\n\n\n");
	iprintf("       Press the ANY key!\n\n");
	iprintf("    SimonDS by Kyle 20200404\n\n");
	iprintf("          High Score: %d\n\n", hscore);

	while(1) {
		for(int i = 0; i < 6; i++) swiWaitForVBlank();
		dmaCopy(intro1Bitmap, bgGetGfxPtr(bg3), 256*256);
		dmaCopy(intro1Pal, BG_PALETTE, 256*2);
		for(int i = 0; i < 2; i++) ticks ++;
		scanKeys();
		if (keysDown()) break;
		for(int i = 0; i < 6; i++) swiWaitForVBlank();
		dmaCopy(intro2Bitmap, bgGetGfxPtr(bg3), 256*256);
		dmaCopy(intro2Pal, BG_PALETTE, 256*2);
		for(int i = 0; i < 3; i++) ticks ++;
		scanKeys();
		if (keysDown()) break;
		for(int i = 0; i < 6; i++) swiWaitForVBlank();
		dmaCopy(intro3Bitmap, bgGetGfxPtr(bg3), 256*256);
		dmaCopy(intro3Pal, BG_PALETTE, 256*2);
		for(int i = 0; i < 4; i++) ticks ++;
		scanKeys();
		if (keysDown()) break;
		for(int i = 0; i < 6; i++) swiWaitForVBlank();	
		dmaCopy(intro4Bitmap, bgGetGfxPtr(bg3), 256*256);
		dmaCopy(intro4Pal, BG_PALETTE, 256*2);
		for(int i = 0; i < 5; i++) ticks ++;
		scanKeys();
		if (keysDown()) break;
		for(int i = 0; i < 6; i++) swiWaitForVBlank();
		dmaCopy(intro5Bitmap, bgGetGfxPtr(bg3), 256*256);
		dmaCopy(intro5Pal, BG_PALETTE, 256*2);
		for(int i = 0; i < 6; i++) ticks ++;
		scanKeys();
		if (keysDown()) break;
		for(int i = 0; i < 6; i++) swiWaitForVBlank();
		dmaCopy(intro6Bitmap, bgGetGfxPtr(bg3), 256*256);
		dmaCopy(intro6Pal, BG_PALETTE, 256*2);
		for(int i = 0; i < 6; i++) ticks ++;
		scanKeys();
		if (keysDown()) break;
		for(int i = 0; i < 6; i++) swiWaitForVBlank();
		dmaCopy(intro7Bitmap, bgGetGfxPtr(bg3), 256*256);
		dmaCopy(intro7Pal, BG_PALETTE, 256*2);
		for(int i = 0; i < 7; i++) ticks ++;
		scanKeys();
		if (keysDown()) break;
		for(int i = 0; i < 6; i++) swiWaitForVBlank();
		dmaCopy(intro8Bitmap, bgGetGfxPtr(bg3), 256*256);
		dmaCopy(intro8Pal, BG_PALETTE, 256*2);
		for(int i = 0; i < 8; i++) ticks ++;
		scanKeys();
		if (keysDown()) break;
	}
	mmStop();
	
	ticks = ticks*1928374650918276;
	sprintf(seq, "%llu", ticks);
//	iprintf("ticks: %s\n", seq);

	for(int i=0;i<strlen(seq);i++)
	{
		cnt3=0;
		while(cnt3<cnt1) {
			if(seq[cnt3] == '0' || seq[cnt3] == '1' || seq[cnt3] == '2') {
				mmEffectEx(&yellow);
				swiWaitForVBlank();
				dmaCopy(yellowBitmap, bgGetGfxPtr(bg3), 256*256);
				dmaCopy(yellowPal, BG_PALETTE, 256*2);
			}
			if(seq[cnt3] == '3' || seq[cnt3] == '4') {
				mmEffectEx(&blue);
				swiWaitForVBlank();
				dmaCopy(blueBitmap, bgGetGfxPtr(bg3), 256*256);
				dmaCopy(bluePal, BG_PALETTE, 256*2);
			}
			if(seq[cnt3] == '5' || seq[cnt3] == '6') {
				mmEffectEx(&green);
				swiWaitForVBlank();
				dmaCopy(greenBitmap, bgGetGfxPtr(bg3), 256*256);
				dmaCopy(greenPal, BG_PALETTE, 256*2);
			}
			if(seq[cnt3] == '7' || seq[cnt3] == '8' || seq[cnt3] == '9') {
				mmEffectEx(&red);
				swiWaitForVBlank();
				dmaCopy(redBitmap, bgGetGfxPtr(bg3), 256*256);
				dmaCopy(redPal, BG_PALETTE, 256*2);
			}
			cnt3++;
			
			for(int i = 0; i < 20; i++) swiWaitForVBlank();
			dmaCopy(blankBitmap, bgGetGfxPtr(bg3), 256*256);
			dmaCopy(blankPal, BG_PALETTE, 256*2);	
		}

		cnt4=0;
		while(cnt4<cnt2) {
			while(1) {
				scanKeys();
				if (keysDown()&KEY_A) {
					if(seq[cnt4] == '0' || seq[cnt4] == '1' || seq[cnt4] == '2' ) {
						mmEffectEx(&yellow);
						swiWaitForVBlank();
						dmaCopy(yellowBitmap, bgGetGfxPtr(bg3), 256*256);
						dmaCopy(yellowPal, BG_PALETTE, 256*2);
						break;
					}
					else {
						i = 100;
						cnt4 = 100;
						break;
					}
				}
				if (keysDown()&KEY_B) {
					if(seq[cnt4] == '3' || seq[cnt4] == '4') {
						mmEffectEx(&blue);
						swiWaitForVBlank();
						dmaCopy(blueBitmap, bgGetGfxPtr(bg3), 256*256);
						dmaCopy(bluePal, BG_PALETTE, 256*2);
						break;
					}
					else {
						i = 100;
						cnt4 = 100;
						break;
					}
				}
				if (keysDown()&KEY_X) {
					if(seq[cnt4] == '5' || seq[cnt4] == '6') {
						mmEffectEx(&green);
						swiWaitForVBlank();
						dmaCopy(greenBitmap, bgGetGfxPtr(bg3), 256*256);
						dmaCopy(greenPal, BG_PALETTE, 256*2);
						break;
					}
					else {
						i = 100;
						cnt4 = 100;
						break;
					}
				}
				if (keysDown()&KEY_Y) {
					if(seq[cnt4] == '7' || seq[cnt4] == '8' || seq[cnt4] == '9') {
						mmEffectEx(&red);
						swiWaitForVBlank();
						dmaCopy(redBitmap, bgGetGfxPtr(bg3), 256*256);
						dmaCopy(redPal, BG_PALETTE, 256*2);
						break;
					}
					else {
						i = 100;
						cnt4 = 100;
						break;
					}
				}
			}
			cnt4++;
			for(int i = 0; i < 10; i++) swiWaitForVBlank();
	    }
		cnt1++;
		cnt2++;
		score++;

		if (cnt1 == 2) { for(int i = 0; i < 30; i++) swiWaitForVBlank(); }
		for(int i = 0; i < 30; i++) swiWaitForVBlank();
		dmaCopy(blankBitmap, bgGetGfxPtr(bg3), 256*256);
		dmaCopy(blankPal, BG_PALETTE, 256*2);	
	}

	iprintf("          Your Score: %d\n", score-1);
	swiWaitForVBlank();
	mmEffectEx(&fail);
	if (score == 2) { 
		dmaCopy(deadBitmap, bgGetGfxPtr(bg3), 256*256);
		dmaCopy(deadPal, BG_PALETTE, 256*2);
	}
	if (score > hscore) { hscore = score-1; }
	for(int i = 0; i < 180; i++) swiWaitForVBlank();
	
}
}