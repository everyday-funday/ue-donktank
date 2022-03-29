// 2020 Copyright JGames Ltd.

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "GameFramework/NavMovementComponent.h"


void UTankMovementComponent::Initialize(UTankTrack* RightTrackToSet, UTankTrack* LeftTrackToSet) 
{
	//Set Tank Turret Reference
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	if (LeftTrack && RightTrack) { 
		UE_LOG(LogTemp, Warning, TEXT("Tracks Set"));

		return; 
	};
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; };
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; };
	LeftTrack	->	SetThrottle(Throw);
	RightTrack	->	SetThrottle(Throw);

}

void UTankMovementComponent::IntendRotateRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; };
	LeftTrack	->	SetThrottle(Throw);
	RightTrack	->	SetThrottle(-Throw);
}

void UTankMovementComponent::IntendRotateLeft(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; };
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super:: as we are replacing the functionality.
	//auto TankName = GetOwner()->GetName();
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForward);
	IntendMoveForward(ForwardThrow);

	auto TurnThrow = FVector::CrossProduct(AIForwardIntention, TankForward);
	IntendRotateRight(TurnThrow.Z);
}
