// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIUnreal.h"
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
	AEntryAIController();
	virtual void OnPossess(APawn* InPawn) override;
	
	static const FName HomePosKey;
	static const FName PatrolPosKey;

private:

	UPROPERTY()
	class UBehaviorTree* BTAsset;

	UPROPERTY()
	class UBlackboardData* BBAsset;

	//void OnRepeatTimer();

	//FTimerHandle RepeatTimerHandle;
	//float RepeatInterval;

};
