// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward Declaration
class UTankBarrel;
class UTankTurret;
class UTankAimComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class TANKARENA_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Setter: Setting a method (SetBarrelReference) that can be called in BP
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// Setter: Setting a method to set Turret mesh class reference that can be called in BP
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	// Aim fxn calls the TankAimingComponent for aiming
	void AimAt(FVector HitLocation);

	//Fire a projectile
	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();


protected:

	UPROPERTY(BlueprintReadOnly)
	UTankAimComponent* TankAimComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;
	virtual void BeginPlay() override;

private:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UClass* ProjectileBlueprint; 
	// Alternative https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/TSubclassOf/index.html
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//Default firing speed
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	double LaunchSpeed = 4000; // Fires at 1000m/s

	//firing rate
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3;

	//Local Barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;


	double LastFireTime = 0;
};
