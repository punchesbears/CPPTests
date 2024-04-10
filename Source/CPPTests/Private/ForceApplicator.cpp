// // ForceApplicator.cpp
// #include "ForceApplicator.h"
//
// // Sets default values
// AForceApplicator::AForceApplicator()
// {
//     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//     PrimaryActorTick.bCanEverTick = true;
// } 
//
// // Called when the game starts or when spawned
// void AForceApplicator::BeginPlay()
// {
//     Super::BeginPlay();
// }
//
// // Called every frame
// void AForceApplicator::Tick(float DeltaTime)
// {
//     Super::Tick(DeltaTime);
// }
//
// void AForceApplicator::ApplyForceToRagdollPelvis(APhysicsConstraintComponent* Pelvis, FVector Force)
// {
//     if(Pelvis && Pelvis->GetBodyInstance())
//     {
//         Pelvis->GetBodyInstance()->AddForce(Force);
//     }
// }


// ForceApplicator.cpp

#include "ForceApplicator.h"

UForceApplicator::UForceApplicator()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UForceApplicator::BeginPlay()
{
    Super::BeginPlay();
}

void UForceApplicator::ApplyForceToPelvis(bool MatchPosition, bool MatchRotation, UPrimitiveComponent* Pelvis, FTransform Target, FVector Force)
{
    if (Pelvis)
    {
        Pelvis->AddForce(Force);
    }
}
