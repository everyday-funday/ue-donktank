// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 Tank Track is a static mesh component that is use to set maximum driving force, 
 and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:

	//Sets the throttle input between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);


	// Max force, per track, in Newtons.
	UPROPERTY(EditDefaultsOnly, Category = TankMovement)
	float TrackMaxDrivingForce = 5000000; // 5ton mass * 1G acceleration


private:

	
};
