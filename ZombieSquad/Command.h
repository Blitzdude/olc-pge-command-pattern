#pragma once

#include "Actor.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(Actor& actor, float dt) = 0;
};

class MoveForward : public Command
{
public:
	MoveForward() {};

	virtual void execute(Actor& actor, float dt) override
	{
		actor.MoveForward(dt);
	}
};

class MoveBack : public Command
{
public:
	MoveBack() {};

	virtual void execute(Actor& actor, float dt) override
	{
		actor.MoveBack(dt);
	}
};

class TurnRight : public Command
{
public:
	TurnRight() {};

	virtual void execute(Actor& actor, float dt) override
	{
		actor.TurnRight(dt);
	}
};

class TurnLeft : public Command
{
public:
	TurnLeft() {};

	virtual void execute(Actor& actor, float dt) override
	{
		actor.TurnLeft(dt);
	}
};

class ChangePlayer : public Command
{
public:
	ChangePlayer() {};

	virtual void execute(Actor& actor, float dt) override
	{
		actor.ChangePlayer();
	}

};

class Attack : public Command
{
public: 
	Attack() {};

	virtual void execute(Actor& actor, float dt) override
	{
		actor.Attack(dt);
	}
};

class ChasePlayer : public Command
{
public: 
	ChasePlayer(const Player* player) 
		: m_player(player)
	{};

	virtual void execute(Actor& actor, float dt) override
	{
		actor.Chase(*m_player);
	}
private:
	const Player* m_player;
};

class Die : public Command
{
public:
	Die() {};
	// TODO: FInish applying dying
	virtual void execute(Actor& actor, float dt) override
	{
		actor.Die(dt);
	}
};