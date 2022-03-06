// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankAIController.h"
#include "Tank.h"

#include "Engine/World.h"
#include "TankArena.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//All enemy AI Tanks aim towards the player
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank) {

		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO: Check radius is in cm

		ControlledTank->AimAt(PlayerTank-> GetActorLocation());
		//ControlledTank->Fire(); //TODO: Limit Firing rate
	}
}