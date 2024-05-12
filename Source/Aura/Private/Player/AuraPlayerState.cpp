// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

AAuraPlayerState::AAuraPlayerState()
{
	// How often we attempt to keep server/client in sync on PlayerState
	// Bumping this because the default value on PlayerStates is usually low
	NetUpdateFrequency = 100.f;
}
