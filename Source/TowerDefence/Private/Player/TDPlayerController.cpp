// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TDPlayerController.h"
#include "Buildings/TDBaseTower.h"

DEFINE_LOG_CATEGORY(LogTDPlayerController);

ATDPlayerController::ATDPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;

	//DeprojectMousePositionToWorld();

}

void ATDPlayerController::MouseHit()
{
	FHitResult TraceHitResult;
	if (this)
	{
		GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, TraceHitResult);
		UE_LOG(LogTDPlayerController, Warning, TEXT("Controll"))
	}

	FVector SpawnLoc = TraceHitResult.Location;
	FRotator SpawnRot = FRotator(0.f);
	FActorSpawnParameters SpawnParams;


	
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	GetWorld()->SpawnActor<ATDBaseTower>(SpawnLoc, SpawnRot, SpawnParams);
	UE_LOG(LogTDPlayerController, Warning, TEXT("spawn"))
}

