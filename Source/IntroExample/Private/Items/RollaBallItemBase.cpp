// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/RollaBallItemBase.h"
#include "RollaBallPlayer.h"
#include "RollaBallGameModeBase.h"
ARollaBallItemBase::ARollaBallItemBase()
{
 	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ARollaBallItemBase::OverlapBegin);


}

void ARollaBallItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARollaBallItemBase::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ARollaBallPlayer>(OtherActor) != nullptr) 
	{
		Collected();
	}
}

void ARollaBallItemBase::Collected_Implementation()
{
	ARollaBallGameModeBase* GameMode = Cast<ARollaBallGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode) 
	{
		GameMode->ItemCollected();
	}
}


