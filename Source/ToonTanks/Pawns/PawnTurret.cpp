// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GamePlayStatics.h"

void APawnTurret::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void APawnTurret::BeginPlay() {
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckedFireCondition, FireRate, true);
}

void APawnTurret::CheckedFireCondition() {
	UE_LOG(LogTemp, Warning, TEXT("Fire Condistion Checked"));
}