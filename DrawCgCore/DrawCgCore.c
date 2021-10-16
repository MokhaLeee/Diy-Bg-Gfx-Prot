#include "include/gbafe.h"

void _BgMap_ApplyTsa(u16* dest, const u16* src, u16 tileBase);
extern void TsaAnime_ApplyTsa(u16* dest, const u16* src, u16 WdithFix, u16 HeightFix, u16 tileBase ); // 0x800159D

extern u16 BgGfx[];
extern u16 BgTSA[];
extern u16 BgPal[];




void DrawCgExample(Proc* proc){

	// Gfx
	u16* GfxDest = (u16*)( GetBgTileDataOffset(3)+0x6000000 );
	Decompress(BgGfx,GfxDest);
	
	// Tsa
	FillBgMap(gBg3MapBuffer,0);
	_BgMap_ApplyTsa(gBg3MapBuffer, BgTSA, 0x8000);
	EnableBgSyncByMask(0b00100);
	
/* 	FillBgMap(gBg2MapBuffer,0);
	TsaAnime_ApplyTsa(gBg2MapBuffer, BgTSA,0,0, 0x8000);
	EnableBgSyncByMask(0b00100); */
	
	// Pal
	CopyToPaletteBuffer(BgPal,0x100,0x100);
	EnablePaletteSync();

	return;
}



#ifndef MOKHA_ARMFUNC_H
#define MOKHA_ARMFUNC_H
typedef struct TileTitle TileTitle;
struct TileTitle{
	u8 width;
	u8 height;
	u16 tiles[];
};
#endif // MOKHA_ARMFUNC_H


void _BgMap_ApplyTsa(u16* dest, const u16* src, u16 tileBase){
	TileTitle* tsa = (TileTitle*)src;
	u8 Width  = tsa->width;
	u8 Height = tsa->height;
	u16* DestCur = dest + (Height<<0x5); // u16
	u16* SrcCur  = &(tsa->tiles[0]);
	
	for(u8 y=0; y<(Height+1); y++)
	{
		for(u8 x=0; x<(Width+1); x++)
			*(DestCur++) = *(SrcCur++) + tileBase;
		DestCur = DestCur - 0x21 - Width;
	}
	
	return;
}
