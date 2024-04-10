// MyActor.cpp

#include "MyActor.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    if (PositionTarget)
    {
        PreviousTargetPos = PositionTarget->GetComponentLocation();
    }

    KP = (6.0f * Frequency) * (6.0f * Frequency) * 0.25f;
    KD = 4.5f * Frequency * Damping;
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    MatchPosition();
    MatchRotation();
}

void AMyActor::MatchPosition()
{
    if (!RBToRotate || !PositionTarget)
        return;

    float dt = GetWorld()->DeltaTimeSeconds;
    FVector targetCurrentVelocity = (PositionTarget->GetComponentLocation() - PreviousTargetPos) / dt;
    PreviousTargetPos = PositionTarget->GetComponentLocation();

    float g = 1 / (1 + KD * dt + KP * dt * dt);
    float ksg = KP * g;
    float kdg = (KD + KP * dt) * g;

    FVector force = (PositionTarget->GetComponentLocation() - RBToRotate->GetComponentLocation()) * ksg + (targetCurrentVelocity - RBToRotate->GetPhysicsLinearVelocity()) * kdg;
    force *= MatchPositionStrength;

    RBToRotate->AddForce(force, NAME_None, true);
}

void AMyActor::MatchRotation()
{
    if (!RBToRotate || !RotationTarget)
        return;

    FQuat targetRotation = RotationTarget->GetComponentQuat();
    FQuat currentRotation = RBToRotate->GetComponentQuat();

    FQuat q = targetRotation * currentRotation.Inverse();
    if (q.W < 0)
    {
        q.X = -q.X;
        q.Y = -q.Y;
        q.Z = -q.Z;
        q.W = -q.W;
    }

    FVector axis;
    float angle;
    q.ToAxisAndAngle(axis, angle);
    axis.Normalize();

    FVector pidv = KP * axis * angle - KD * RBToRotate->GetPhysicsAngularVelocityInRadians();
    FVector inertiaTensor = RBToRotate->GetInertiaTensor();
    FQuat rotInertiaToWorld = RBToRotate->GetComponentQuat() * RBToRotate->GetBodyInstance()->GetUnrealWorldTransform().GetRotation();

    pidv = rotInertiaToWorld.Inverse().RotateVector(pidv * inertiaTensor);
    pidv = rotInertiaToWorld.RotateVector(pidv);

    RBToRotate->AddTorqueInRadians(pidv, NAME_None, true);
}






//// Fill out your copyright notice in the Description page of Project Settings.
//
//
//#include "MyActor.h"
//
//// Sets default values
//AMyActor::AMyActor()
//{
// 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//}
//
//// Called when the game starts or when spawned
//void AMyActor::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
//
//// Called every frame
//void AMyActor::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

