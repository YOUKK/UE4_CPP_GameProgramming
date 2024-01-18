// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h" // CoreMinimal.h보다 더 많은 기능을 담고 있다
#include "GameFramework/Actor.h"
#include "Fountain.generated.h" // 클래스이름.generated.h는 가장 아래에 있어야 한다.

UCLASS()
class ARENABATTLE_API AFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 디테일 패널에서 볼 수 있지만 다른 데이터로 변경할 수는 없다
	// ex) 값 유형의 경우 0을 10으로 바꿀 수 없다 / 객체 유형의 경우 UStaticMeshComponent를 UPointLightComponent로 바꿀 수 없다
	UPROPERTY(VisibleAnywhere) 
	UStaticMeshComponent *Body; // 포인터로 선언했으므로 메모리를 동적으로 할당해준다

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *Water;

	UPROPERTY(VisibleAnywhere)
	UPointLightComponent *Light;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent *Splash;

	UPROPERTY(EditAnywhere, Category=ID) // 디테일 패널에서 볼 수 있고 편집도 가능하다
	int32 ID;
};
