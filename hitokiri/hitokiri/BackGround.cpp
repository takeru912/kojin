#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
}

void BackGround::update()
{

}

void BackGround::draw()const
{
	bg.resized(Scene::Size()).draw();
	pg.resized(Scene::Size()).draw();
}
