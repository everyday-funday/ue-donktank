// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}



void UTankAimComponent::AimAt(FVector HitLocation, double LaunchSpeed)
{
	//Exit if TankBarrel OR TankTurret is empty
	if (!TankBarrel || !TankTurret) { return; }

	auto TankName = GetOwner() -> GetName();
	FVector OutLaunchVelocity;
	FVector StartLocation = TankBarrel->GetSocketLocation(FName("Projectile"));

	//Checking whether a aim solution exists. i.e. whether it would hit anything.

	FCollisionResponseParams collisionresponse;
	TArray <AActor * > ActorsToIgnore;

	bool bAimSolutionExist = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		collisionresponse,
		ActorsToIgnore,
		false
	);
		
	if (bAimSolutionExist){
	
		//Calculate AimDirection from OutLaunchVelocity
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTo(AimDirection);

	} // Do nothing if no solution is found.

}


void UTankAimComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	TankBarrel = BarrelToSet;
}

void UTankAimComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return;  }
	TankTurret = TurretToSet;
}

void UTankAimComponent::MoveBarrelTo(FVector AimDirection)
{
	// Exit if barrel and turret references are not set.
	if (!TankBarrel || !TankTurret) { return; }

	// Get Aim Direction. Get Current Position (Current Direction).
	// Calculate how much barrel needs to move. Workout the difference. Calculate FRotator
	auto BarrelRotator = TankBarrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	// Always yaw the shortest way
	TankBarrel->Elevate(DeltaRotator.Pitch);

	if (FMath::Abs(DeltaRotator.Yaw) < 180)
	{
		TankTurret->Rotate(DeltaRotator.Yaw);
	}
	else // Avoid going the long-way round
	{
		TankTurret->Rotate(-DeltaRotator.Yaw);
	}
}