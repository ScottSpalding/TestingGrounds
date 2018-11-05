// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorPool.h"


// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

AActor * UActorPool::Checkout()
{
	UE_LOG(LogTemp, Warning, TEXT("[%s] Checkout"), *GetName());
	if (Pool.Num() > 0) 
	{
		return Pool.Pop();
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("Pool was empty!"));
		return nullptr;
	}
	
}

void UActorPool::Return(AActor * ActorToReturn)
{
	if (ActorToReturn == nullptr) 
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Returned null actor!"), *GetName());
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor returned: {%s}."), *GetName(), *ActorToReturn->GetName());
	Add(ActorToReturn);
}

void UActorPool::Add(AActor * ActorToAdd)
{
	if (ActorToAdd == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Added null actor!"), *GetName());
		return;
	}
	Pool.Push(ActorToAdd);
}
