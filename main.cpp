#include <iostream>
#include "MiniFW_Modified.h"
#include "Robots_Modified.h"
#include "randgen.h"

void iMhigh (Robot & muro, int & a);
void voltacýreyis(Robot & ege, Robot & emre, Robot & ock, Robot & huso);
void koselereYerlestir (Robot & muro, int & a);
int yasarMý (Robot & muro, int & a);

void comon (Robot & muro, int & a) //this function allows my player robot to move.
{
	if (muro.isAlive())
	{
		if(IsPressed(keyDownArrow))
		{
			muro.TurnFace(south);
			muro.Move(1);
			if((muro.GetXCoordinate() != 0 && muro.GetYCoordinate() != 0 ) || (muro.GetXCoordinate() != 12 && muro.GetYCoordinate() != 0 ))//this if allows me not to collect things in corners.
			muro.PickAllThings();
		}
		if(IsPressed(keyUpArrow))
		{
			muro.TurnFace(north);
			muro.Move(1);
			if((muro.GetXCoordinate() != 0 && muro.GetYCoordinate() != 12 ) || (muro.GetXCoordinate() != 12 && muro.GetYCoordinate() != 12 ))//this if allows me not to collect things in corners.
			muro.PickAllThings();
		}
		if(IsPressed(keyRightArrow))
		{
			muro.TurnFace(east);
			muro.Move(1);
			if((muro.GetXCoordinate() != 12 && muro.GetYCoordinate() != 0 ) || (muro.GetXCoordinate() != 12 && muro.GetYCoordinate() != 12 ))//this if allows me not to collect things in corners.
			muro.PickAllThings();
		}
		if(IsPressed(keyLeftArrow))
		{
			muro.TurnFace(west);
			muro.Move(1);
			if((muro.GetXCoordinate() != 0 && muro.GetYCoordinate() != 12 ) || (muro.GetXCoordinate() != 0 && muro.GetYCoordinate() != 0 ))//this if allows me not to collect things in corners.
			muro.PickAllThings();
		}
	}
	else if (!muro.isAlive())//i called the life function to check if player is alive and to check how many lives he has left.
	{
		yasarMý(muro, a);
	}

}

void iMhigh (Robot & muro, int & a)//this function is for the super mode.
{
	if(muro.isAlive())
	{
	if(muro.GetBagCount() >= 30)//super mode begins when the player has more than 30 things on his bag.
	{
		if(IsPressed(keyDownArrow) && muro.GetYCoordinate() > 0 )
			{
				muro.Teleport(muro.GetXCoordinate(), muro.GetYCoordinate()-1, south);
				muro.PickAllThings();
			}
		else if( IsPressed(keyUpArrow) && muro.GetYCoordinate() < 12)
			{
				muro.Teleport(muro.GetXCoordinate(),muro.GetYCoordinate()+1,north);
				muro.PickAllThings();
			}
		else if( IsPressed(keyRightArrow) && muro.GetXCoordinate() < 12) 
			{
				muro.Teleport(muro.GetXCoordinate()+1,muro.GetYCoordinate(),east);
				muro.PickAllThings();
			}
		else if( IsPressed(keyLeftArrow) && muro.GetXCoordinate() > 0)
			{
				muro.Teleport(muro.GetXCoordinate()-1,muro.GetYCoordinate(),west);
				muro.PickAllThings();
			}
	}
	}
	else if (muro.isAlive()==0)
	{
	yasarMý(muro, a);
	}
}

