// Fill out your copyright notice in the Description page of Project Settings.


#include "TDGameModeBase.h"
#include "Player/TDPlayerCharacter.h"
#include "Player/TDPlayerController.h"


ATDGameModeBase::ATDGameModeBase()
{
	DefaultPawnClass = ATDPlayerCharacter::StaticClass();
	PlayerControllerClass = ATDPlayerController::StaticClass();
}