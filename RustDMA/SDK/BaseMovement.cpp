#include "Pch.h"
#include "BaseMovement.h"
#include "Globals.h"

BaseMovement::BaseMovement(uint64_t address)
{
	this->Class = address;
}

float BaseMovement::GetGroundAngle()
{
	return mem.Read<float>(Class + GroundAngle);
}

float BaseMovement::GetGroundAngleNew()
{
	return mem.Read<float>(Class + GroundAngleNew);
}

float BaseMovement::GetMaxAngleClimbing()
{
	return mem.Read<float>(Class + MaxAngleClimbing);
}

float BaseMovement::GetMaxAngleWalking()
{
	return mem.Read<float>(Class + MaxAngleWalking);
}

float BaseMovement::GetGroundTime()
{
	return mem.Read<float>(Class + GroundTime);
}

float BaseMovement::GetJumpTime()
{
	return mem.Read<float>(Class + JumpTime);
}

float BaseMovement::GetLandTime()
{
	return mem.Read<float>(Class + LandTime);
}

void BaseMovement::WriteGroundAngle(VMMDLL_SCATTER_HANDLE handle, float angle)
{
	mem.AddScatterWriteRequest(handle, Class + GroundAngle, &angle);
}

void BaseMovement::WriteGroundAngleNew(VMMDLL_SCATTER_HANDLE handle, float angle)
{
	mem.AddScatterWriteRequest(handle, Class + GroundAngleNew, &angle);
}

void BaseMovement::WriteMaxAngleClimbing(VMMDLL_SCATTER_HANDLE handle, float angle)
{
	mem.AddScatterWriteRequest(handle, Class + MaxAngleClimbing, &angle);
}

void BaseMovement::WriteMaxAngleWalking(VMMDLL_SCATTER_HANDLE handle, float angle)
{
	mem.AddScatterWriteRequest(handle, Class + MaxAngleWalking, &angle);
	
}

void BaseMovement::WriteGroundTime(VMMDLL_SCATTER_HANDLE handle, float time)
{
	mem.AddScatterWriteRequest(handle, Class + GroundTime, &time);
}

void BaseMovement::WriteJumpTime(VMMDLL_SCATTER_HANDLE handle, float time)
{
	mem.AddScatterWriteRequest(handle, Class + JumpTime, &time);
}

void BaseMovement::WriteLandTime(VMMDLL_SCATTER_HANDLE handle, float time)
{
	mem.AddScatterWriteRequest(handle, Class + LandTime, &time);
}