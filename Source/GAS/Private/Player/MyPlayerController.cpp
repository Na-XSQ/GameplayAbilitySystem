// Copyright Naxts


#include "Player/MyPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AMyPlayerController::AMyPlayerController()
{
	bReplicates = true;//打开网络同步
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(PlayerContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());//获取当前本地玩家的输入
	check(Subsystem);
	Subsystem->AddMappingContext(PlayerContext,0);

	bShowMouseCursor = true;//显示鼠标光标
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;//设置输入模式
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);//鼠标不会锁定在视口内
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AMyPlayerController::Move);//绑定MoveAction输入动作到Move方法中，当玩家触发时，Move被调用
}

void AMyPlayerController::Move(const FInputActionValue& InputActionValue)//处理玩家移动
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();//获取玩家输入轴向值
	const FRotator Rotation = GetControlRotation();//获取玩家控制器的控制旋转
	const FRotator YawRotation(0.f,Rotation.Yaw,0.f);//创建一个新的旋转器，用于激素按前进和偏移方向

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if(APawn* ControlledPawn = GetPawn<APawn>())//获取当前控制的APawn实例
	{
		ControlledPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);//将前进方向与输入的垂直分量添加到Apawn中
		ControlledPawn->AddMovementInput(RightDirection,InputAxisVector.X);//将侧移方向和输入水平分量添加到APawn中
	}
	
	
}
