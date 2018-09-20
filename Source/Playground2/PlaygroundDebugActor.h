// Weichao Qiu @ 2018
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlaygroundDebugActor.generated.h"

UCLASS()
class PLAYGROUND2_API APlaygroundDebugActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlaygroundDebugActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CaptureFrame();
	
	
};
