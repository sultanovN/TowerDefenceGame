// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TDPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Player/TDPlayerController.h"

DEFINE_LOG_CATEGORY(LogTDPlayerCharacter);


ATDPlayerCharacter::ATDPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->SetWorldLocationAndRotation(FVector{0, 0, 4000}, FRotator{-90, 0, 0});

}

void ATDPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	TDPlayerController = Cast<ATDPlayerController>(Controller);

}

void ATDPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATDPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(LeftClickAction, ETriggerEvent::Started, this, &ATDPlayerCharacter::LeftClick);
		EnhancedInputComponent->BindAction(RightClickAction, ETriggerEvent::Started, this, &ATDPlayerCharacter::RightClick);
	}
	else
	{
		UE_LOG(LogTDPlayerCharacter, Warning, TEXT("Failed to find Enhanced Input Component!!!"));
	}
}

void ATDPlayerCharacter::LeftClick()
{
	UE_LOG(LogTDPlayerCharacter, Warning, TEXT("Left Click!"));

	TDPlayerController->MouseHit();
}

void ATDPlayerCharacter::RightClick()
{
	UE_LOG(LogTDPlayerCharacter, Warning, TEXT("Right Click!"));

}

