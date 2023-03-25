#include "Splash.h"
#include "Object.h"

int Object::act_water(Direction fromwhere, Actor fromwho) {
	// TODO
	int res = 0;
	if(fromwho == PLAYER || fromwho == WATER)
	{
		if(fromwhere == NONE ||
		fromwhere == LEFT||
		fromwhere == RIGHT||
		fromwhere == UP||
		fromwhere == DOWN)
		{
			//如果小于3，则只是尺寸+1
			if(size<3)size++;
			else{
				//否则先爆掉
				set2void(this->x,this->y,this->splash);
				res++;
				//如果左边存在
				if(y-1>=0)
					res+=this->splash->map[x][y-1]->act(RIGHT,WATER);
				//如果右边存在
				if(y+1<this->splash->size)
					res+=this->splash->map[x][y+1]->act(LEFT,WATER);
				//如果上边存在
				if(x-1>=0)
					res+=this->splash->map[x-1][y]->act(DOWN,WATER);
				//如果下边存在
				if(x+1<this->splash->size)
					res+=this->splash->map[x+1][y]->act(UP,WATER);
			}
		}
	}
	else if(fromwho == TOXIC)
	{
		if(size>1)size--;
		else{
			set2void(this->x,this->y,this->splash);
		}
	}
	return res;
}

int Object::act_void(Direction fromwhere, Actor fromwho) {
	// TODO
	int res = 0;
	if(fromwho == PLAYER)
	{
		cout<<"Error: Cannot act a Void."<<endl;
	}
	else if(fromwho == TOXIC)
	{
		if(fromwhere == LEFT){
			if(y+1<this->splash->size)
				res+=this->splash->map[x][y+1]->act(LEFT,TOXIC);
		}
		if(fromwhere == UP){
			if(x+1<this->splash->size)
				res+=this->splash->map[x+1][y]->act(UP,TOXIC);
		}
		if(fromwhere == RIGHT){
			if(y-1>=0)
				res+=this->splash->map[x][y-1]->act(RIGHT,TOXIC);
		}
		if(fromwhere == DOWN){
			if(x-1>=0)
				res+=this->splash->map[x-1][y]->act(DOWN,TOXIC);
		}
	}
	else if(fromwho == WATER)
	{
		if(fromwhere == LEFT){
			if(y+1<this->splash->size)
				res+=this->splash->map[x][y+1]->act(LEFT,WATER);
		}
		if(fromwhere == UP){
			if(x+1<this->splash->size)
				res+=this->splash->map[x+1][y]->act(UP,WATER);
		}
		if(fromwhere == RIGHT){
			if(y-1>=0)
				res+=this->splash->map[x][y-1]->act(RIGHT,WATER);
		}
		if(fromwhere == DOWN){
			if(x-1>=0)
				res+=this->splash->map[x-1][y]->act(DOWN,WATER);
		}
	}
	return res;
}

int Object::act_barrier(Direction fromwhere, Actor fromwho) {
	// TODO
	if(fromwho == PLAYER)
	{
		cout<<"Error: Cannot act a Barrier."<<endl;
	}
	return 0;
}

int Object::act_toxic(Direction fromwhere, Actor fromwho) {
	// TODO
	int res = 0;
	if(fromwho == PLAYER || fromwho == TOXIC)
	{
		if(fromwhere == NONE ||
		fromwhere == LEFT||
		fromwhere == RIGHT||
		fromwhere == UP||
		fromwhere == DOWN)
		{
			if(size<3)size++;
			else{
				//否则先爆掉
				set2void(this->x,this->y,this->splash);
				res--;
				//如果左边存在
				if(y-1>=0)
					res+=this->splash->map[x][y-1]->act(RIGHT,TOXIC);
				//如果右边存在
				if(y+1<this->splash->size)
					res+=this->splash->map[x][y+1]->act(LEFT,TOXIC);
				//如果上边存在
				if(x-1>=0)
					res+=this->splash->map[x-1][y]->act(DOWN,TOXIC);
				//如果下边存在
				if(x+1<this->splash->size)
					res+=this->splash->map[x+1][y]->act(UP,TOXIC);
			}
		}
	}
	else if(fromwho == WATER)
	{
		if(size>1)size--;
		else{
			set2void(this->x,this->y,this->splash);
		}
	}
	return res;
}