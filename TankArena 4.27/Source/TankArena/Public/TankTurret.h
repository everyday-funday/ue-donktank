// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
Tank Turret is a static mesh component that is use to control the movement of the turret 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKARENA_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeRotateSpeed);


private:
	UPROPERTY(EditAnywhere, Category = Setup) 
	float MaxDegreesPerSecond = 40; // sensible default
	
	//UPROPERTY(EditAnywhere, Category = Setup)
	float MaxRotationDegrees = 175; // sensible default

	//UPROPERTY(EditAnywhere, Category = Setup)
	float MinRotationDegrees = -175; // sensible default

};
