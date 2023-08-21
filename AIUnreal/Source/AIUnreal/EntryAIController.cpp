// Fill out your copyright notice in the Description page of Project Settings.


#include "EntryAIController.h"
#include "AI.h"

AEntryAIController::AEntryAIController(FObjectInitializer const& ObjectInitializer)
{
}

void AEntryAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (AAI* const ai = Cast<AAI>(InPawn))
	{
		if (UBehaviorTree* const tree = ai->GetBehaviorTree())
		{
			UBlackboardComponent* b;
			UseBlackboard(tree->BlackboardAsset, b);
			Blackboard = b;
			RunBehaviorTree(tree);
		}
	}

}
