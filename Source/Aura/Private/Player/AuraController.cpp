// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraController.h"
#include "../../../Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputSubsystems.h"
#include "../../../Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h"


AAuraController::AAuraController()
{
	bReplicates = true;
}

void AAuraController::BeginPlay()
{
	Super::BeginPlay();

	// Assert if AuraContext isn't set within Blueprints
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Cast from the default input system to the enhanced input system.
	// Note, as it's CastChecked the game will crash if it fails.
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	// Bind our MoveInput action to the enhanced input
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraController::Move);
}

void AAuraController::Move(const FInputActionValue& InputActionValue)
{
	// Get the input axis vector and store it from the InputActionValue
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	// Get the current rotation of the controller to remove from the WASD calcuation so we can get a forward vector
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	// Calculate the forward direction and right direction
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// Get the pawn controlled by the Aura controller, check the controller has the pawn set up via if statement
	if (APawn* ControlledPawn = GetPawn <APawn>())
	{
		// Apply the forward and right direction based on the input
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
