// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Math/UnrealMathUtility.h"
#include "TankArena.h"



void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the Barrel the right amount this time.
	// Given a max elevation speed, and the frame time.

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * (GetWorld()->DeltaTimeSeconds);
	/*auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;*/
	auto RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;
	auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}

