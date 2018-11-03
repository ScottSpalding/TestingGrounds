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
	AInfiniteTerrainGameMode();

	UFUNCTION(Blueprintcallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool* NavMeshBoundsVolumePool;

private:

	UFUNCTION(Blueprintcallable, Category = "")
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);

};
