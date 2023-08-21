// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindPatrolPos.h"
#include "NavigationSystem.h"
#include "EntryAIController.h"

UBTTask_FindPatrolPos::UBTTask_FindPatrolPos(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Find Random Location In NavMesh";
}

EBTNodeResult::Type UBTTask_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// get AI controller and its ai
	if (AEntryAIController* const cont = Cast<AEntryAIController>(OwnerComp.GetAIOwner()))
	{
		if (auto* const ai = cont->GetPawn())
		{
			// obtain ai location to use as an origin
			auto const Origin = ai->GetActorLocation();

			// get the navigation system and generate a random location
			if (auto* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				FNavLocation Loc;
				if (NavSys->GetRandomPointInNavigableRadius(Origin, SearchRadius, Loc))
				{
					//OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Loc.Location);
				}

				//finish with success
				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}

		}

	}

	return EBTNodeResult::Failed;
}
