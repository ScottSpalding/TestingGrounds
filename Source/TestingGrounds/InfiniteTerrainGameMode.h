// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingGroundsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API AInfiniteTerrainGameMode : public ATestingGroundsGameMode
{
	GENERATED_BODY()
public:

UFUNCTION(Blueprintcallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

UFUNCTION(Blueprintcallable, Category = "Bounds Pool")
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);

};
