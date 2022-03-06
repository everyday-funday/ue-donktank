// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{

	//auto Time = GetWorld()->GetTimeSeconds();
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%f: %s Throttle: %f"), Time, *Name, ClampedThrottle);

	//Clamp Throttle input to -1 ~ +1
	float ClampedThrottle = FMath::Clamp<float>(Throttle, -1, +1);
	
	// Apply the force to move the possessed Tank.
	auto ForceApplied = GetForwardVector() * ClampedThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner() -> GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}
