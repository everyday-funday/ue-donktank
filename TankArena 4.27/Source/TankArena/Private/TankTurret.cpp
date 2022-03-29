// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "TankArena.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	
	//TODO: Resolve gimbal lock issue at 180 degrees yaw.
	auto RotateChange = RelativeSpeed * MaxDegreesPerSecond * (GetWorld()->DeltaTimeSeconds);
	auto Rotation = GetRelativeRotation().Yaw + RotateChange;
	//GetRelativeRotation().Pitch

	SetRelativeRotation(FRotator(0, Rotation, 0));

}
