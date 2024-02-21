// Copyright Naxts

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GASCharacterBase.generated.h"

UCLASS(Abstract)//阻止这个类被拖入关卡
class GAS_API AGASCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:

	AGASCharacterBase();

protected:

	virtual void BeginPlay() override;
	
UPROPERTY(EditAnywhere,Category="Combat")
TObjectPtr<USkeletalMeshComponent>Weapon;//用指针获武器的骨骼网格组件

	UPROPERTY(EditAnywhere,Category="Mesh")
	TObjectPtr<UStaticMeshComponent>WeaponMesh;//用指针获武器的骨骼网格组件
};
