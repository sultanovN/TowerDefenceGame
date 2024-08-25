// Fill out your copyright notice in the Description page of Project Settings.


#include "Buildings/TDBaseTower.h"
#include "Components/StaticMeshComponent.h"

ATDBaseTower::ATDBaseTower()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
}

void ATDBaseTower::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATDBaseTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

