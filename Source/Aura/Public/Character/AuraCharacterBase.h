// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

// Forward declaring Ability System Component and Attributes
class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAuraCharacterBase();

	// Implement interface that allows us to get character's Ability System component
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Implement getter for Attribute set
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Property to hold a reference to the Weapon's skeletal mesh component, editable in the editor.
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	// Give the character a pointer to an Ability System Component
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	// Give the character a pointer to an Attribute Set
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
