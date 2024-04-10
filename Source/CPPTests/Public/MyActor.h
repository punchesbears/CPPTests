// Required header files.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "MyActor.generated.h"

// Define AMyActor class having parent class as AActor.
UCLASS()
class CPPTESTS_API AMyActor : public AActor
{
    // Necessary macro for UE classes
    GENERATED_BODY()

public:
    // Default constructor
    AMyActor();

    // 'Tick' method called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    // 'BeginPlay' method called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    // Skeletal Mesh Component property
    UPROPERTY(EditAnywhere)
    USkeletalMeshComponent * RBToRotate;

    // Position Target property
    UPROPERTY(EditAnywhere)
    UPrimitiveComponent* PositionTarget;

    // Rotation Target property
    UPROPERTY(EditAnywhere)
    UPrimitiveComponent* RotationTarget;

    // Frequency property
    UPROPERTY(EditAnywhere)
    float Frequency = 1.0f;

    // Damping property
    UPROPERTY(EditAnywhere)
    float Damping = 1.0f;

    // Match Position Strength property
    UPROPERTY(EditAnywhere)
    float MatchPositionStrength = 1.0f;

    // Vector to store previous target position
    FVector PreviousTargetPos;

    // PID Controller terms
    float KP;
    float KD;

    // Methods for matching position and rotation
    void MatchPosition();
    void MatchRotation();
};




//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
//#include "MyActor.generated.h"
//
//UCLASS()
//class CPPTESTS_API AMyActor : public AActor
//{
//	GENERATED_BODY()
//	
//public:	
//	// Sets default values for this actor's properties
//	AMyActor();
//
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//};
