#include "Pch.h"
#include "Globals.h"
#include "TODSky.h"

TODSky::TODSky()
{
	printf("[TODSky] Initialized\n");
	Class = mem.Read<uint64_t>(mem.GetBaseDaddy(LIT("GameAssembly.dll")) + Class);
	printf("[TODSky] Class: 0x%llX\n", Class);
	StaticField = mem.Read<uint64_t>(Class + StaticField); // static field and 0x0 is 	private static List<TOD_Sky> instances;
	StaticField = mem.Read<uint64_t>(StaticField + 0x0);
	uint64_t intancevalues = mem.Read<uint64_t>(StaticField + 0x10); // 0x10 = list values
	Instance = mem.Read<uint64_t>(intancevalues + 0x20); // first value in instances list
	printf("[TODSky] Instance: 0x%llX\n", Instance);
	NightParameters = mem.Read<uint64_t>(Instance + NightParameters);
	DayParameters = mem.Read<uint64_t>(Instance + DayParameters);

}
void TODSky::WriteNightLightIntensity(VMMDLL_SCATTER_HANDLE handle, float value)
{
	
	if(!mem.AddScatterWriteRequest(handle,NightParameters + LightIntensityNight, &value))
			printf("[TODSky] Failed to write Night Light Intensity\n");
}
void TODSky::WriteNightAmbientMultiplier(VMMDLL_SCATTER_HANDLE handle, float value)
{
	if(!mem.AddScatterWriteRequest(handle,NightParameters + AmbientMultiplierNight, &value))
				printf("[TODSky] Failed to write Night Ambient Multiplier\n");
}
void TODSky::WriteDayAmbientMultiplier(VMMDLL_SCATTER_HANDLE handle, float value)
{
	if(!mem.AddScatterWriteRequest(handle,DayParameters + AmbientMultiplierDay, &value))
					printf("[TODSky] Failed to write Day Ambient Multiplier\n");
}