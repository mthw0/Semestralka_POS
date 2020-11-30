#pragma once

class Plocha
{
private:
	char **plocha;
	int velkostRiadka, velkostStlpca;

public:
	Plocha(char**, int, int);
	int getVelkostStlpca();
	int getVelkostRiadka();
	char getColor(int, int);
	void changeColor(int, int);
	bool isWall(int, int);
};

