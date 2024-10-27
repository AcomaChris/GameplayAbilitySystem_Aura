// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"


#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	// Create the Ability System Component and set replication to true
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	// Create the attribute set component
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	// How often we attempt to keep server/client in sync on PlayerState
	// Bumping this because the default value on PlayerStates is usually low
	NetUpdateFrequency = 100.f;
}

// Interface to get the character's AbilitySystemComponent
UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
