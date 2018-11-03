// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//assigns InputHandle
	void FindInputComponentAndBindActions();

	void FindPhysicsComponent();

	//Raycast and grab objects in reach.
	void Grab();

	// called when grab key is released.
	void Release();

	FVector GetPlayerGrabReach() const;

	FHitResult GetFirstPhysicsBodyInReach() const;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// provides initial value to LineTraceEnd and PlayerViewPoint, called in the constructor.
	void FindPlayerGrabbingReach();

private:
	float Reach = 100.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	
	UInputComponent* InputHandle = nullptr;

	FVector PlayerViewpointLocation;

	FRotator PlyerViewpointRotation;

	FVector LineTraceEnd;
};
