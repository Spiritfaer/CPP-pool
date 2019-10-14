#include "Pony.hpp"

void	ponyOnTheHeap()
{
	Pony *heapPony = new Pony("Fucker");
	heapPony->getPain();
	delete heapPony;
}

void	ponyOnTheStack()
{
	Pony stackPony("Fucker");
	stackPony.getPain();
}

int		main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();

	return 0;
}
