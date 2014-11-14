// Fill out your copyright notice in the Description page of Project Settings.

#include "Platformer.h"
#include "PaperEnemy.h"
#include "PaperPlatformerCharacter.h"


APaperEnemy::APaperEnemy(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
    // set initial health
    Health = MaxHealth = 1000.0f;
}

void APaperEnemy::ReceiveDamage(float val)
{
    // can be made more complicated than this
    // for example, we could reduce the damage by some some defense rating
    Health -= val;
    
    if (Health <= 0)
    {
        GEngine->AddOnScreenDebugMessage(2, 5.0f, FColor::Red, TEXT("Enemy defeated!!"));
        Destroy();
    }
}

void APaperEnemy::ReceiveHit(class UPrimitiveComponent *MyComp, AActor *Other, class UPrimitiveComponent *OtherComp,
                bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult &Hit)
{
    Super::ReceiveHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
    Cast<APaperPlatformerCharacter>(Other)->OnEnemyCollide(20.0f);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("HIT"));
}