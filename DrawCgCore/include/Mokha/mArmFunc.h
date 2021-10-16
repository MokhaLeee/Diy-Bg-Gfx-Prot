#ifndef MOKHA_ARMFUNC_H
#define MOKHA_ARMFUNC_H

typedef struct TileTitle TileTitle;
struct TileTitle{
	u8 width;
	u8 height;
	u16 tiles[];
};

//void BgMap_ApplyTsa(u16* dest, const TileTitle* src, u16 tileBase); //! FE8U = 0x80D74A1


#endif // MOKHA_ARMFUNC_H