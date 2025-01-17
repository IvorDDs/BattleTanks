// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetPlayerTank();

	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank: %s"), *ControlledTank->GetName());
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Player not found"));
	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
