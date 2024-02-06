// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h" // CoreMinimal.h보다 더 많은 기능을 담고 있다

DECLARE_LOG_CATEGORY_EXTERN(ArenaBattle, Log, All); // 로그 카테고리 만들기

// 로그 찍는 매크로 함수들
#define ABLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define ABLOG_S(Verbosity) UE_LOG(ArenaBattle, Verbosity, TEXT("%s"), *ABLOG_CALLINFO)
#define ABLOG(Verbosity, Format, ...) UE_LOG(ArenaBattle, Verbosity, TEXT("%s %S"), *ABLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
#define ABCHECK(Expr, ...) { if(!(Expr)) { ABLOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; } }