// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "PawnTank.h"

void APawnTurret::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void APawnTurret::BeginPlay() {
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckedFireCondition, FireRate, true);
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::CheckedFireCondition() {
	//if Player == null || is Dead Then Bail  
	if (!PlayerPawn) {
		return;
	}
	
	//If player is in range then fire
	if (ReturnDistanceToPlayer() <= FireRange) {
		//Fire
		UE_LOG(LogTemp, Warning, TEXT("Fire Condistion success"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Falied"));
	}
	
}

float APawnTurret::ReturnDistanceToPlayer() {
	if (!PlayerPawn) {
		return 0.0f;
	}
	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}