// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDBaseTower.generated.h"

class UStaticMeshComponent;

UCLASS()
class TOWERDEFENCE_API ATDBaseTower : public AActor
{
	GENERATED_BODY()
	
public:	
	ATDBaseTower();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* MeshComponent;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	
};
