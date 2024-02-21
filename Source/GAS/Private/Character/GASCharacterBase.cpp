// Copyright Naxts


#include "Character/GASCharacterBase.h"

AGASCharacterBase::AGASCharacterBase()
{
    PrimaryActorTick.bCanEverTick = false;
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");//创建子对象
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));//把Weapon组件附加到Actor的主网格的插槽上
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);//取消碰撞
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh");
	WeaponMesh ->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
}

void AGASCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}