void koselereYerlestir (Robot & muro, int & a)//this function is to drop things on the corners.
{
	if(muro.isAlive())
	{
		if(GetCellCount(0,12) + muro.GetBagCount() <= 10)
		{
			if(muro.GetXCoordinate() == 0 && muro.GetYCoordinate() == 12)
			{
				for (int i = 0; i <= muro.GetBagCount() ; i++)
				{
					muro.PutThing();
				}
		
			}
		}
			if(GetCellCount(0,0) + muro.GetBagCount() <= 10)
		{
			if(muro.GetXCoordinate() == 0 && muro.GetYCoordinate() == 0)
			{
				for (int i = 0; i <= muro.GetBagCount() ; i++)
				{
					muro.PutThing();
				}
		
			}
		}	if(GetCellCount(12,12) + muro.GetBagCount() <= 10)
		{
			if(muro.GetXCoordinate() == 12 && muro.GetYCoordinate() == 12)
			{
				for (int i = 0; i <= muro.GetBagCount() ; i++)
				{
					muro.PutThing();
				}
		
			}
		}	if(GetCellCount(12,0) + muro.GetBagCount() <= 10)
		{
			if(muro.GetXCoordinate() == 12 && muro.GetYCoordinate() == 0)
			{
				for (int i = 0; i <= muro.GetBagCount() ; i++)
				{
					muro.PutThing();
				}
		
			}
		}
		if(GetCellCount(0,12) + muro.GetBagCount() > 10)
		{
			if( muro.GetXCoordinate() == 0 && muro.GetYCoordinate() == 12)
			{
				for (int i = 0; i < 10 - GetCellCount(0,12) ; i++)
				{
					muro.PutThing();
				}
		
			}
		}


		if(GetCellCount(12,12) + muro.GetBagCount() > 10)
		{
			if( muro.GetXCoordinate() == 12 && muro.GetYCoordinate() == 12)
			{
				for (int i = 0; i < 10 - GetCellCount(12,12) ; i++)
				{
					muro.PutThing();
				}
		
			}
		}


		if(GetCellCount(0,0) + muro.GetBagCount() > 10)
		{
			if( muro.GetXCoordinate() == 0 && muro.GetYCoordinate() == 0)
			{
				for (int i = 0; i < 10 - GetCellCount(0,0) ; i++)
				{
					muro.PutThing();
				}
		
			}
		}


		if(GetCellCount(12,0) + muro.GetBagCount() > 10)
		{
			if( muro.GetXCoordinate() == 12 && muro.GetYCoordinate() == 0)
			{
				for (int i = 0; i < 10 - GetCellCount(12,0) ; i++)
				{
					muro.PutThing();
				}
		
			}
		}

}
	else if(!muro.isAlive())
	{
		yasarMý(muro, a);
	}
}




void voltacýreyis(Robot & ege, Robot & emre, Robot & ock, Robot & huso)//monsters do random walk by this function
{
	RandGen volta;
	int voltta = volta.RandInt(1,4);//random integers taken here to move the monsters randomly.
	
	if(voltta == 1)
	{
		ege.TurnRandom();
		ege.Move();
		ege.Resurrect();
		ege.TurnRandom();
	}
	else if(voltta == 2)
	{
		emre.TurnRandom();
		emre.Move();
		emre.Resurrect();
		emre.TurnRandom();
	}
	else if(voltta == 3)
	{
		ock.TurnRandom();
		ock.Move();
		ock.Resurrect();
		ock.TurnRandom();
	}
	else if(voltta == 4)
	{
		huso.TurnRandom();
		huso.Move();
		huso.Resurrect();
		huso.TurnRandom();
	}
}

int yasarMý (Robot & muro, int & a)//this function checks the number of lives of the player robot.
{ 
	if (!muro.isAlive())
	{
		muro.Resurrect();
		a++;
		if(a==2)
			ShowMessage("You have 2 lives left!");
		else if(a==3)
			ShowMessage("You have only 1 live left!");

	}
	return a;
}

bool ASTROWORLD ()//this function is the winning condition of the game.
{
	if(GetCellCount(0,0) == 10 &&  GetCellCount(0,12) == 10 && GetCellCount(12,0) == 10 && GetCellCount(12,12) == 10)
	{
		ShowMessage("Congratulations, you win!");
		return true;
	}
	else
	return false;
}

int main()
{
	
	RandGen xCo, yCo, thngs, puttedcells ;//i created these random integers in order to have random things in random cells.
	int  cellcounts = puttedcells.RandInt(40, 169) ;

	
	for ( int k = 0 ; k <= cellcounts ; k++)//this loop puts random things inside 40 to  169 cells.
	{
		int xCor = xCo.RandInt(0,12);
		int yCor = yCo.RandInt(0,12);
		int things = thngs.RandInt(0,4);

		if(!GetCellCount(xCor, yCor))
		{
		PutThingsOnCell(xCor, yCor, things);
		}
	}


	Robot muro(6,6);//this is my player robot.
	muro.SetColor(yellow);

	Robot ege(6,2);//this is my monster robot
	ege.SetColor(red);

	Robot ock(2,6);//this is my monster robot
	ock.SetColor(red);

	Robot emre(6,10);//this is my monster robot
	emre.SetColor(red);

	Robot huso(10,6);//this is my monster robot
	huso.SetColor(red);

	int a = 1;
	
	for (a = 1 ;  a < 4 ; yasarMý(muro, a))//this is my main loop.all the functions written here.
	{

		voltacýreyis(ege, emre, ock, huso);
		iMhigh (muro, a);
		comon (muro, a);
		koselereYerlestir(muro, a);
		if(ASTROWORLD() == true)
			return 0;

	}
	if(a==4)//this situation means the game is over.
	{
		ShowMessage("You have no lives left");
		ShowMessage("You just lost The Game!");
		return 0;
	}
	return 0;
}