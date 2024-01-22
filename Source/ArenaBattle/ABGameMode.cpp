// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "ABPawn.h"
#include "ABPlayerController.h"

AABGameMode::AABGameMode()
{
	// 언리얼 오브젝트의 클래스 정보는 StaticClass라는 스태틱 함수를 호출해 가져올 수 있다.
	// 주의할 점 : 액터를 생성하고 지정하는 것이 아니라 클래스 정보를 지정한다.
	DefaultPawnClass = AABPawn::StaticClass();
	PlayerControllerClass = AABPlayerController::StaticClass();
	// 블루프린트로 제작된 마네킹 폰을 C++ 게임모드에서 사용하려면 에셋 경로에 _C를 붙여 사용한다.
	static ConstructorHelpers::FClassFinder<APawn> BP_PAWN_C(TEXT("Blueprint'/Game/ThirdPersonBP/Blueprints/ThirdPersonCharacter.ThirdPersonCharacter_C'"));
	if (BP_PAWN_C.Succeeded()) {
		DefaultPawnClass = BP_PAWN_C.Class;
	}
}
