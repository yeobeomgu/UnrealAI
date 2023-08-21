// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "EntryAIController.generated.h"

/**
 * 
 */
UCLASS()
class AIUNREAL_API AEntryAIController : public AAIController
{
	GENERATED_BODY()

public:
	explicit AEntryAIController(FObjectInitializer const& ObjectInitializer);

protected:
	virtual void OnPossess(APawn* InPawn) override;

};
