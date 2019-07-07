
#include"head.h"

sprite *billsprite1[25] = { NULL };
sprite *goodmushsprite[1] = { NULL };
sprite *coinsprite1[25] = { NULL };
sprite *coinsprite2[25] = { NULL };

rect rectmario, rectbad_snake, rectbad_mush, rectgood_mush[3], rectbill[50], rectbad_missile, rectgreen_turtle, rectbad_mask, rectcoin1[25], rectcoin2[25];

//window
const int winWidth = 700, winHeight = 260;
//win
ACL_Image win_img;
char *win = "win.bmp";
//lose
ACL_Image lose_img;
char *lose = "lose.bmp";
//start
ACL_Image start_img;
char *start = "start.bmp";
//restart
ACL_Image restart_img;
char *restart = "restart.bmp";
//mario
ACL_Image mario_img;
char *mario = "mario.bmp";
int mario_width = 30, mario_height = 30, mario_x = 10, mario_y = 200;
//bad_missile
ACL_Image bad_missile_img;
char *bad_missile = "bad_missile.bmp";
int dx_bad_missile = 30;
int bad_missile_width = 60, bad_missile_height = 30, bad_missile_x = 930, bad_missile_y = 80;
int id_bad_missile = 0, timeinterval = 50;
int timecounter = 0;
//bad_mask
char *bad_mask = "bad_mask.bmp";
ACL_Image bad_mask_img;
int bad_mask_width = 50, bad_mask_height = 40, bad_mask_x = 0, bad_mask_y = 120;
int dx_bad_mask = 15;
int id_bad_mask = 1;
//wall
ACL_Image wall_2_img;
char *wall_2 = "wall_2.bmp";
const int wall_2_width = 1000, wall_2_height = 40, wall_2_x = 0, wall_2_y = 260;
//background1
ACL_Image background_1_img;
char *background_1 = "background_1.jpg";
int background_1_width = 1000, background_1_height = 260, background_1_x = 0, background_1_y = 0;
//background2
ACL_Image background_2_img;
char *background_2 = "background_2.jpg";
int background_2_width = 1000, background_2_height = 260, background_2_x = 0, background_2_y = 0;
//bill
ACL_Image bill_img;
char *bill = "bill.bmp";
int bill_width = 20, bill_height = 20;
int numbill = 0;//bill的计数器
int dx_bill = 2;
int dy_bill = 2;
int bill_x, bill_y;
const int maxbill = 25;
const int id_bill = 2;
const int createtimerinterval1 = 1500;
int createid1 = 3;
//coin1
ACL_Image coin1_img;
char *coin1 = "coin.bmp";
int coin1_width = 20, coin1_height = 20;
int numcoin1 = 0;//coin的计数器
int dx_coin1 = 0;
int dy_coin1 = 3;
int coin1_x, coin1_y;
const int maxcoin1 = 25;
const int id_coin1 = 7;
const int createtimerinterval2 = 2000;
int createid2 = 8;
//coin2
ACL_Image coin2_img;
char *coin2 = "coin2.bmp";
int coin2_width = 20, coin2_height = 20;
int numcoin2 = 0;//coin的计数器
int dx_coin2 = 3;
int dy_coin2 = 1;
int coin2_x, coin2_y;
const int maxcoin2 = 25;
const int id_coin2 = 9;
const int createtimerinterval3 = 3000;
int createid3 = 10;
//greenturtle
ACL_Image bad_green_turtle_img;
char *bad_green_turtle = "bad_green_turtle.bmp";
int id_bad_green_turtle = 4;
int bad_green_turtle_x = 200, bad_green_turtle_y = 190, bad_green_turtle_width = 40, bad_green_turtle_height = 40;
int dx_bad_green_turtle = 3;
//goodmush
ACL_Image good_mush_img;
char *good_mush = "good_mush.bmp";
int id_good_mush1 = 5;
int id_good_mush2 = 6;
int longtime = 20000;
int numgoodmush = 0, maxgoodmush = 0;
//greenpole
ACL_Image greenpole_img;
char *greenpole = "greenpole.bmp";
int greenpole_x = 600, greenpole_y = 160, greenpole_width = 40, greenpole_height = 100;
//bad_snake
ACL_Image bad_snake_img;
char *bad_snake = "bad_snake.bmp";
int bad_snake_x = 600, bad_snake_y = 0, bad_snake_width = 40, bad_snake_height = 100;
int dy_bad_snake = 2;
int id_bad_snake = 11;
//bad_mush
ACL_Image bad_mush_img;
char *bad_mush = "bad_mush.bmp";
int bad_mush_x = 0, bad_mush_y = 0, bad_mush_width = 50, bad_mush_height = 50;
int dy_bad_mush = 3, dx_bad_mush = 3;
int id_bad_mush = 12;
//
int score = 0, heart = 10;
//music
ACL_Sound easy_mp3;
char *easy = "easy.mp3";
ACL_Sound hard_mp3;
char *hard = "hard.mp3";

