#include "sequencer_defines.h"
#include "alt_types.h"
#if HCX_COMPAT_MODE || ENABLE_INST_ROM_WRITE
const alt_u32 ac_rom_init_size = 27;
const alt_u32 ac_rom_init[27] = 
{
	0x207fffff,
	0x10783010,
	0x10783010,
	0x10705020,
	0x10701030,
	0x107ff0a0,
	0x107003f0,
	0x307fffff,
	0x10700002,
	0x10700082,
	0x1070001b,
	0x14f00001,
	0x14f00081,
	0x14f01001,
	0x14f01081,
	0x30ffffff,
	0x34ffffff,
	0x307fffff,
	0x10700001,
	0x10f00001,
	0x13700005,
	0x13700085,
	0x13701005,
	0x13701085,
	0x337fffff,
	0x10701005,
	0x1070000c
};
#endif
