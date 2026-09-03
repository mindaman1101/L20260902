#pragma once

class AActor;

class FRenderer
{
public:
	FRenderer();

	virtual ~FRenderer();

	const void Render(const AActor* DrawActor);
};