int Setup()
{
	int x, y;
	initConsole();
	printf("Please type in the number：1.Start   2.Past score   3.Log out\n\n");
	scanf_s("%d",&x);
	printf_s("\n");
	if (x == 1)
	{
		printf("Please type in the number：1.Sign in   2.Log in\n\n");
		scanf_s("%d", &y);
		printf_s("\n");
		if (y == 1)
		{
			registers();
			Login();
		}
		else if (y == 2) {
			Login();
		}
	}
	else if (x == 2)
	{
		printf("                    Past score\n");
		scoreSort();
		_getch();
	}
	else 
		printf("Please type in the correct number!");

	srand((unsigned)time(NULL));//令随机数与时间无关
	initWindow("super_mario", DEFAULT, DEFAULT, winWidth, winHeight);
	imageLoading();

	loadSound(easy = "sound/easy.mp3", &easy_mp3);
	loadSound(hard = "sound/hard.mp3", &hard_mp3);

	playSound(easy_mp3, 0);
	
	//goodmush
	{goodmushsprite[numgoodmush] = (sprite*)malloc(sizeof(sprite));
	goodmushsprite[numgoodmush]->width = 30;
	goodmushsprite[numgoodmush]->height = 30;
	goodmushsprite[numgoodmush]->x = rand() % (400);
	goodmushsprite[numgoodmush]->y = 200;
	goodmushsprite[numgoodmush]->dx = 8; }
	//bill
	{billsprite1[numbill] = (sprite*)malloc(sizeof(sprite));
	billsprite1[numbill]->width = 20;
	billsprite1[numbill]->height = 20;
	billsprite1[numbill]->x = rand() % (winWidth - billsprite1[numbill]->width);
	billsprite1[numbill]->y = rand() % (winHeight - wall_2_height - billsprite1[numbill]->height);
	billsprite1[numbill]->dx = 2;
	billsprite1[numbill]->dy = 2; }
	//coin1
	{coinsprite1[numcoin1] = (sprite*)malloc(sizeof(sprite));
	coinsprite1[numcoin1]->width = 20;
	coinsprite1[numcoin1]->height = 20;
	coinsprite1[numcoin1]->x = rand() % (winWidth - billsprite1[numcoin1]->width);
	coinsprite1[numcoin1]->y = rand() % (winHeight - wall_2_height - billsprite1[numcoin1]->height);
	coinsprite1[numcoin1]->dx = 0;
	coinsprite1[numcoin1]->dy = 3; }
	//coin2
	{coinsprite2[numcoin2] = (sprite*)malloc(sizeof(sprite));
	coinsprite2[numcoin2]->width = 20;
	coinsprite2[numcoin2]->height = 20;
	coinsprite2[numcoin2]->x = rand() % (winWidth - billsprite1[numcoin2]->width);
	coinsprite2[numcoin2]->y = rand() % (winHeight - wall_2_height - billsprite1[numcoin2]->height);
	coinsprite2[numcoin2]->dx = 3;
	coinsprite2[numcoin2]->dy = 1; }
	//
	registerMouseEvent(mouseEvent);
	//开始界面
	beginPaint();
	putImageScale(&background_2_img, background_2_x, background_2_y, background_2_width, background_2_height);
	putImageTransparent(&start_img, 275, 100, 150, 60, BLACK);
	endPaint();
	registerKeyboardEvent(keyEvent);
	registerTimerEvent(timerEvent);
	return 0;
}
int imageLoading()
{
	loadImage(start = "image/start.bmp",&start_img);
	loadImage(restart = "image/restart.bmp", &restart_img);
	loadImage(win = "image/win.bmp", &win_img);
	loadImage(lose = "image/lose.bmp", &lose_img);
	loadImage(mario = "image/mario.bmp", &mario_img);
	loadImage(bad_missile = "image/bad missile.bmp", &bad_missile_img);
	loadImage(bad_mask = "image/bad mask.bmp", &bad_mask_img);
	loadImage(wall_2 = "image/wall 2.bmp", &wall_2_img);
	loadImage(background_1 = "image/background 1.jpg", &background_1_img);
	loadImage(background_2 = "image/background 2.jpg", &background_2_img);
	loadImage(bill = "image/bill.bmp", &bill_img);
	loadImage(coin1 = "image/coin.bmp", &coin1_img);
	loadImage(coin2 = "image/coin2.bmp", &coin2_img);
	loadImage(bad_green_turtle = "image/bad green turtle.bmp", &bad_green_turtle_img);
	//loadImage(good_mush = "image/good mush.bmp", &good_mush_img);
	loadImage(greenpole = "image/greenpole.bmp", &greenpole_img);
	loadImage(bad_snake = "image/bad snake.bmp", &bad_snake_img);
	loadImage(bad_mush = "image/bad mush.bmp", &bad_mush_img);
	return 0;
}
int paint()//每次需要更新位置的时候就调用
{
	beginPaint();
	clearDevice();
	if (score <= 60)
	{
		setTextBkColor(RGB(74, 93, 232));
		setTextColor(WHITE);
		putImageScale(&background_1_img, background_1_x, background_1_y, background_1_width, background_1_height);
	}
	if (score > 60)
	{
		setTextBkColor(RGB(83, 53, 117));
		setTextColor(WHITE);
		putImageScale(&background_2_img, background_2_x, background_2_y, background_2_width, background_2_height);
	}
	putImageTransparent(&mario_img, mario_x, mario_y, mario_width, mario_height, BLACK);
	putImageTransparent(&wall_2_img, wall_2_x, wall_2_y, wall_2_width, wall_2_height, WHITE);
	putImageTransparent(&bad_green_turtle_img, bad_green_turtle_x, bad_green_turtle_y, bad_green_turtle_width, bad_green_turtle_height, WHITE);
	putImageTransparent(&greenpole_img, greenpole_x, greenpole_y, greenpole_width, greenpole_height, BLACK);
	putImageTransparent(&bad_missile_img, bad_missile_x, bad_missile_y, bad_missile_width, bad_missile_height, WHITE);
	
	if (score >= 30)
		putImageTransparent(&bad_mask_img, bad_mask_x, bad_mask_y, bad_mask_width, bad_mask_height, WHITE);
	if (score >= 100)
	{
		putImageTransparent(&bad_snake_img, bad_snake_x, bad_snake_y, bad_snake_width, bad_snake_height, BLACK);
		putImageTransparent(&bad_mush_img, bad_mush_x, bad_mush_y, bad_mush_width, bad_mush_height, BLACK);
	}
	for (int j = 0; j <= numbill; j++)
	{
		if (billsprite1[j])
			putImageTransparent(&bill_img, billsprite1[j]->x, billsprite1[j]->y, billsprite1[j]->width, billsprite1[j]->height, WHITE);
	}//把所有bill绘制出来
	for (int j = 0; j <= numcoin1; j++)
	{
		if (coinsprite1[j])
			putImageTransparent(&coin1_img, coinsprite1[j]->x, coinsprite1[j]->y, coinsprite1[j]->width, coinsprite1[j]->height, WHITE);
	}//把所有coin1绘制出来
	for (int j = 0; j <= numcoin2; j++)
	{
		if (coinsprite2[j])
			putImageTransparent(&coin2_img, coinsprite2[j]->x, coinsprite2[j]->y, coinsprite2[j]->width, coinsprite2[j]->height, BLACK);
	}//把所有coin2绘制出来
	
	for (int j = 0; j <=0; j++)
	{
		if (goodmushsprite[j])
			//putImageScale(&good_mush2_img, goodmushsprite[j]->x, goodmushsprite[j]->y, goodmushsprite[j]->width, goodmushsprite[j]->height);
			putImageTransparent(&good_mush_img, goodmushsprite[j]->x, goodmushsprite[j]->y, goodmushsprite[j]->width, goodmushsprite[j]->height, WHITE);
	}
	char str1[100];
	char str2[20];
	char str3[20];
	char str4[20];
	char str5[20];
	//char str6[40];
	char str7[20];
	//char str8[40];
	char str9[20];
	sprintf_s(str9, 19, "heart:%d", heart);
	setTextSize(30);
	paintText(10, 40, str9);
	sprintf_s(str1, 19, "score:%d", score);
	setTextSize(30);
	paintText(10, 10, str1);

	if (score > -50 && score < 30)
	{
		sprintf_s(str2, 19, "level 1!");
		setTextSize(30);
		paintText(800, 10, str2);
	}
	if (score >= 30 && score < 60)
	{
		sprintf_s(str3, 19, "level 2!");
		setTextSize(30);
		paintText(800, 10, str3);
	}
	if (score >= 60 && score < 100)
	{
		sprintf_s(str4, 19, "level 3!");
		setTextSize(30);
		paintText(800, 10, str4);
	}
	if (score >= 100 && score < 150)
	{
		sprintf_s(str5, 19, "FIINAL!");
		setTextSize(30);
		paintText(800, 10, str5);
	}
	if (score >= 150)
	{
		fopen_s(&fp1,"score.txt","at+");
		fprintf(fp1,"%d",score);
		fclose(fp1);
		timerCancel();
		putImageScale(&background_2_img, background_2_x, background_2_y, background_2_width, background_2_height);
		putImageTransparent(&win_img, 250, 50, 200, 60, BLACK);
		putImageTransparent(&restart_img, 275, 100, 150, 60, BLACK);
		//sprintf_s(str6, 39, "You win!Get a kiss from Little Sister");
		//setTextSize(30);
		//paintText(200, 130, str6);
	}
	if (score <= -50)
	{
		sprintf_s(str7, 19, "Tip!You can hide in the well");
		setTextSize(20);
		paintText(100, 10, str7);
	}
	if (heart <= 0)
	{
		fopen_s(&fp1, "score.txt", "at+");
		fprintf(fp1, "%d", score);
		fclose(fp1);
		timerCancel();
			/*billsprite1[25]->x = NULL;
			billsprite1[25]->y = NULL;
			coinsprite1[25]->x = NULL;
			coinsprite1[25]->y = NULL;
			coinsprite2[25]->x = NULL;
			coinsprite2[25]->y = NULL;*/
		putImageScale(&background_2_img, background_2_x, background_2_y, background_2_width, background_2_height);
		putImageTransparent(&lose_img, 250, 50, 200, 60, BLACK);
		putImageTransparent(&restart_img, 275, 100, 150, 60, BLACK);
		//sprintf_s(str8, 39, "You lose!Get a kick from Leader Sister");
		//setTextSize(30);
		//(200, 130, str8);
	}
	endPaint();
	return 0;
}

