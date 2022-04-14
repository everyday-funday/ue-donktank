// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "TankArena.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	
	// Get relative speed and rotate the turret.
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -2, +2);
	auto RotateChange = RelativeSpeed * MaxDegreesPerSecond * (GetWorld()->DeltaTimeSeconds);
	auto Rotation = GetRelativeRotation().Yaw + RotateChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));

}
