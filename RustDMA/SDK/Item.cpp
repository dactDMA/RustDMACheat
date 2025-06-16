#include "pch.h"
#include "Globals.h"
#include "Item.h"

Item::Item(uint64_t address)
{
	
	Class = address;
//	printf("[Item] Initialized: 0x%llX\n", Class);
//	auto handle = mem.CreateScatterHandle();
//	mem.AddScatterReadRequest(handle, Class + Info,reinterpret_cast<void*>(&Info),sizeof(uint64_t));
//	mem.AddScatterReadRequest(handle, Class + ItemID, reinterpret_cast<void*>(&ItemID), sizeof(uint32_t));
//	mem.AddScatterReadRequest(handle, Class + HeldEntity, reinterpret_cast<void*>(&HeldEntity), sizeof(uint64_t));
//	mem.ExecuteReadScatter(handle);
// 
	//mem.CloseScatterHandle(handle);
	//ItemDefinitionInstance = new ItemDefinition(Info);
	//printf("[Item] ItemID: 0x%llX\n", ItemID);
	//printf("[Item] HeldEntity: 0x%llX\n", HeldEntity);
	ItemID = mem.Read<uint32_t>(Class + ItemID);
	HeldEntity = mem.Read<uint64_t>(Class + HeldEntity);
}
Item::~Item()
{
}
uint32_t Item::GetItemID()
{
	if (Class != 0 && this != nullptr)
		return ItemID;
	else
		return 0;
}

uint64_t Item::GetHeldEntity()
{
	return HeldEntity;
}

std::shared_ptr<BaseProjectile> Item::GetBaseProjectile()
{
	if (HeldEntity == 0)
		return nullptr;
	BaseProjectileInstance = std::make_shared<BaseProjectile>(HeldEntity);
	return BaseProjectileInstance;
}