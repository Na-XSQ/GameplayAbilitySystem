// Copyright Naxts


#include "Character/ACTCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AACTCharacter::AACTCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll =false;
	bUseControllerRotationYaw = false;

GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f);
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom ->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);
	
	WeaponMesh1 = CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh1");
	WeaponMesh1 ->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	WeaponMesh1->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	WeaponMesh2 = CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh2");
	WeaponMesh2 ->SetupAttachment(GetMesh(),FName("hand_lSocket"));
	WeaponMesh2->SetCollisionEnabled(ECollisionEnabled::NoCollision);	
}


void AACTCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AACTCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AACTCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"),this,&AACTCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"),this,&AACTCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("Turn"),this,&AACTCharacter::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"),this,&AACTCharacter::LookUp);

	PlayerInputComponent->BindAction(FName("Jump"),IE_Pressed,this,&ACharacter::Jump);//回调函数绑定到跳跃动作映射
}

void AACTCharacter::MoveForward(float Value)
{
	if(Controller&&(Value!=0.f))
	{
		//find out which way is forward自由视角
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f,ControlRotation.Yaw,0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction,Value);
	}
}

void AACTCharacter::MoveRight(float Value)
{
	if(Controller&&(Value!=0.f))
	{
	//find out which way is Right
	const FRotator ControlRotation = GetControlRotation();
	const FRotator YawRotation(0.f,ControlRotation.Yaw,0.f);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction,Value);
	}
}

void AACTCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AACTCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}
