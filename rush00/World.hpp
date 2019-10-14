#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdlib>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Ball.hpp"

#define MAX_ENEMY 75
#define MAX_PLAYER_BALL 75
#define MAX_ENEMY_BALL 75
#define WIND_EVEL 25


class World
{
public:
	World();
	World(World const &);
	World &operator=(World const &);
	~World();

	void	init();
	void	initTimer();
	void	end();
	void	checkSize(World *world);
	void	makeWindow();

	Player	&getPlayerShip();
	void	getEnemies();
	void	setBallPlayer(Ball *ball);
	void	setEnemyBall(Ball *ball);

	void	mvEnemies();
	void	mvBall();
	void	mvStars();

	void	enemyFire();
	void	collisions();
	void	showBox();
	void	showInfo(unsigned fTime);
	void	showGame();
	void	showAll(WINDOW *);
	void	animation();
	void	play();

	static void	resizeHandl(int);
	int		_info_win_pos_h;
	int 	_info_win_pos_w;

	WINDOW	*_bottom_win;
	WINDOW	*_game_win;

	bool	_loop_flag;
	clock_t	_time;
	clock_t	_delay;
	unsigned _fTime;

private:
	Player 	_playerShip;
	Enemy	*_enemies[MAX_ENEMY];
	Ball	*_player_ball[MAX_PLAYER_BALL];
	Ball	*_enemy_ball[MAX_ENEMY_BALL];
	Ball	*_stars_wind[WIND_EVEL];

};

#endif
