// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class TANKARENA_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ATankPlayerController();

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	/// AimTowardsCrosshair function helps moving the turret barrel towards where the cross hair is pointing at. 
	/// Requires ray casting straight through the tank to cross hair (line trace)
	void AimTowardsCrosshair();

	/// Return an OUT parameter, true if hit landscape. OUT parameters use references
	bool GetSightRayHitLocation( FVector& HitLocation ) const;

	/// Get Look direction of the tank
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	/// Line-cast to check what the ray hits
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	
	//float timeSeconds = 0;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000; //10km reach

};
