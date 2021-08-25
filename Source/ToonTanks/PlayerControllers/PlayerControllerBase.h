#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"


UCLASS()
class TOONTANKS_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	// Enable or disable player input
	void SetPlayerEnableState(bool SetPlayerEnabled);
};
