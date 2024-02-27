// Copyright Naxts

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ACTCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GAS_API AACTCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AACTCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	virtual void BeginPlay() override;
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);


	UPROPERTY(EditAnywhere,Category="Combat")
	TObjectPtr<USkeletalMeshComponent>Weapon;//用指针获武器的骨骼网格组件

	UPROPERTY(EditAnywhere,Category="Mesh")
	TObjectPtr<UStaticMeshComponent>WeaponMesh1;//用指针获武器的骨骼网格组件

	UPROPERTY(EditAnywhere,Category="Mesh")
	TObjectPtr<UStaticMeshComponent>WeaponMesh2;
private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent*CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent*ViewCamera;
	


};