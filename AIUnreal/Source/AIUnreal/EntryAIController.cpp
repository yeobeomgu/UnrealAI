// Fill out your copyright notice in the Description page of Project Settings.


#include "EntryAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AEntryAIController::HomePosKey(TEXT("HomePos"));
const FName AEntryAIController::PatrolPosKey(TEXT("PatrolPos"));

AEntryAIController::AEntryAIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Script/AIModule.BlackboardData'/Game/AI/BB_ABCharacter.BB_ABCharacter'"));
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree>BTObject(TEXT("/Script/AIModule.BehaviorTree'/Game/AI/BT_ABCharacter.BT_ABCharacter'"));
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object;
	}

}

void AEntryAIController::OnPossess(APawn* InPawn)
{
	Super::Possess(InPawn);

	//UE4���� UBlackboardComponent*Blackboard;
	//UE5���� TObjectPtr<UBlackboardComponent>Blackboard; �� �����.
	//�ذ� ������� BlakcboardComp�� ���� ����.
	UBlackboardComponent* BlackboardComp = Blackboard.Get();
	if (UseBlackboard(BBAsset, BlackboardComp))
	{
		//������ Ű ������ ����
		// 
	
		//UBlackboardComponent::SetValueAsVector(HomePosKey, InPawn->GetActorLocation());

		if (!RunBehaviorTree(BTAsset))
		{
			
		}
	}
}


