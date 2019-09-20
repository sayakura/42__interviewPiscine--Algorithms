#include "header.h"
const double red_win = 0.4864864;
const double green_win = 0.02702;

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
    if (firstDollarsBet >= dollarsWanted)
		return 1;
	if (nbGame == 0)
		return 0;
	double prob = probabilityWin(firstDollarsBet * 2, dollarsWanted, nbGame - 1) * red_win;
	prob += probabilityWin(firstDollarsBet / 2, dollarsWanted, nbGame - 1) * green_win;
	return (prob);
}