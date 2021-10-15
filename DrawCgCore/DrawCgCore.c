#include "include/gbafe.h"
extern u16 BgGfx[];
extern u16 BgTSA[];
extern u16 BgPal[];

void DrawCgExample(Proc* proc){

	// Gfx
	u16* GfxDest = (u16*)( GetBgTileDataOffset(3)+0x6000000 );
	Decompress(BgGfx,GfxDest);
	
	// Tsa
	FillBgMap(gBg3MapBuffer,0);
	BgMap_ApplyTsa(gBg3MapBuffer, BgTSA, 0x8000);
	EnableBgSyncByMask(0b01000);
	
	// Pal
	CopyToPaletteBuffer(BgPal,0x100,0x100);
	EnablePaletteSync();

	return;
}

