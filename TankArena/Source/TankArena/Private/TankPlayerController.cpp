// Fill out your copyright notice in the Description page of Project Settings.



#include "TankPlayerController.h"
#include "Tank.h"
#include "TankArena.h"

#define OUT

ATankPlayerController::ATankPlayerController(){};

void ATankPlayerController::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);

	AimTowardsCrosshair();

}

void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesed to play"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}


///Get the player tank
ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn()); 
}


/// Aiming towards the crosshair
void ATankPlayerController::AimTowardsCrosshair() {

	//Prevent method from running if controller fails to acquire, return right away.
	if (!GetControlledTank()) { return; }


	FVector HitLocation; //Out parameter declared. Get initialized through GetSightHit Location method.

	if (GetSightRayHitLocation(HitLocation))
	{
		

		/*if it hits landscape:
			// TODO: Tell controlled tank to aim at this point.
		  if it hits an emeny tank:
			// TODO: indicate that enemy tank is detected
			// TODO: Tell Controlled tank to aim at this point.
		*/

		GetControlledTank() -> AimAt(HitLocation);

	}

	return;
}


///  Get world location of line trace through cross-hair
bool ATankPlayerController::GetSightRayHitLocation( FVector& HitLocation ) const {

	// Find the cross hair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation;
	FVector LookDirection;

	ScreenLocation.X = ViewportSizeX * CrossHairXLocation;
	ScreenLocation.Y = ViewportSizeY * CrossHairYLocation;

	if (GetLookDirection(ScreenLocation, LookDirection)) {

		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return false;
}


/// Obtain the aim direction vector
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	// Deproject the screen position of the cross-hair to a world direction
	FVector CameraWorldLocation; // Not used

	DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation,
		LookDirection
	);

	return true;
}


/// Obtain the hit location which the cross hair is pointing towards to.
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const {

	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager -> GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
	
	){

		//Set hit location
		HitLocation = HitResult.Location;
		return true;
	}

	//When nothing is detected
	HitLocation = FVector(0, 0, 0);
	return false;
}