int mouseEvent(int x, int y, int button,int event)
{
	if (button == LEFT_BUTTON && event == BUTTON_DOWN && x > 275 && x < 425 && y > 100 && y < 160)
	{
		timerStart();
		score = 0, heart = 10;
		mario_x = 10, mario_y = 200;
		bad_missile_x = 930, bad_missile_y = 80;
		bad_mask_x = 0, bad_mask_y = 120;
		background_1_x = 0, background_1_y = 0;
		background_2_x = 0, background_2_y = 0;
		bad_green_turtle_x = 200, bad_green_turtle_y = 190;
		greenpole_x = 600, greenpole_y = 160;
		bad_snake_x = 600, bad_snake_y = 0;
		bad_mush_x = 0, bad_mush_y = 0;
	}
	//else return;
	return 0;
}

int keyEvent(int key, int e)
{
	if (e != KEY_DOWN) return;
	switch (key)
	{
	case VK_UP:
		mario_y -= 7;
		if (mario_y <= 0)
			mario_y = 0;
		break;

	case VK_DOWN:
		mario_y += 10;
		if (mario_y >= winHeight - mario_height - wall_2_height)
			mario_y = winHeight - mario_height - wall_2_height;
		break;

	case VK_LEFT:
		mario_x -= 7;
		if (mario_x <= (600 + 40) && mario_x <= (600 + 40 - 6) && mario_y >= 175)
			mario_x = 600 + 40;
		if (mario_x <= 0)
			mario_x = 0;
		if (score <= 60 && mario_x > 0 && background_1_x < 0)
		{
			background_1_x += 5;
			greenpole_x += 5;
			beginPaint();
			putImageScale(&background_1_img, background_1_x, background_1_y, background_1_width, background_1_height);
			putImageScale(&greenpole_img, greenpole_x, greenpole_y, greenpole_width, greenpole_height);
			endPaint();
		}
		if (score > 60 && mario_x > 0 && background_2_x < 0)
		{
			background_2_x += 5;
			greenpole_x += 5;
			beginPaint();
			putImageScale(&background_2_img, background_2_x, background_2_y, background_2_width, background_2_height);
			putImageScale(&greenpole_img, greenpole_x, greenpole_y, greenpole_width, greenpole_height);
			endPaint();
		}
		break;

	case VK_RIGHT:
		mario_x += 7;
		if (mario_x >= (600 - 30) && mario_x <= (600 - 30 + 6) && mario_y >= 175)
			mario_x = 600 - 30;
		if (mario_x >= winWidth - mario_width)
			mario_x = winWidth - mario_width;
		if (score <= 60 && mario_x < background_1_width - winWidth)
		{
			background_1_x -= 5;
			greenpole_x -= 5;
			beginPaint();
			putImageScale(&background_1_img, background_1_x, background_1_y, background_1_width, background_1_height);
			putImageScale(&greenpole_img, greenpole_x, greenpole_y, greenpole_width, greenpole_height);
			endPaint();
		}
		if (score > 60 && mario_x < background_2_width - winWidth)
		{
			background_2_x -= 5;
			greenpole_x -= 5;
			beginPaint();
			putImageScale(&background_2_img, background_2_x, background_2_y, background_2_width, background_2_height);
			putImageScale(&greenpole_img, greenpole_x, greenpole_y, greenpole_width, greenpole_height);
			endPaint();
		}
		break;
	default:break;
	}
	//碰撞
	{
		rectmario.x = mario_x;
		rectmario.y = mario_y;
		rectmario.w = mario_width;
		rectmario.h = mario_height;
		for (int i = 0; i < 1; i++)
		{
			if (goodmushsprite[i])// 不为空
			{
				rectgood_mush[i].x = goodmushsprite[i]->x;
				rectgood_mush[i].y = goodmushsprite[i]->y;
				rectgood_mush[i].w = goodmushsprite[i]->width;
				rectgood_mush[i].h = goodmushsprite[i]->height;

				if (collision(rectmario, rectgood_mush[i]) == 1)
				{
					score += 10;
					heart += 3;
					goodmushsprite[i] = NULL;
				}
			}
		}
		for (int i = 0; i < numbill; i++)
		{
			if (billsprite1[i])// 不为空
			{
				rectbill[i].x = billsprite1[i]->x;
				rectbill[i].y = billsprite1[i]->y;
				rectbill[i].w = billsprite1[i]->width;
				rectbill[i].h = billsprite1[i]->height;

				if (collision(rectmario, rectbill[i]) == 1)
				{
					score += 2;
					billsprite1[i] = NULL;
				}
			}
		}

		for (int i = 0; i < numcoin1; i++)
		{
			if (coinsprite1[i])// 不为空
			{
				rectcoin1[i].x = coinsprite1[i]->x;
				rectcoin1[i].y = coinsprite1[i]->y;
				rectcoin1[i].w = coinsprite1[i]->width;
				rectcoin1[i].h = coinsprite1[i]->height;

				if (collision(rectmario, rectcoin1[i]) == 1)
				{
					score += 3;
					coinsprite1[i] = NULL;
				}
			}
		}
		for (int i = 0; i < numcoin2; i++)
		{
			if (coinsprite2[i])// 不为空
			{
				rectcoin2[i].x = coinsprite2[i]->x;
				rectcoin2[i].y = coinsprite2[i]->y;
				rectcoin2[i].w = coinsprite2[i]->width;
				rectcoin2[i].h = coinsprite2[i]->height;

				if (collision(rectmario, rectcoin2[i]) == 1)
				{
					score -= 1;
					coinsprite2[i] = NULL;
				}
			}
		}
	}

	rectbad_mask.x = bad_mask_x;
	rectbad_mask.y = bad_mask_y;
	rectbad_mask.h = bad_mask_height;
	rectbad_mask.w = bad_mask_width;

	if (collision(rectmario, rectbad_mask) == 1)
	{
		score -= 5;
		heart -= 1;
		mario_x += 10;
	}

	rectgreen_turtle.x = bad_green_turtle_x;
	rectgreen_turtle.y = bad_green_turtle_y;
	rectgreen_turtle.h = bad_green_turtle_height;
	rectgreen_turtle.w = bad_green_turtle_width;

	if (collision(rectmario, rectgreen_turtle) == 1)
	{
		score -= 3;
		heart -= 1;
		mario_x += 10;
	}

	rectbad_missile.x = bad_missile_x;
	rectbad_missile.y = bad_missile_y;
	rectbad_missile.h = bad_missile_height;
	rectbad_missile.w = bad_missile_width;

	if (collision(rectmario, rectbad_missile) == 1)
	{
		score -= 2;
		heart -= 1;
		mario_x += 20;
	}

	rectbad_mush.x = bad_mush_x;
	rectbad_mush.y = bad_mush_y;
	rectbad_mush.h = bad_mush_height;
	rectbad_mush.w = bad_mush_width;

	if (score >= 100 && collision(rectmario, rectbad_mush) == 1)
	{
		score -= 10;
		heart -= 3;
		mario_x += 20;
	}

	rectbad_snake.x = bad_snake_x;
	rectbad_snake.y = bad_snake_y;
	rectbad_snake.h = bad_snake_height;
	rectbad_snake.w = bad_snake_width;

	if (score >= 100 && collision(rectmario, rectbad_snake) == 1)
	{
		score -= 5;
		heart -= 1;
		mario_x += 20;
	}
	/*
	rectgood_mush.x = good_mush2_x;
	rectgood_mush.y = bad_snake_y;
	rectgood_mush.h = bad_snake_height;
	rectgood_mush.w = bad_snake_width;
	if (collison(rectmario, rectbad_snake) == 1)
	{
	score -= 5;
	heart -= 1;
	}//好蘑菇的碰撞滞后*/

	//if()}
	paint();//必须重新绘制
	return 0;
}

