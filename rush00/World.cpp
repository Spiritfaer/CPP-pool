#include "World.hpp"
#include "main.hpp"

World::World() : _playerShip(PLAY_WINDOW_H, PLAY_WINDOW_W)
{
	srand(time(NULL));
	for (int i = 0; i < MAX_ENEMY; ++i)
		_enemies[i] = 0;
	for (int i = 0; i < MAX_PLAYER_BALL; ++i)
		_player_ball[i] = 0;
	for (int i = 0; i < MAX_ENEMY_BALL; ++i)
		_enemy_ball[i] = 0;
	for (int i = 0; i < WIND_EVEL; ++i)
		_stars_wind[i] = new Ball((rand() % (PLAY_WINDOW_H - 3)) + 1, (rand() % (PLAY_WINDOW_W - 3)) + 1, '.');
	this->_bottom_win = nullptr;
	this->_game_win = nullptr;
}

World::World(World const & src) { *this = src; }

World &	World::operator=(World const & src)
{
	if (this == &src)
		return *this;
	_playerShip = src._playerShip;

	for (int i = 0; i < MAX_ENEMY; ++i)
	{
		if (src._enemies[i] == nullptr)
			_enemies[i] = nullptr;
		else
			_enemies[i] = new Enemy(*((src._enemies)[i]));
	}
	for (int i = 0; i < MAX_PLAYER_BALL; ++i)
	{
		if (src._player_ball[i] == nullptr)
			_player_ball[i] = nullptr;
		else
			_player_ball[i] = new Ball(*((src._player_ball)[i]));
	}
	for (int i = 0; i < MAX_ENEMY_BALL; ++i)
	{
		if (src._enemy_ball[i] == nullptr)
			_enemy_ball[i] = nullptr;
		else
			_enemy_ball[i] = new Ball(*((src._enemy_ball)[i]));
	}
	for (int i = 0; i < WIND_EVEL; ++i)
	{
		if (src._stars_wind[i] == nullptr)
			_stars_wind[i] = nullptr;
		else
			_stars_wind[i] = new Ball(*((src._stars_wind)[i]));
	}

	return *this;
}

World::~World(){}

void World::init() {
	initscr();
	noecho();
	curs_set(0);
	cbreak();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	refresh();
	signal(SIGWINCH, resizeHandl);
}

void World::initTimer() {
	this->_loop_flag = true;
	this->_time = clock();
	this->_delay = 27000;
	this->_fTime = 0;
}

void World::checkSize(World *world) {
	int terminal_h, terminal_w;
	getmaxyx(stdscr, terminal_h, terminal_w);
	if (terminal_w < PLAY_WINDOW_W || terminal_h < (PLAY_WINDOW_H + INFO_WINDOW_H))
	{
		endwin();
		std::cerr << ERROR_SMALL_TERM << std::endl;
		world->~World();
		exit(1);
	}
	_info_win_pos_h = (terminal_h - (PLAY_WINDOW_H + INFO_WINDOW_H)) / 2;
	_info_win_pos_w = (terminal_w - PLAY_WINDOW_W) / 2;
}

void World::makeWindow() {
	_bottom_win = newwin(INFO_WINDOW_H, INFO_WINDOW_W, _info_win_pos_h, _info_win_pos_w);
	_game_win = newwin(PLAY_WINDOW_H, PLAY_WINDOW_W, _info_win_pos_h + INFO_WINDOW_H, _info_win_pos_w);
}

void World::showBox() {
	box(_bottom_win, 0, 0);
	box(_game_win, 0, 0);
	wrefresh(_bottom_win);
	wrefresh(_game_win);
}

void World::end() {
	wclear(_bottom_win);
	wrefresh(_bottom_win);
	wclear(_game_win);
	wrefresh(_game_win);
	mvwprintw(_game_win, 10, 30, "GAME END");
	mvwprintw(_game_win, 15, 28, "Your score: %d", getPlayerShip()._score);
	mvwprintw(_game_win, 20, 26, "Press 'q' to quit");
	wrefresh(_game_win);
	nodelay(stdscr, false);
	while(true)
		if (getch() == 'q')
			break;

	delwin(_bottom_win);
	delwin(_game_win);
	endwin();
}

void World::showInfo(unsigned fTime) {
	mvwprintw(_bottom_win, 3, 10, "Score: %d", getPlayerShip()._score);
	mvwprintw(_bottom_win, 3, 35, "fTime: %d", fTime);
	mvwprintw(_bottom_win, 3, 60, "HP: %d", getPlayerShip()._hp);
	wrefresh(_bottom_win);
}

void World::showGame() {
	mvBall();
	collisions();
	showAll(_game_win);
	getPlayerShip().draw(_game_win);
	wrefresh(_game_win);
}

void World::animation() {
	if (clock() > _time)
	{
		_time += _delay;
		_fTime++;
		wclear(_game_win);
		box(_game_win, 0, 0);
		if (_fTime % 20 == 0)
			mvStars();
		if (_fTime % 7 == 0) {
			mvEnemies();
			getEnemies();
			enemyFire();
		}
		showGame();
		showInfo(_fTime);
	}
}

void World::resizeHandl(int)
{
	endwin();
	std::cerr << ERROR_RESIZE_TERM << std::endl;
	exit(1);
}

