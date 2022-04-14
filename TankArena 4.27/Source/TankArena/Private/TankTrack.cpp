// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{

	//Clamp Throttle input to -1 ~ +1
	float ClampedThrottle = FMath::Clamp<float>(Throttle, -1.5, +1.5);
	
	// Apply the force to move the possessed Tank.
	auto ForceApplied = GetForwardVector() * ClampedThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner() -> GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}
