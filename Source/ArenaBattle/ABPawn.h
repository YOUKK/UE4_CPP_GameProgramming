// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "ABPawn.generated.h"

UCLASS()
class ARENABATTLE_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 폰의 움직임을 담당하는 충돌 컴포넌트
	UPROPERTY(VisibleAnywhere, Category=Collision)
	UCapsuleComponent* Capsule;

	// 캐릭터 에셋을 보여주고 애니메이션도 담당하는 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = Visual)
	USkeletalMeshComponent* Mesh;

	// 플레이어의 입력에 따라 캐릭터가 움직이도록 설정해주는 컴포넌트
	// 이 무브먼트를 사용하면 중력을 고려하지 않은 간단한 움직임을 구현할 수 있다.
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UFloatingPawnMovement* Movement;

	// 삼인칭 시점으로 카메라 구도를 편리하게 설정할 수 있는 부가 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	// 폰에 카메라 컴포넌트를 부착하면 카메라가 바라보는 게임 세계의 화면을 플레이어의 화면으로 전송한다.
	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
};
