// Copyright Naxts


#include "Character/PlayerAnimInstance.h"

#include "Character/ACTCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	ACTCharacter = Cast<AACTCharacter>(TryGetPawnOwner());
	if(ACTCharacter)
	{
		PlayerCharacterMovement = ACTCharacter->GetCharacterMovement();
	}
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if(PlayerCharacterMovement)
	{
	 GroundSpeed=UKismetMathLibrary::VSizeXY(PlayerCharacterMovement->Velocity);
		IsFalling = PlayerCharacterMovement->IsFalling();
	}
}
