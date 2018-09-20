// Weichao Qiu @ 2018
#include "PlaygroundDebugActor.h"
#include "Runtime/Engine/Classes/Components/MaterialBillboardComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
APlaygroundDebugActor::APlaygroundDebugActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UMaterialBillboardComponent* Billboard = CreateDefaultSubobject<UMaterialBillboardComponent>(TEXT("BillboardComponent"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Engine/EditorMaterials/HelpActorMaterial"));
	Billboard->AddElement(MaterialAsset.Object, nullptr, false, 32.0f, 32.0f, nullptr);
	// Billboard->SetupAttachment(RootComponent);
	Billboard->bIsEditorOnly = true;
	Billboard->bHiddenInGame = true;
	
	RootComponent = Billboard;
}

// Called when the game starts or when spawned
void APlaygroundDebugActor::BeginPlay()
{
	Super::BeginPlay();
	
	CaptureFrame();
}

void APlaygroundDebugActor::CaptureFrame()
{
	TArray<FString> TestCommands = {
		"vget /camera/0/lit playground_cam0_lit.png",
		"vget /camera/0/object_mask playground_cam0_seg.png",
		"vget /camera/0/depth playground_cam0_depth.npy",
		"vget /camera/1/lit playground_cam1_lit.png",
		"vget /camera/1/object_mask playground_cam1_seg.png",
		"vget /camera/1/depth playground_cam1_depth.npy",
	};
	APlayerController* PController= UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if( PController )
	{
		for (FString Cmd : TestCommands)
		{
			PController->ConsoleCommand(*Cmd, true);
		}
	}
	// FConsoleOutputDevice OutputDevice(GetWorld()->GetGameViewport()->ViewportConsole);
	// GetWorld()->Exec(GetWorld(), TEXT("vget /camera/0/lit playground_lit.png"), OutputDevice);
	UE_LOG(LogTemp, Display, TEXT("Save image and ground truth to the disk"));
}

// Called every frame
void APlaygroundDebugActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CaptureFrame();
}

