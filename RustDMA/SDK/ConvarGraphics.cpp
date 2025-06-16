#include "Pch.h"
#include "ConvarGraphics.h"
#include "Globals.h"

ConvarGraphics::ConvarGraphics()
{
	printf("[ConvarGraphics] Initialized\n");
	uint64_t graphics = mem.Read<uint64_t>(mem.GetBaseDaddy(LIT("GameAssembly.dll")) + Class); // Get Class Start Address
	printf("[ConvarGraphics] ConvarGraphics: 0x%llX\n", graphics);
	this->StaticField = mem.Read<uint64_t>(graphics + StaticField); // Set Static Padding
	printf("[ConvarGraphics] Static Fields: 0x%llX\n", StaticField);
}
void ConvarGraphics::WriteFOV(float fov)
{
	if(!mem.Write<float>(StaticField + FOV, fov))
	printf("[ConvarGraphics] Failed to write FOV\n");
}