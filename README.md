# Diy-Bg-Gfx-Prot

## How to install
- Assemble ```Buildfile.event``` by Event Assembler or refer to [Ultimate Tutorial](https://tutorial.feuniverse.us/buildbasics).

## How to compile C
- Correctly install DevkitPro and open Msys2 in ```DrawCgCore/```, then ```sh build.sh```.

## Notes
Function in ```DrawCgCore.c``` mainly refer to 0x800E7D0 of FE8U, which is draw CGs routine in Vanilla.

The Gfx/TSA/Pal are all exported by ```FEBuilder -> Image Editor -> BackGround -> Graphics Editor -> Data Dump```.

Now I can correctly draw the gfx on screen. But have no idea to Show the background and lightning at the same time.In addition, I currently have no way to show Lightning in front of units, which is just like [what I made](https://feuniverse.us/t/fe8-map-tsa-anime-of-fe7s-limstella-style-big-lightning-and-adaptable-to-any-other-diy-animations/13508) on reference to TSA Anime before. 

I feel that these problems are no longer something I can solve, so I decided to temporarily stop researching on this issue. I have sorted out the part of the picture display program, so that you can easily handle it and do further research. 

## Logs
- 2021.10.06 Update the decomp of function ```void BgMap_ApplyTsa(u16* dest, const u16* src, u16 tileBase); ```
