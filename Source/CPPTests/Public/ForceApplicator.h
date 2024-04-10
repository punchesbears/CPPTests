// // ForceApplicator.h
// #pragma once
//
// #include "CoreMinimal.h"
// #include "GameFramework/Actor.h"
// #include "ForceApplicator.generated.h"
//
// UCLASS()
// class CPPTESTS_API AForceApplicator : public AActor
// {
//     GENERATED_BODY()
//     
// public:    
//     // Sets default values for this actor's properties
//     AForceApplicator();
//
// protected:
//     // Called when the game starts or when spawned
//     virtual void BeginPlay() override;
//
// public:    
//     // Called every frame
//     virtual void Tick(float DeltaTime) override;
//
//     UFUNCTION(BlueprintCallable, Category = "Physics")
//     void ApplyForceToRagdollPelvis(APhysicsConstraintComponent* Pelvis, FVector Force);
// };

// ForceApplicator.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ForceApplicator.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPPTESTS_API UForceApplicator : public UActorComponent
{
    GENERATED_BODY()

public:    
    UForceApplicator();

protected:
    virtual void BeginPlay() override;

public:    
    UFUNCTION(BlueprintCallable, Category = "PB")
    static void ApplyForceToPelvis(bool MatchPosition, bool MatchRotation, UPrimitiveComponent* Bone, FTransform Target, FVector Force);
};


