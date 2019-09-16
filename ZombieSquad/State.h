#pragma once
#include "Command.h"
enum class StateID
{
	ZOMBIE_ROAM,	   // Zombie states
	ZOMBIE_CHASE,
	ZOMBIE_NAVIGATING,
	PLAYER_CONTROLLED, // Player states
	PLAYER_OVERWATCH,
	STATE_DEAD,		   // All Actors 
	STATE_NONE
};

class Player;
class Zombie;
class Bullet;

class PlayerState
{
public:
	// Abstract class to give a common update Functionality for Actors
	PlayerState() {}
	virtual ~PlayerState() {}

	virtual void Update(Player& player, float dt) = 0;

	virtual const StateID& GetStateID() = 0;
};


class ZombieState
{
public:
	// Abstract class to give a common update Functionality for Actors
	ZombieState() {}
	virtual ~ZombieState() {};

	virtual void Update(Zombie& zombie, float dt) = 0;

	virtual const StateID& GetStateID() = 0;
};


class BulletState
{
public:
	// Abstract class to give a common update Functionality for Actors
	BulletState() {}
	virtual ~BulletState() {};

	virtual void Update(Bullet& bullet, float dt) = 0;

	virtual const StateID& GetStateID() = 0;
};

// PLAYER STATES
/////////////////
class Controlled : public PlayerState
{
public:
	Controlled()
		: m_id(StateID::PLAYER_CONTROLLED)
	{}
	virtual ~Controlled() {};

	virtual void Enter(Player& player) {};
	virtual void Update(Player&, float dt) override;
	// virtual void Exit(Player& player) {}; // Not Implemented

	const StateID& GetStateID() override { return m_id; }
private:
	StateID m_id;
};

class Watching : public PlayerState
{
public:
	Watching()
		: m_id(StateID::PLAYER_OVERWATCH)
	{}
	virtual ~Watching() {};

	virtual void Enter(Player& player) {};
	virtual void Update(Player& player, float dt) override;
	// virtual void Exit(Player& player) {}; // Not Implemented

	const StateID& GetStateID() override { return m_id; }
private:
	Vec2f m_direction;
	StateID m_id;
};

class PlayerDead : public PlayerState
{
public:
	PlayerDead()
		: m_id(StateID::STATE_DEAD)
	{
		m_deathTime = 0.0f;
	}

	virtual void Enter(Player& player) {};	// Not implemented
	virtual void Update(Player& player, float dt) override;
	// virtual void Exit(Zombie& player) {}; // Not Implemented

	const StateID& GetStateID() override { return m_id; }
private:
	StateID m_id;
	float m_deathTime;
};

// ZOMBIE STATES
/////////////////
class Chasing : public ZombieState
{
public:
	Chasing(const Player& player)
		: m_id(StateID::ZOMBIE_CHASE), m_chaseTarget(&player)
	{}

	virtual ~Chasing() { m_chaseTarget = nullptr; };

	virtual void Enter(Zombie& zombie) {};	// Not implemented
	virtual void Update(Zombie& zombie, float dt) override;
	// virtual void Exit(Zombie& player) {}; // Not Implemented

	const StateID& GetStateID() override { return m_id; }
private:
	StateID m_id;
	const Player* m_chaseTarget;
};

class Roaming : public ZombieState
{
public:
	Roaming()
		: m_id(StateID::ZOMBIE_ROAM), m_timer(0.0f)
	{}

	virtual ~Roaming() {};

	virtual void Enter(Zombie& zombie) {};	// Not implemented
	virtual void Update(Zombie& zombie, float dt) override;
	// virtual void Exit(Zombie& player) {}; // Not Implemented

	const StateID& GetStateID() override { return m_id; }
private:
	StateID m_id;
	float m_timer;

};


class ZombieDead : public ZombieState
{
public:
	ZombieDead()
		: m_id(StateID::STATE_DEAD) 
	{
		m_deathTime = 0.0f;
	}

	virtual void Enter(Zombie& zombie) {};	// Not implemented
	virtual void Update(Zombie& zombie, float dt) override;
	// virtual void Exit(Zombie& player) {}; // Not Implemented

	const StateID& GetStateID() override { return m_id; }
private:
	StateID m_id;
	float m_deathTime;
};


class Flying : public BulletState
{
public:
	Flying()
		: m_id(StateID::STATE_NONE)
	{}

	virtual ~Flying() {};

	virtual void Enter(Bullet& bullet) {};
	virtual void Update(Bullet& bullet, float dt) override;
	// virtual void Exit(Player& player) {}; // Not implemented

	const StateID& GetStateID() override { return m_id; }
private:
	StateID m_id;

};

