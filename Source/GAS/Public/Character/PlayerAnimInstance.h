// Copyright Naxts

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class AACTCharacter*ACTCharacter;

	UPROPERTY(BlueprintReadOnly,Category=Movement)
	class UCharacterMovementComponent* PlayerCharacterMovement;

	UPROPERTY(BlueprintReadOnly,Category=Movement)
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly,Category=Movement)
	bool IsFalling;
};