Player &	World::getPlayerShip() { return _playerShip; }
void	World::getEnemies()
{
	for(int i = 0; i < MAX_ENEMY; ++i)
	{
		if (_enemies[i] == 0)
		{
			_enemies[i] = new Enemy((rand() % (PLAY_WINDOW_W - 3)) + 1);
			return ;
		}
	}
}
void	World::setBallPlayer(Ball *ball)
{
	if (!ball)
		return ;
	for (int i = 0; i < MAX_PLAYER_BALL; ++i)
		if (_player_ball[i] == nullptr) {
			_player_ball[i] = ball;
			return ;
		}
}
void	World::setEnemyBall(Ball *ball)
{
	if (!ball)
		return ;
	for (int i = 0; i < MAX_ENEMY_BALL; ++i) {
		if (_enemy_ball[i] == nullptr) {
			_enemy_ball[i] = ball;
			return ;
		}
	}
}

void	World::mvBall()
{
	for(int i = 0; i < MAX_PLAYER_BALL; ++i) {
		if (_player_ball[i] != nullptr && !_player_ball[i]->mvToOneStep(-1, 0)) {
			delete _player_ball[i];
			_player_ball[i] = nullptr;
		}
	}
	for(int i = 0; i < MAX_ENEMY_BALL; ++i) {
		if (_enemy_ball[i] != nullptr && !_enemy_ball[i]->mvToOneStep(1, 0)) {
			delete _enemy_ball[i];
			_enemy_ball[i] = nullptr;
		}
	}
}

void	World::mvEnemies()
{
	for(int i = 0; i < MAX_ENEMY; ++i)
	{
		if (_enemies[i] != 0 && !_enemies[i]->mvToOneStep(1, 0))
		{
			delete _enemies[i];
			_enemies[i] = 0;
		}
	}
}

void	World::mvStars()
{
	for(int i = 0; i < WIND_EVEL; ++i)
		if (!_stars_wind[i]->mvToOneStep(1, 0))
			_stars_wind[i]->mvTo(1, _stars_wind[i]->getPos()._x);
}

void	World::enemyFire()
{
	for (int i = 0; i < MAX_ENEMY; ++i) {
		if ((rand() % 100) == 0 && _enemies[i])
			setEnemyBall(_enemies[i]->attack());
	}
}

void	World::collisions()
{
	for (int i = 0; i < MAX_PLAYER_BALL; ++i)
	{
		if (_player_ball[i] != 0)
		{
			for(int j = 0; j < MAX_ENEMY; ++j)
			{
				if (_enemies[j] != 0)
				{
					Vec2D tmp(_player_ball[i]->getPos());
					tmp--;
					if (_player_ball[i]->getPos() == _enemies[j]->getPos()
						|| tmp == _enemies[j]->getPos())
					{
						delete _player_ball[i];
						delete _enemies[j];
						_player_ball[i] = 0;
						_enemies[j] = 0;
						_playerShip.upScore();
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i < MAX_ENEMY; ++i)	{
		if (_enemies[i] != nullptr) {
			Vec2D tmp(_enemies[i]->getPos());
			tmp++;
			if (_enemies[i]->getPos() == _playerShip.getPos()
					|| tmp == _playerShip.getPos()) {
				delete _enemies[i];
				_enemies[i] = nullptr;
				_playerShip.damageHP();
				flash();
				break;
			}
		}
	}
	for(int i = 0; i < MAX_ENEMY_BALL; ++i)	{
		if (_enemy_ball[i] != nullptr) {
			Vec2D tmp(_enemy_ball[i]->getPos());
			tmp++;
			if (_playerShip.getPos() == _enemy_ball[i]->getPos()
				|| _playerShip.getPos() == tmp) {
				delete _enemy_ball[i];
				_enemy_ball[i] = nullptr;
				beep();
				flash();
				_playerShip.damageHP();
				break;
			}
		}
	}
}

void	World::showAll(WINDOW *win)
{
	for (int i = 0; i < WIND_EVEL; ++i)
		_stars_wind[i]->draw(win);
	for(int i = 0; i < MAX_PLAYER_BALL; ++i)
		if (_player_ball[i] != nullptr)
			_player_ball[i]->draw(win);
	for(int i = 0; i < MAX_ENEMY_BALL; ++i)
		if (_enemy_ball[i] != nullptr)
			_enemy_ball[i]->draw(win);
	for(int i = 0; i < MAX_ENEMY; ++i)
		if (_enemies[i] != nullptr)
			_enemies[i]->draw(win);
}

void World::play() {
	while(_loop_flag && getPlayerShip()._hp)
	{
		switch (getch())
		{
			case KEY_UP:	getPlayerShip().mvToOneStep(-1, 0);			break;
			case 'w':		getPlayerShip().mvToOneStep(-1, 0);			break;
			case KEY_DOWN:	getPlayerShip().mvToOneStep(1, 0);			break;
			case 's':		getPlayerShip().mvToOneStep(1, 0);			break;
			case KEY_LEFT:	getPlayerShip().mvToOneStep(0, -1);			break;
			case 'a':		getPlayerShip().mvToOneStep(0, -1);			break;
			case KEY_RIGHT:	getPlayerShip().mvToOneStep(0, 1);			break;
			case 'd':		getPlayerShip().mvToOneStep(0, 1);			break;
			case ' ':		setBallPlayer(getPlayerShip().attack());	break;
			case 'q':		_loop_flag = false;							break;
		}
		animation();
	}
}
