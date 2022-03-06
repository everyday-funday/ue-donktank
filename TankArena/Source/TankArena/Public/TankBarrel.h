// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Tank Barrel is Blueprint spawnable component.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKARENA_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category=Setup)
	float MaxDegreesPerSecond = 5; // sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40; // sensible default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0; // sensible default

};
