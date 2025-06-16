#include "Pch.h"
#include "OcclusionCulling.h"
#include "Globals.h"
OcclusionCulling::OcclusionCulling()
{
	printf("[OcclusionCulling] Initialized\n");
	uint64_t convarculling = mem.Read<uint64_t>(mem.GetBaseDaddy(LIT("GameAssembly.dll")) + Class); // Get Class Start Address
	printf("[OcclusionCulling] OcclusionCulling: 0x%llX\n", convarculling);
	this->StaticField = mem.Read<uint64_t>(convarculling + StaticField); // Set Static Padding
	printf("[OcclusionCulling] Static Fields: 0x%llX\n", StaticField);
	this->Instance = mem.Read<uint64_t>(StaticField +Instance); // instance 
	printf("[OcclusionCulling] Instance: 0x%llX\n", Instance);
	this->DebugSettings = mem.Read<uint64_t>(Instance + DebugSettings);  // debugSettings
	printf("[OcclusionCulling] DebugSettings: 0x%llX\n", Instance);
}

void OcclusionCulling::WriteLayerMask(int mask)
{
	
	if (!mem.Write<int>(this->DebugSettings + 0x20, mask))
	{
		std::printf("[OcclusionCulling] Mask Write Failure");

	}
}

void OcclusionCulling::WriteDebugSettings(DebugFilter debugfilter)
{
	if (!mem.Write<DebugFilter>(this->StaticField + 0x8C, debugfilter))
	{
		std::printf("[OcclusionCulling] Debug Settings Write Failure");

	}
}