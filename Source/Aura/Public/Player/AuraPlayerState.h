// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

// Forward declaring Ability System Component and Attributes
class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraPlayerState();

	// Implement interface that allows us to get character's Ability System component
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Implement getter for Attribute set
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	// Give the character a pointer to an Ability System Component
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	// Give the character a pointer to an Attribute Set
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
