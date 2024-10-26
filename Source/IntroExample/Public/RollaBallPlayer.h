// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "RollaBallPlayer.generated.h"


UCLASS()
class INTROEXAMPLE_API ARollaBallPlayer : public APawn
{
	GENERATED_BODY()

public:
	ARollaBallPlayer();
protected:
	virtual void BeginPlay() override;

	// Definte Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* Camera;

	// VARIABLES //
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveForce = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JumpImpulse = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxJumpCount = 1;

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	// FUNCTIONS //
	void MoveRight(float Value);
	void MoveForward(float Value);
	void Jump();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent,
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		FVector NormalImpulse, 
		const FHitResult& Hit);


	int32 JumpCount = 0;

};
