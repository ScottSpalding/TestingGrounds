// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGroundsCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

#include "Weapons/Gun.h"

// Sets default values
ATestingGroundsCharacter::ATestingGroundsCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a CameraComponent	
	TGCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	TGCameraComponent->SetupAttachment(GetCapsuleComponent());
	TGCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	TGCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(TGCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	Mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

	UE_LOG(LogTemp, Warning, TEXT("Here6."));
	if (InputComponent != NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Binding component."));
		InputComponent->BindAction("Fire", IE_Pressed, this, &ATestingGroundsCharacter::PullTrigger);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found null input component and I am controlled by: %s"), GetController());
	}
	UE_LOG(LogTemp, Warning, TEXT("Here7."));
}

void ATestingGroundsCharacter::PullTrigger()
{
	UE_LOG(LogTemp, Warning, TEXT("Firing."));
	Gun->OnFire();
}

// Called when the game starts or when spawned
void ATestingGroundsCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (GunBlueprint == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Gun blueprint missing."));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Here3."));
	Gun = GetWorld()->SpawnActor<AGun>(GunBlueprint);
	Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	Gun->AnimInstance = Mesh1P->GetAnimInstance();
	UE_LOG(LogTemp, Warning, TEXT("Here4."));
}

// Called every frame
void ATestingGroundsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestingGroundsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("Here1."));
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UE_LOG(LogTemp, Warning, TEXT("Here2."));
}

