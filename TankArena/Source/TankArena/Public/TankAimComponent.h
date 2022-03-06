// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"

// Forward Declaration - allow us to reference UTankBarrel.
class UTankBarrel; //Hold parameters for Barrel's properties and elevate
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKARENA_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);	
	void SetTurretReference(UTankTurret* TurretToSet);

	UTankBarrel* TankBarrel = nullptr;
	UTankTurret* TankTurret = nullptr;

	void AimAt(FVector HitLocation, double LaunchSpeed);

protected:

private:

	void MoveBarrelTo(FVector AimDirection);
};
