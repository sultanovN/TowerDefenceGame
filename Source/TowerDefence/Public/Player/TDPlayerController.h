// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TDPlayerController.generated.h"

/**
 * 
 */


DECLARE_LOG_CATEGORY_EXTERN(LogTDPlayerController, Log, All);

UCLASS()
class TOWERDEFENCE_API ATDPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	ATDPlayerController();


public:
	void MouseHit();
};
