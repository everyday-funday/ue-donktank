// 2020 Copyright JGames Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 Tank Movement Component provides fly-by-wire user control to move the tank.
 Takes left-axis controller input and moves the player pawn.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKARENA_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankTrack* RightTrackToSet, UTankTrack* LeftTrackToSet);


	// Movement controls - Used in Tank Blueprint
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendRotateRight(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendRotateLeft(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveBackward(float Throw);

	//TODO: Check best protection

private:
	// Called from the pathfinding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UTankTrack* RightTrack = nullptr;
	UTankTrack* LeftTrack = nullptr;	
	
};
