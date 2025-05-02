#include "enemy.h"

int setEnemies(int level, int wave, Invaders* e1)
{
	int alpha = 0, beta = 0, gamma = 0;
	if (level == 1)
	{
		if (wave == 1)
		{
			e1[0].setInvaders("img/enemy_1.png", 100, 1);
			e1[1].setInvaders("img/enemy_1.png", 200, 1);
			e1[2].setInvaders("img/enemy_1.png", 300, 1);
			e1[3].setInvaders("img/enemy_1.png", 400, 1);
			e1[4].setInvaders("img/enemy_1.png", 500, 1);
			e1[5].setInvaders("img/enemy_1.png", 600, 1);
			e1[6].setInvaders("img/enemy_1.png", 100, 100);
			e1[7].setInvaders("img/enemy_1.png", 600, 100);
			e1[8].setInvaders("img/enemy_1.png", 100, 200);
			e1[9].setInvaders("img/enemy_1.png", 200, 200);
			e1[10].setInvaders("img/enemy_1.png", 300, 200);
			e1[11].setInvaders("img/enemy_1.png", 400, 200);
			e1[12].setInvaders("img/enemy_1.png", 500, 200);
			e1[13].setInvaders("img/enemy_1.png", 600, 200);
			alpha = 14;
			return alpha;
		}
		else if (wave == 2)
		{
			e1[0].setInvaders("img/enemy_2.png", 350, 1);
			e1[1].setInvaders("img/enemy_2.png", 250, 100);
			e1[2].setInvaders("img/enemy_2.png", 450, 100);
			e1[3].setInvaders("img/enemy_2.png", 150, 200);
			e1[4].setInvaders("img/enemy_2.png", 250, 200);
			e1[5].setInvaders("img/enemy_2.png", 350, 200);
			e1[6].setInvaders("img/enemy_2.png", 450, 200);
			e1[7].setInvaders("img/enemy_2.png", 550, 200);
			beta = 8;
			return beta;
		}
		else
		{
			e1[0].setInvaders("img/enemy_3.png", 200, 1);
			e1[1].setInvaders("img/enemy_3.png", 600, 1);
			e1[2].setInvaders("img/enemy_3.png", 300, 100);
			e1[3].setInvaders("img/enemy_3.png", 500, 100);
			e1[4].setInvaders("img/enemy_3.png", 400, 200);
			e1[5].setInvaders("img/enemy_3.png", 300, 300);
			e1[6].setInvaders("img/enemy_3.png", 500, 300);
			e1[7].setInvaders("img/enemy_3.png", 200, 400);
			e1[8].setInvaders("img/enemy_3.png", 600, 400);
			gamma = 9;
			return gamma;
		}
	}
	else if (level == 2)
	{
		if (wave == 1)
		{
			e1[0].setInvaders("img/enemy_1.png", 300, 1);
			e1[1].setInvaders("img/enemy_1.png", 400, 1);
			e1[2].setInvaders("img/enemy_1.png", 200, 100);
			e1[3].setInvaders("img/enemy_1.png", 500, 100);
			e1[4].setInvaders("img/enemy_1.png", 200, 200);
			e1[5].setInvaders("img/enemy_1.png", 500, 200);
			e1[6].setInvaders("img/enemy_1.png", 300, 300);
			e1[7].setInvaders("img/enemy_1.png", 400, 300);
			alpha = 8;
			return alpha;

		}
		else if (wave == 2)
		{
			e1[0].setInvaders("img/enemy_2.png", 350, 1);
			e1[1].setInvaders("img/enemy_2.png", 250, 100);
			e1[2].setInvaders("img/enemy_2.png", 450, 100);
			e1[3].setInvaders("img/enemy_2.png", 150, 200);
			e1[4].setInvaders("img/enemy_2.png", 550, 200);
			e1[5].setInvaders("img/enemy_2.png", 250, 300);
			e1[6].setInvaders("img/enemy_2.png", 450, 300);
			e1[7].setInvaders("img/enemy_2.png", 350, 400);
			beta = 8;
			return beta;
		}
		else
		{
			e1[0].setInvaders("img/enemy_3.png", 250, 1);
			e1[1].setInvaders("img/enemy_3.png", 450, 1);
			e1[2].setInvaders("img/enemy_3.png", 150, 100);
			e1[3].setInvaders("img/enemy_3.png", 350, 100);
			e1[4].setInvaders("img/enemy_3.png", 550, 100);
			e1[5].setInvaders("img/enemy_3.png", 250, 200);
			e1[6].setInvaders("img/enemy_3.png", 450, 200);
			e1[7].setInvaders("img/enemy_3.png", 350, 300);
			gamma = 8;
			return gamma;
		}
	}
	else
	{
		if (wave == 1)
		{
			e1[0].setInvaders("img/enemy_1.png", 300, 1);
			e1[1].setInvaders("img/enemy_1.png", 400, 1);
			e1[2].setInvaders("img/enemy_1.png", 200, 100);
			e1[3].setInvaders("img/enemy_1.png", 300, 100);
			e1[4].setInvaders("img/enemy_1.png", 400, 100);
			e1[5].setInvaders("img/enemy_1.png", 500, 100);
			e1[6].setInvaders("img/enemy_1.png", 200, 200);
			e1[7].setInvaders("img/enemy_1.png", 300, 200);
			e1[8].setInvaders("img/enemy_1.png", 400, 200);
			e1[9].setInvaders("img/enemy_1.png", 500, 200);
			e1[10].setInvaders("img/enemy_1.png", 300, 300);
			e1[11].setInvaders("img/enemy_1.png", 400, 300);
			alpha = 12;
			return alpha;
		}
		else if (wave == 2)
		{
			e1[0].setInvaders("img/enemy_2.png", 350, 1);
			e1[1].setInvaders("img/enemy_2.png", 250, 100);
			e1[2].setInvaders("img/enemy_2.png", 350, 100);
			e1[3].setInvaders("img/enemy_2.png", 450, 100);
			e1[4].setInvaders("img/enemy_2.png", 150, 200);
			e1[5].setInvaders("img/enemy_2.png", 250, 200);
			e1[6].setInvaders("img/enemy_2.png", 350, 200);
			e1[7].setInvaders("img/enemy_2.png", 450, 200);
			e1[8].setInvaders("img/enemy_2.png", 550, 200);
			e1[9].setInvaders("img/enemy_2.png", 250, 300);
			e1[10].setInvaders("img/enemy_2.png", 350, 300);
			e1[11].setInvaders("img/enemy_2.png", 450, 300);
			e1[12].setInvaders("img/enemy_2.png", 350, 400);
			beta = 13;
			return beta;
		}
		else
		{

			e1[0].setInvaders("img/enemy_3.png", 100, 1);
			e1[1].setInvaders("img/enemy_3.png", 200, 1);
			e1[2].setInvaders("img/enemy_3.png", 300, 1);
			e1[3].setInvaders("img/enemy_3.png", 400, 1);
			e1[4].setInvaders("img/enemy_3.png", 500, 1);
			e1[5].setInvaders("img/enemy_3.png", 600, 1);
			e1[6].setInvaders("img/enemy_3.png", 100, 100);
			e1[7].setInvaders("img/enemy_3.png", 200, 100);
			e1[8].setInvaders("img/enemy_3.png", 300, 100);
			e1[9].setInvaders("img/enemy_3.png", 400, 100);
			e1[10].setInvaders("img/enemy_3.png", 500, 100);
			e1[11].setInvaders("img/enemy_3.png", 600, 100);
			e1[12].setInvaders("img/enemy_3.png", 100, 200);
			e1[13].setInvaders("img/enemy_3.png", 200, 200);
			e1[14].setInvaders("img/enemy_3.png", 300, 200);
			e1[15].setInvaders("img/enemy_3.png", 400, 200);
			e1[16].setInvaders("img/enemy_3.png", 500, 200);
			e1[17].setInvaders("img/enemy_3.png", 600, 200);
			gamma = 18;
			return gamma;
		}
	}

}
// 4 5 11 14 19 22 (for hollow circle)
// 4 5 11 12 13 14 19 20 21 22 (for filled circle)


//5 12 14 19 23 (for hollow diamond)
//5 12 13 14 19 20 21 22 23 24(for filled diamond)


// 4 6 13 11 15 20 22 (for hollow heart)
// 4 6 11 12 13 14 15 20 21 22 (for filled heart)