int timerEvent(int id)//当500ms到了会发生什么
{
	int i;
	if (id == 0)
	{
		//if (dx_bad_missile = -dx_bad_missile; <= 0||bad_missile_x+ bad_missile_width>= winWidth) dx_bad_missile = -dx_bad_missile;
		bad_missile_x -= dx_bad_missile;
		timecounter++;
		if (timecounter % 100 == 0)
			bad_missile_x = 930;

		rectbad_missile.x = bad_missile_x;
		rectbad_missile.y = bad_missile_y;
		rectbad_missile.h = bad_missile_height;
		rectbad_missile.w = bad_missile_width;

		if (collision(rectbad_missile, rectmario) == 1)
		{
			score -= 2;
			heart -= 1;
			mario_x += 10;
		}
	}

	else if (id == 1 && score >= 30)
	{
		bad_mask_x += dx_bad_mask;
		if (bad_mask_x <= 0 || bad_mask_x + bad_mask_width >= winWidth)
			dx_bad_mask = -dx_bad_mask;

		rectbad_mask.x = bad_mask_x;
		rectbad_mask.y = bad_mask_y;
		rectbad_mask.h = bad_mask_height;
		rectbad_mask.w = bad_mask_width;

		if (collision(rectbad_mask, rectmario) == 1)
		{
			score -= 5;
			heart -= 1;
			mario_x += 20;
		}
	}

	else if (id == 2)
	{
		for (i = 0; i <= numbill; i++)//bill将所有出现的bill进行移动
		{
			if (billsprite1[i])
			{
				billsprite1[i]->x += billsprite1[i]->dx;
				billsprite1[i]->y += billsprite1[i]->dy;

				if (billsprite1[i]->x <= 0 || billsprite1[i]->x + billsprite1[i]->width >= winWidth)
					billsprite1[i]->dx = -billsprite1[i]->dx;

				if (billsprite1[i]->y <= 0 || billsprite1[i]->y + billsprite1[i]->height + wall_2_height >= winHeight)
					billsprite1[i]->dy = -billsprite1[i]->dy;

				rectmario.x = mario_x;
				rectmario.y = mario_y;
				rectmario.w = mario_width;
				rectmario.h = mario_height;
				rectbill[i].x = billsprite1[i]->x;
				rectbill[i].y = billsprite1[i]->y;
				rectbill[i].w = billsprite1[i]->width;
				rectbill[i].h = billsprite1[i]->height;

				if (collision(rectbill[i], rectmario) == 1)
				{
					score += 2;
					billsprite1[i] = NULL;
				}

			}
			//billsprite1[i]->y = rand() % (winHeight - mario_height - wall_2_height - bill_width);
			//billsprite1[i]->x = rand() % (winWidth - bill_height);// 防止卡在边界

		}
		//paint();
	}
	else if (id == 3)
	{
		if (numbill < maxbill)
			numbill++;
		else
			numbill = 0;

		if (billsprite1[numbill] == NULL)
		{
			billsprite1[numbill] = (sprite*)malloc(sizeof(sprite));
			billsprite1[numbill]->width = 20;
			billsprite1[numbill]->height = 20;
			billsprite1[numbill]->x = rand() % (winWidth - billsprite1[numbill]->width);
			billsprite1[numbill]->y = rand() % (winHeight - wall_2_height - billsprite1[numbill]->height);
			billsprite1[numbill]->dx = 2;
			billsprite1[numbill]->dy = 2;
		}
	}
	else if (id == 4)
	{
		bad_green_turtle_x += dx_bad_green_turtle;

		if (bad_green_turtle_x >= 400 || bad_green_turtle_x <= 0)
			dx_bad_green_turtle *= -1;

		rectgreen_turtle.x = bad_green_turtle_x;
		rectgreen_turtle.y = bad_green_turtle_y;
		rectgreen_turtle.h = bad_green_turtle_height;
		rectgreen_turtle.w = bad_green_turtle_width;

		if (collision(rectgreen_turtle, rectmario) == 1)
		{
			score -= 3;
			heart -= 1;
			mario_x += 10;
		}
	}
	
	else if (id == 5)
	{
		for (int i = 0; i < 1; i++)
		{
			if (goodmushsprite[i])
			{
				goodmushsprite[i]->x += goodmushsprite[i]->dx;
				
				if (goodmushsprite[i]->x >= 400 || goodmushsprite[i]->x <= 0)
					goodmushsprite[i]->dx *= -1;

				rectmario.x = mario_x;
				rectmario.y = mario_y;
				rectmario.w = mario_width;
				rectmario.h = mario_height;
				rectgood_mush[i].x = goodmushsprite[i]->x;
				rectgood_mush[i].y = goodmushsprite[i]->y;
				rectgood_mush[i].w = goodmushsprite[i]->width;
				rectgood_mush[i].h = goodmushsprite[i]->height;

				if (collision(rectgood_mush[i], rectmario) == 1)
				{
					score += 10;
					heart += 3;
					goodmushsprite[i] = NULL;
				}
			}
		}
	}
	/*
	else if (id == 6)
	{
	if (numgoodmush < maxgoodmush)
		numgoodmush++;
	if (goodmushsprite[numgoodmush] == NULL)
	{
	goodmushsprite[numgoodmush] = (sprite*)malloc(sizeof(sprite));
	goodmushsprite[numgoodmush]->width = 30;
	goodmushsprite[numgoodmush]->height = 30;
	goodmushsprite[numgoodmush]->x = rand() % (400);
	goodmushsprite[numgoodmush]->y = 200;
	goodmushsprite[numgoodmush]->dx = 8;
	}
	}
	*/
	
	//coin
	else if (id == 7)
	{
		//int i = 0;
		for (i = 0; i <= numcoin1; i++)//coin将所有出现的coin进行移动
		{
			if (coinsprite1[i])
			{
				coinsprite1[i]->x += coinsprite1[i]->dx;
				coinsprite1[i]->y += coinsprite1[i]->dy;

				if (coinsprite1[i]->x <= 0 || coinsprite1[i]->x + coinsprite1[i]->width >= winWidth)
					coinsprite1[i]->dx = -coinsprite1[i]->dx;

				if (coinsprite1[i]->y <= 0 || coinsprite1[i]->y + coinsprite1[i]->height + wall_2_height >= winHeight)
					coinsprite1[i]->dy = -coinsprite1[i]->dy;

				rectmario.x = mario_x;
				rectmario.y = mario_y;
				rectmario.w = mario_width;
				rectmario.h = mario_height;
				rectcoin1[i].x = coinsprite1[i]->x;
				rectcoin1[i].y = coinsprite1[i]->y;
				rectcoin1[i].w = coinsprite1[i]->width;
				rectcoin1[i].h = coinsprite1[i]->height;

				if (collision(rectcoin1[i], rectmario) == 1)
				{
					score += 3;
					coinsprite1[i] = NULL;
				}

			}
		}
	}

	else if (id == 8)
	{
		if (numcoin1 < maxcoin1)
			numcoin1++;
		else
			numcoin1 = 0;

		if (coinsprite1[numcoin1] == NULL)
		{
			coinsprite1[numcoin1] = (sprite*)malloc(sizeof(sprite));
			coinsprite1[numcoin1]->width = 20;
			coinsprite1[numcoin1]->height = 20;
			coinsprite1[numcoin1]->x = rand() % (winWidth - coinsprite1[numcoin1]->width);
			coinsprite1[numcoin1]->y = rand() % (winHeight - wall_2_height - coinsprite1[numcoin1]->height);
			coinsprite1[numcoin1]->dx = 0;
			coinsprite1[numcoin1]->dy = 3;
		}
	}
	//
	else if (id == 9)
	{
		//int i = 0;
		for (i = 0; i <= numcoin2; i++)//coin将所有出现的coin进行移动
		{
			if (coinsprite2[i])
			{
				coinsprite2[i]->x += coinsprite2[i]->dx;
				coinsprite2[i]->y += coinsprite2[i]->dy;

				if (coinsprite2[i]->x <= 0 || coinsprite2[i]->x + coinsprite2[i]->width >= winWidth)
					coinsprite2[i]->dx = -coinsprite2[i]->dx;

				if (coinsprite2[i]->y <= 0 || coinsprite2[i]->y + coinsprite2[i]->height + wall_2_height >= winHeight)
					coinsprite2[i]->dy = -coinsprite2[i]->dy;

				rectmario.x = mario_x;
				rectmario.y = mario_y;
				rectmario.w = mario_width;
				rectmario.h = mario_height;
				rectcoin2[i].x = coinsprite2[i]->x;
				rectcoin2[i].y = coinsprite2[i]->y;
				rectcoin2[i].w = coinsprite2[i]->width;
				rectcoin2[i].h = coinsprite2[i]->height;

				if (collision(rectcoin2[i], rectmario) == 1)
				{
					score -= 1;
					coinsprite2[i] = NULL;
				}

			}
		}
	}

	else if (id == 10)
	{
		if (numcoin2 < maxcoin2)
			numcoin2++;
		else
			numcoin2 = 0;

		if (coinsprite2[numcoin2] == NULL)
		{
			coinsprite2[numcoin2] = (sprite*)malloc(sizeof(sprite));
			coinsprite2[numcoin2]->width = 20;
			coinsprite2[numcoin2]->height = 20;
			coinsprite2[numcoin2]->x = rand() % (winWidth - coinsprite2[numcoin2]->width);
			coinsprite2[numcoin2]->y = rand() % (winHeight - wall_2_height - coinsprite2[numcoin2]->height);
			coinsprite2[numcoin2]->dx = 3;
			coinsprite2[numcoin2]->dy = 1;
		}
	}
	else if (id == 11 && score >= 100)
	{
		bad_snake_y += dy_bad_snake;

		if (bad_snake_y <= 0 || bad_snake_y >= 100)
			dy_bad_snake *= -1;

		rectmario.x = mario_x;
		rectmario.y = mario_y;
		rectmario.w = mario_width;
		rectmario.h = mario_height;
		rectbad_snake.x = bad_snake_x;
		rectbad_snake.y = bad_snake_y;
		rectbad_snake.h = bad_snake_height;
		rectbad_snake.w = bad_snake_width;

		if (collision(rectbad_snake, rectmario) == 1)
		{
			score -= 5;
			heart -= 1;
			mario_x += 10;
		}
	}

	if (id == 12 && score >= 100)
	{
		bad_mush_x += dx_bad_mush;
		bad_mush_y += dy_bad_mush;

		if (bad_mush_x <= 0 || bad_mush_x + bad_mush_width >= winWidth)
			dx_bad_mush *= -1;

		if (bad_mush_y <= 0 || bad_mush_y + bad_mush_height + wall_2_height >= winHeight)
			dy_bad_mush *= -1;

		rectmario.x = mario_x;
		rectmario.y = mario_y;
		rectmario.w = mario_width;
		rectmario.h = mario_height;
		rectbad_mush.x = bad_mush_x;
		rectbad_mush.y = bad_mush_y;
		rectbad_mush.h = bad_mush_height;
		rectbad_mush.w = bad_mush_width;

		if (collision(rectbad_mush, rectmario) == 1)
		{
			score -= 10;
			heart -= 3;
			mario_x += 10;
		}
	}
	paint();
	return 0;
}

int timerCancel()
{
	cancelTimer(id_bad_missile);
	cancelTimer(id_bad_mask);
	cancelTimer(id_bill);
	cancelTimer(id_coin1);
	cancelTimer(id_coin2);
	cancelTimer(createid1);
	cancelTimer(createid3);
	cancelTimer(id_bad_green_turtle);
	cancelTimer(id_good_mush1);
	cancelTimer(id_good_mush2, longtime);
	cancelTimer(id_bad_snake);
	cancelTimer(id_bad_mush);
	return 0;
}

int timerStart()
{
	startTimer(id_bad_missile, timeinterval);//id为0，500ms启动一次
	startTimer(id_bad_mask, timeinterval);
	startTimer(id_bill, timeinterval);
	startTimer(id_coin1, timeinterval);
	startTimer(id_coin2, timeinterval);
	startTimer(createid1, createtimerinterval1);
	startTimer(createid2, createtimerinterval2);
	startTimer(createid3, createtimerinterval3);
	startTimer(id_bad_green_turtle, timeinterval);
	//startTimer(id_good_mush1, timeinterval);
	startTimer(id_good_mush2, longtime);
	startTimer(id_bad_snake, timeinterval);
	startTimer(id_bad_mush, timeinterval);
	return 0;
}