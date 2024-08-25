// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TDPlayerCharacter.generated.h"

class UCameraComponent;
struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
class ATDPlayerController;

DECLARE_LOG_CATEGORY_EXTERN(LogTDPlayerCharacter, Log, All);

UCLASS()
class TOWERDEFENCE_API ATDPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATDPlayerCharacter();

protected:
	virtual void BeginPlay() override;

	ATDPlayerController* TDPlayerController;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LeftClickAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* RightClickAction;

	//void Move(const FInputActionValue& Value);

	void LeftClick();

	void RightClick();
};
