#include "iGraphics.h"
#include<stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <time.h>


#pragma comment(lib, "Winmm.lib")

#define JUMPLIMIT 210
#define backGroundSpeed 10

int screenWidth = 1200;
int screenHeight = 700;


void drawHomePage();
void drawDifficultyPage();
void drawDifficultyPage2();
void drawStartPage();
void drawStartPage2();
void drawInstructionsPage();
void drawCharacterSelectionPage();
void drawGameoverPage();
void collision();
void gameover();
void obstacleVariable();
void drawStartPage_2();
void drawStartPage_3();
void drawStartPage2_2();
void drawStartPage2_3();

void difficultyButtonClickHandler();
void difficultyButtonClickHandler2();
void startButtonClickHandler();
void instructionsButtonClickHandler();
void yesButtonClickHandler();
void noButtonClickHandler();
void backButtonClickHandler();
void scoreButtonClickHandler();
void characterSelection1Button();
void characterSelection2Button();

int starButtonClick = 0;

int homePage = 1;
int difficultyPage = 0;
int difficultyPage2 = 0;
int startPage = 0;
int instructionsPage = 0;
int gameoverPage = 0;
int scorePage = 0;
int highScorePage = 0;
int characterSelectionPage = 0;
int startPage2 = 0;
int startPage_2 = 0;
int startPage_3 = 0;
int startPage2_2 = 0;
int startPage2_3 = 0;

int showScore = 0;
int mode;

bool musicOn = true;

int x = 300, y = 300, r = 20;

char dino[13][30] = {"image\\movingDino\\1.bmp", "image\\movingDino\\2.bmp", "image\\movingDino\\3.bmp", "image\\movingDino\\4.bmp",
					 "image\\movingDino\\5.bmp", "image\\movingDino\\6.bmp", "image\\movingDino\\7.bmp", "image\\movingDino\\8.bmp",
					 "image\\movingDino\\9.bmp", "image\\movingDino\\10.bmp", "image\\movingDino\\11.bmp", "image\\movingDino\\12.bmp","image\\movingDino\\13.bmp"};

char dino2[13][30] = {"image\\movingDino\\14.bmp", "image\\movingDino\\15.bmp", "image\\movingDino\\16.bmp", "image\\movingDino\\17.bmp",
					 "image\\movingDino\\18.bmp", "image\\movingDino\\19.bmp", "image\\movingDino\\20.bmp", "image\\movingDino\\21.bmp",
					 "image\\movingDino\\22.bmp", "image\\movingDino\\23.bmp", "image\\movingDino\\24.bmp", "image\\movingDino\\25.bmp", "image\\movingDino\\26.bmp"};

char dinoJ[7][30] = {"image\\movingDino\\jump1.bmp", "image\\movingDino\\jump2.bmp", "image\\movingDino\\jump3.bmp", "image\\movingDino\\jump4.bmp", 
					 "image\\movingDino\\jump5.bmp", "image\\movingDino\\jump6.bmp", "image\\movingDino\\jump7.bmp"};

char dinoJ2[7][30] = {"image\\movingDino\\jump8.bmp", "image\\movingDino\\jump9.bmp", "image\\movingDino\\jump10.bmp", "image\\movingDino\\jump11.bmp", 
					 "image\\movingDino\\jump12.bmp", "image\\movingDino\\jump13.bmp", "image\\movingDino\\jump14.bmp"};                     

char bg[20][50] = {"split\\image1x1.bmp", "split\\image2x1.bmp", "split\\image3x1.bmp", "split\\image4x1.bmp", "split\\image5x1.bmp",
				   "split\\image6x1.bmp", "split\\image7x1.bmp", "split\\image8x1.bmp", "split\\image9x1.bmp", "split\\image10x1.bmp",
				   "split\\image11x1.bmp", "split\\image12x1.bmp", "split\\image13x1.bmp", "split\\image14x1.bmp", "split\\image15x1.bmp",
				   "split\\image16x1.bmp", "split\\image17x1.bmp", "split\\image18x1.bmp", "split\\image19x1.bmp", "split\\image20x1.bmp",
				   };

                   

struct background
{
	int x;
	int y;
};
background BackGround[20];

int dinoCordinateX = 154;
int dinoCordinateY = 162;
int dinoIndex = 0;

bool jump = false;
bool jumpUp = false;
int dinoCordinateJump = 0;

int obstacle1y = 166;
int obstacle2y = 166;
int obstacle3y = 166;
int obstacle1x = 400;
int obstacle2x = 700;
int obstacle3x = 1000;
int obstacle1xspeed = 0;
int obstacle2xspeed = 0;
int obstacle3xspeed = 0;


char sec[10000];
int second = 0;
int score = 0;
int minute = 0;
int hour = 0;
char hr[10000];
int totalSecond = 0;
char point[10000];
char str[100],str2[100];

void changeTimer()
{
	if(startPage == 1 || startPage2 == 1 || startPage_2 ==1 || startPage_3 == 1 || startPage2_2 == 1 || startPage2_3 == 1)
	{
		totalSecond = (second++) + (60*minute) + (60 * 60 * hour);
		score = score + second;
	}
}

void obstacleVariable()
{

	obstacle1x = 400;
	obstacle2x = 700;
	obstacle3x = 1000;
}

void drawTimer()
{
	if(startPage == 1 || startPage2 == 1 || startPage_2 ==1 || startPage_3 == 1 || startPage2_2 == 1 || startPage2_3 == 1)
	{
		iSetColor(141, 76, 176);
		iFilledRectangle(900,600,200,40);

		iSetColor(255,255,255);
		sprintf(sec, "%d" ,second);
		iText(1000,615,sec,GLUT_BITMAP_TIMES_ROMAN_24);

		iText(912,615,"Timer",GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(141, 76, 176);
		iFilledRectangle(900,560,100,50);
		iSetColor(255,255,255);

		iText(910,587,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(point, "%d", score);
		iText(930,562,point,GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void resetLevel()
{
	homePage = 1;
	gameoverPage = 0;
	startPage = 0;
	startPage2 = 0;
	instructionsPage = 0;
	scorePage = 0;
	obstacle1x = 400;
	obstacle2x = 700;
	obstacle3x = 1000;

}

void highScore();
void readScore();
int len = 0;
char str1[100];
bool newScore = true;

struct hscore{
    char name[50];
    int score = 0;
}high_score[5];


void drawScorePage()
{
    int y= 450;
    iSetColor(255,255,255);
    iFilledRectangle(0,0,screenWidth,screenHeight);
    iShowBMP2(0, 0, "image\\dp.bmp", 0);
    iShowBMP2(50,550,"image\\backbutton2.bmp",0);
    iShowBMP2(400,550,"image\\LEADERBOARD.bmp",0);
    iShowBMP2(50, 50, "image\\speaker.bmp", 0);

    FILE *fp;
    fp = fopen("Score.txt","r");
    char showName[5][30],showScore[5][5];
    for(int i=0;i<5;i++)
    {
        fscanf(fp,"%s %d\n",high_score[i].name,&high_score[i].score);
    }
    for(int i=0;i<5;i++)
    {
        iSetColor(255,255,255);
        sprintf(showName[i],"%s",high_score[i].name);
        sprintf(showScore[i],"%d",high_score[i].score);
        //iSetColor(0,255,255);
        iText(650,y,showScore[i],GLUT_BITMAP_HELVETICA_18);
        iSetColor(255,255,255);
        iText(550,y,showName[i],GLUT_BITMAP_HELVETICA_18);
        y-=50;
    }
    fclose(fp);

}

void highScore(int showscore,char str3[100])
{
    FILE *fp;
    fp = fopen("Score.txt","r");
    for(int i=0;i<5;i++)
    {
        fscanf(fp,"%s %d\n",high_score[i].name,&high_score[i].score);
    }
    fclose(fp);
    
    if(high_score[0].score <= showscore)
    {
        for(int j=4;j>=1;j--)
        {
            high_score[j].score = high_score[j-1].score;
            strcpy(high_score[j].name,high_score[j-1].name);
        }
        high_score[0].score = showscore;
        strcpy(high_score[0].name,str3);
    }
    for(int i=0;i<5 && i+1<5;i++)
    {
        if(high_score[i].score>showscore && high_score[i+1].score<showscore)
        {
            for(int j=4;j>i+1;j--)
            {
                high_score[j].score = high_score[j-1].score;
                strcpy(high_score[j].name,high_score[j-1].name);
            }
            high_score[i+1].score = showscore;
            strcpy(high_score[i+1].name,str3);
            break;
        }
    }
    fp = fopen("Score.txt","w");
    for(int i=0;i<5;i++)
    {
        fprintf(fp,"%s  %d\n\n",high_score[i].name,high_score[i].score);
    }
    fclose(fp);
}

void showChar()
{
    iSetColor(255,255,255);
    iShowBMP2(325, 400, "image\\enterYourName.bmp", 0);
    iShowBMP2(480, 250, "image\\score4.bmp", 0);
    iRectangle(495,340,160,30);
    iRectangle(530,200,90,30);
}

void iDraw()
{
	iClear();

	if (homePage == 1)
	{
		drawHomePage();
	}

	else if (difficultyPage == 1)
	{
		drawDifficultyPage();
	}

	else if (difficultyPage2 == 1)
	{
		drawDifficultyPage2();
	}

	else if (startPage == 1)
	{
		drawStartPage();
	}
	else if (startPage_2 == 1)
	{
		drawStartPage_2();
	}
	else if (startPage_3 == 1)
	{
		drawStartPage_3();
	}

    else if(startPage2 == 1)
    {
        drawStartPage2();
    }

	else if (startPage2_2 == 1)
	{
		drawStartPage2_2();
	}
	else if (startPage2_3 == 1)
	{
		drawStartPage2_3();
	}

    else if (characterSelectionPage == 1)
	{
		drawCharacterSelectionPage();
	}

	else if (instructionsPage == 1)
	{
		drawInstructionsPage();
	}

	else if(gameoverPage == 1)
	{
		drawGameoverPage();
        showChar();
        iText(500,350,str,GLUT_BITMAP_TIMES_ROMAN_24);
	}

    else if(scorePage = 1)
    {
        drawScorePage(); 
    }
}

void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x=%d y=%d", mx, my);
		if (homePage == 1 && (mx >= 370 && mx <= 594) && (my >= 301 && my <= 399))
		{
			startButtonClickHandler();
		}
		if (homePage == 1 && ((mx >= 470 && mx <= 769) && (my >= 152 && my <= 251)))
		{
			instructionsButtonClickHandler();
		}
        if (characterSelectionPage == 1 && ((mx >= 212 && mx <= 428) && (my >= 203 && my <= 460)))
		{
			characterSelection1Button();
			obstacleVariable();
		}
        if (characterSelectionPage == 1 && ((mx >= 699 && mx <= 927) && (my >= 207 && my <= 466)))
		{
			characterSelection2Button();
			obstacleVariable();
		}
        if((instructionsPage == 1 || characterSelectionPage == 1 || scorePage == 1) && ((mx >= 55 && mx <= 144) && (my >= 557 && my <= 644))) 
        {
            backButtonClickHandler();
        }
        if(homePage == 1 && ((mx >= 669 && mx <= 894) && (my >= 300 && my <= 400)))
        {
            scoreButtonClickHandler();
        }
		if ((homePage == 1 || instructionsPage == 1 || scorePage == 1 || characterSelectionPage == 1 || gameoverPage == 1) && ((mx >= 55 && mx <= 144) && (my >= 56 && my <= 145)))
		{
			if (musicOn)
			{
				musicOn = false;
				if (!musicOn)
				{
					PlaySound(0, 0, 0);
				}
			}
			else
			{
				musicOn = true;
				if (musicOn)
				{
					PlaySound("music\\bgm.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
		}
        if(gameoverPage == 1 && ((mx >= 495 && mx <= 653) && (my >= 340 && my <= 370)))
		{
			mode = 1;
		}
	}
}

void iKeyboard(unsigned char key)
{
    
	if (key == 'q')
	{
		exit(0);
	}
	if (key == 'm')
	{
		if (musicOn)
		{
			musicOn = false;
			if (!musicOn)
			{
				PlaySound(0, 0, 0);
			}
		}
		else
		{
			musicOn = true;
			if (musicOn)
			{
				PlaySound("music\\bgm.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
	}
	if (key == ' ')
	{
		if (!jump)
		{
			jump = true;
			jumpUp = true;
            PlaySound("music\\jumpingsound.wav", NULL,SND_FILENAME | SND_ASYNC);
		}
	}
    if(gameoverPage == 1)
    {
        if(mode == 1)
        {
            if(key == '\r')
            {
                mode = 0;
                strcpy(str2,str);
                highScore(score,str2);
                //score = 0;
                printf("%s\n",str2);
                for(int i=0;i<len;i++)
                    str[i] = 0;
                len = 0;
            }
            else if(key == '\b')
            {
                len--;
                str[len] = '\0';
            }
            else
            {
                str[len] = key;
                len++;
            }
        }
    }
    if(gameoverPage == 1)
    {
        if(key == '\r')
        {
            resetLevel();
        }
    }
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}

void drawHomePage()
{
	iSetColor(128, 128, 128);
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	iShowBMP2(0, 0, "image\\dp.bmp", 0);

	iShowBMP2(370, 450, "image\\LOGO.bmp", 0);
	iShowBMP2(370, 300, "image\\button1.bmp", 0);
	iShowBMP2(670, 300, "image\\button1.bmp", 0);
	iShowBMP2(470, 150, "image\\button2.bmp", 0);
	iShowBMP2(400, 320, "image\\start.bmp", 0);
	iShowBMP2(700, 320, "image\\score.bmp", 0);
	iShowBMP2(520, 175, "image\\instructions.bmp", 0);
	iShowBMP2(50, 50, "image\\speaker.bmp", 0);

	iSetColor(255, 255, 255);
	obstacleVariable();
}

void drawDifficultyPage()
{
	iSetColor(128, 128, 128);
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	iShowBMP2(0, 0, "image\\dp.bmp", 0);

	iShowBMP2(470, 290, "image\\button1.bmp", 0);
	iText(500, 330, "DIFFICULTY", GLUT_BITMAP_TIMES_ROMAN_24);
}

void drawDifficultyPage2()
{
	iSetColor(128, 128, 128);
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	iShowBMP2(0, 0, "image\\dp.bmp", 0);

	iShowBMP2(370, 450, "image\\button1.bmp", 0);
	iShowBMP2(370, 250, "image\\button4.bmp", 0);
	iShowBMP2(370, 50, "image\\button3.bmp", 0);

	iSetColor(255, 255, 255);
	iText(450, 490, "EASY", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(430, 290, "MEDIUM", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(450, 90, "HARD", GLUT_BITMAP_TIMES_ROMAN_24);
}

void drawStartPage()
{
	//iClear();
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	iShowBMP(0, 0, "image\\startPage.bmp");

	for (int i = 0; i < 20; i++)
	{
		iShowBMP(BackGround[i].x, BackGround[i].y, bg[i]);
	}

	
		PlaySoundA("music\\ingamesound.wav", NULL, SND_LOOP | SND_ASYNC);
	

	iShowBMP2(obstacle1x, obstacle1y, "image\\movingDino\\cactus1 (2).bmp", 0);
	iShowBMP2(obstacle2x, obstacle2y, "image\\movingDino\\rock (2).bmp", 0);
	iShowBMP2(obstacle3x, obstacle3y, "image\\movingDino\\cactus3 (2).bmp", 0);
	iShowBMP2(50, 600, "image\\fullLife2.bmp", 0);
	iShowBMP2(110,600, "image\\fullLife2.bmp", 0);
	iShowBMP2(170, 600, "image\\fullLife2.bmp", 0);

	if (jump == false)
	{
		iShowBMP2(dinoCordinateX, dinoCordinateY, dino[dinoIndex], 0);
	}
	else if (jump)
	{

		if (jumpUp)
		{
			int i=0;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ[i], 0);
			i++;

		}
		else
		{
			int i=4;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ[i], 0);
			i++;
		}
	}
	
	if(gameoverPage != 1 && startPage == 1 && homePage != 1){
	obstacle1x = obstacle1x - 10;
	
	if(obstacle1x <= 0)
	{
		obstacle1x=screenWidth;
	}collision();
	}
	if(gameoverPage != 1 && startPage == 1 && homePage != 1){
	obstacle2x = obstacle2x - 10;
    
	if(obstacle2x <= 0)
	{
		obstacle2x=screenWidth;
	}collision();
	}
	if(gameoverPage != 1 && startPage == 1 && homePage != 1){
	obstacle3x = obstacle3x - 10;
    
	if(obstacle3x <= 0)
	{
		obstacle3x=screenWidth ;
	}collision();
	}

	drawTimer();
}

void drawStartPage_2()
{
	iClear();
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	iShowBMP(0, 0, "image\\startPage.bmp");
	for (int i = 0; i < 20; i++)
	{
		iShowBMP(BackGround[i].x, BackGround[i].y, bg[i]);
	}

	if (musicOn)
	{
		PlaySound("music\\ingamesound.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	iShowBMP2(obstacle1x, obstacle1y, "image\\movingDino\\cactus1 (2).bmp", 0);
	iShowBMP2(obstacle2x, obstacle2y, "image\\movingDino\\rock (2).bmp", 0);
	iShowBMP2(obstacle3x, obstacle3y, "image\\movingDino\\cactus3 (2).bmp", 0);
	iShowBMP2(50, 600, "image\\fullLife2.bmp", 0);
	iShowBMP2(110,600, "image\\fullLife2.bmp", 0);
	iShowBMP2(170, 600, "image\\zeroLife2.bmp", 0);

	if (jump == false)
	{
		iShowBMP2(dinoCordinateX, dinoCordinateY, dino[dinoIndex], 0);
	}
	else if (jump)
	{

		if (jumpUp)
		{
			int i=0;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ[i], 0);
			i++;

		}
		else
		{
			int i=4;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ[i], 0);
			i++;
		}
	}
	
	if(gameoverPage != 1 && startPage_2 == 1 && homePage != 1){
	obstacle1x = obstacle1x - 10;
	
	if(obstacle1x <= 0)
	{
		obstacle1x=screenWidth;
	}collision();
	}
	if(gameoverPage != 1 && startPage_2 == 1 && homePage != 1){
	obstacle2x = obstacle2x - 10;
    
	if(obstacle2x <= 0)
	{
		obstacle2x=screenWidth;
	}collision();
	}
	if(gameoverPage != 1 && startPage_2 == 1 && homePage != 1){
	obstacle3x = obstacle3x - 10;
    
	if(obstacle3x <= 0)
	{
		obstacle3x=screenWidth ;
	}collision();
	}

	drawTimer();
}

void drawStartPage_3()
{
	iClear();
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	iShowBMP(0, 0, "image\\startPage.bmp");
	for (int i = 0; i < 20; i++)
	{
		iShowBMP(BackGround[i].x, BackGround[i].y, bg[i]);
	}

	if (musicOn)
	{
		PlaySound("music\\ingamesound.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	iShowBMP2(obstacle1x, obstacle1y, "image\\movingDino\\cactus1 (2).bmp", 0);
	iShowBMP2(obstacle2x, obstacle2y, "image\\movingDino\\rock (2).bmp", 0);
	iShowBMP2(obstacle3x, obstacle3y, "image\\movingDino\\cactus3 (2).bmp", 0);
	iShowBMP2(50, 600, "image\\fullLife2.bmp", 0);
	iShowBMP2(110,600, "image\\zeroLife2.bmp", 0);
	iShowBMP2(170, 600, "image\\zeroLife2.bmp", 0);

	if (jump == false)
	{
		iShowBMP2(dinoCordinateX, dinoCordinateY, dino[dinoIndex], 0);
	}
	else if (jump)
	{

		if (jumpUp)
		{
			int i=0;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ[i], 0);
			i++;

		}
		else
		{
			int i=4;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ[i], 0);
			i++;
		}
	}
	
	if(gameoverPage != 1 && startPage_3 == 1 && homePage != 1){
	obstacle1x = obstacle1x - 10;
	
	if(obstacle1x <= 0)
	{
		obstacle1x=screenWidth;
	}collision();
	}
	if(gameoverPage != 1 && startPage_3 == 1 && homePage != 1){
	obstacle2x = obstacle2x - 10;
    
	if(obstacle2x <= 0)
	{
		obstacle2x=screenWidth;
	}collision();
	}
	if(gameoverPage != 1 && startPage_3 == 1 && homePage != 1 ){
	obstacle3x = obstacle3x - 10;
    
	if(obstacle3x <= 0)
	{
		obstacle3x=screenWidth ;
	}collision();
	}

	drawTimer();
}

void drawStartPage2()
{
	iClear();
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	iShowBMP(0, 0, "image\\startPage.bmp");
	for (int i = 0; i < 20; i++)
	{
		iShowBMP(BackGround[i].x, BackGround[i].y, bg[i]);
	}

	if (musicOn)
	{
		PlaySound("music\\ingamesound.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	iShowBMP2(obstacle1x, obstacle1y, "image\\movingDino\\cactus1 (2).bmp", 0);
	iShowBMP2(obstacle2x, obstacle2y, "image\\movingDino\\rock (2).bmp", 0);
	iShowBMP2(obstacle3x, obstacle3y, "image\\movingDino\\cactus3 (2).bmp", 0);
	iShowBMP2(50, 600, "image\\fullLife2.bmp", 0);
	iShowBMP2(110,600, "image\\fullLife2.bmp", 0);
	iShowBMP2(170, 600, "image\\fullLife2.bmp", 0);

	if (jump == false)
	{
		iShowBMP2(dinoCordinateX, dinoCordinateY, dino2[dinoIndex], 0);
	}
	else if (jump)
	{

		if (jumpUp)
		{
			int i=0;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ2[i], 0);
			i++;

		}
		else
		{
			int i=4;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ2[i], 0);
			i++;
		}
	}
	obstacle1x = obstacle1x - 10;
	
	if(obstacle1x <= 0)
	{
		obstacle1x=screenWidth;
	}collision();
	obstacle2x = obstacle2x - 10;
    
	if(obstacle2x <= 0)
	{
		obstacle2x=screenWidth;
	}collision();
	obstacle3x = obstacle3x - 10;
    
	if(obstacle3x <= 0)
	{
		obstacle3x=screenWidth ;
	}collision();

	drawTimer();
}

void drawStartPage2_2()
{
	iClear();
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	iShowBMP(0, 0, "image\\startPage.bmp");
	for (int i = 0; i < 20; i++)
	{
		iShowBMP(BackGround[i].x, BackGround[i].y, bg[i]);
	}

	if (musicOn)
	{
		PlaySound("music\\ingamesound.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	iShowBMP2(obstacle1x, obstacle1y, "image\\movingDino\\cactus1 (2).bmp", 0);
	iShowBMP2(obstacle2x, obstacle2y, "image\\movingDino\\rock (2).bmp", 0);
	iShowBMP2(obstacle3x, obstacle3y, "image\\movingDino\\cactus3 (2).bmp", 0);
	iShowBMP2(50, 600, "image\\fullLife2.bmp", 0);
	iShowBMP2(110,600, "image\\fullLife2.bmp", 0);
	iShowBMP2(170, 600, "image\\zeroLife2.bmp", 0);

	if (jump == false)
	{
		iShowBMP2(dinoCordinateX, dinoCordinateY, dino2[dinoIndex], 0);
	}
	else if (jump)
	{

		if (jumpUp)
		{
			int i=0;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ2[i], 0);
			i++;

		}
		else
		{
			int i=4;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ2[i], 0);
			i++;
		}
	}
	obstacle1x = obstacle1x - 10;
	
	if(obstacle1x <= 0)
	{
		obstacle1x=screenWidth;
	}collision();
	obstacle2x = obstacle2x - 10;
    
	if(obstacle2x <= 0)
	{
		obstacle2x=screenWidth;
	}collision();
	obstacle3x = obstacle3x - 10;
    
	if(obstacle3x <= 0)
	{
		obstacle3x=screenWidth ;
	}collision();

	drawTimer();
}

void drawStartPage2_3()
{
	iClear();
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	iShowBMP(0, 0, "image\\startPage.bmp");
	for (int i = 0; i < 20; i++)
	{
		iShowBMP(BackGround[i].x, BackGround[i].y, bg[i]);
	}

	if (musicOn)
	{
		PlaySound("music\\ingamesound.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	iShowBMP2(obstacle1x, obstacle1y, "image\\movingDino\\cactus1 (2).bmp", 0);
	iShowBMP2(obstacle2x, obstacle2y, "image\\movingDino\\rock (2).bmp", 0);
	iShowBMP2(obstacle3x, obstacle3y, "image\\movingDino\\cactus3 (2).bmp", 0);
	iShowBMP2(50, 600, "image\\fullLife2.bmp", 0);
	iShowBMP2(110,600, "image\\zeroLife2.bmp", 0);
	iShowBMP2(170, 600, "image\\zeroLife2.bmp", 0);

	if (jump == false)
	{
		iShowBMP2(dinoCordinateX, dinoCordinateY, dino2[dinoIndex], 0);
	}
	else if (jump)
	{

		if (jumpUp)
		{
			int i=0;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ2[i], 0);
			i++;

		}
		else
		{
			int i=4;
			iShowBMP2(dinoCordinateX , dinoCordinateY + dinoCordinateJump, dinoJ2[i], 0);
			i++;
		}
	}
	

	obstacle1x = obstacle1x - 10;
	
	if(obstacle1x <= 0)
	{
		obstacle1x=screenWidth;
	}collision();
	obstacle2x = obstacle2x - 10;
    
	if(obstacle2x <= 0)
	{
		obstacle2x=screenWidth;
	}collision();
	obstacle3x = obstacle3x - 10;
    
	if(obstacle3x <= 0)
	{
		obstacle3x=screenWidth ;
	}collision();

	drawTimer();
}

void drawCharacterSelectionPage()
{
    iSetColor(128, 128, 128);
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	iShowBMP2(0, 0, "image\\dp.bmp", 0);
    iShowBMP2(200, 200, "image\\movingDino\\character1.bmp", 0);
    iShowBMP2(700, 200, "image\\movingDino\\character2.bmp", 0);
    iShowBMP2(150, 100, "image\\movingDino\\BARNEY.bmp", 0);
    iShowBMP2(700, 100, "image\\movingDino\\SPIKE.bmp", 0);
    iShowBMP2(50,550,"image\\backbutton2.bmp",0);
    iShowBMP2(140,550,"image\\chooseCharacter.bmp",0);
    iShowBMP2(50, 50, "image\\speaker.bmp", 0);
}

void drawGameoverPage()
{
	if (musicOn)
		{
			PlaySound("music\\gameover.wav", NULL, SND_LOOP | SND_ASYNC);
		}
		else
		{
			PlaySound(0, 0, 0);
		}
    
	char str[100];
	iSetColor(255, 255, 255);
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	
    iShowBMP2(0, 0, "image\\dp.bmp", 0);
    iShowBMP2(330, 500, "image\\gameover2.bmp", 0);

    sprintf(str,"%d",score);
    iText(540,210,str,GLUT_BITMAP_TIMES_ROMAN_24);
    iShowBMP2(50, 50, "image\\speaker.bmp", 0);
}

void drawInstructionsPage()
{
	iSetColor(128, 128, 128);
	iFilledRectangle(0, 0, screenWidth, screenHeight);
	iShowBMP2(0, 0, "image\\instructionsPage.bmp", 0);
    iShowBMP2(50,550,"image\\backbutton2.bmp",0);
    iShowBMP2(370, 550, "image\\LOGO.bmp", 0);
	
	
    iShowBMP2(50, 50, "image\\speaker.bmp", 0);
}

void startButtonClickHandler()
{
	homePage = 0;
	difficultyPage = 0;
	difficultyPage2 = 0;
	gameoverPage = 0;
	startPage = 0;
    startPage2 = 0;
	instructionsPage = 0;
    characterSelectionPage = 1;
    scorePage = 0;
    score = 0;
	second = 0;
}

void difficultyButtonClickHandler()
{
	homePage = 0;
	difficultyPage = 0;
	difficultyPage2 = 1;
}

void difficultyButtonClickHandler2()
{
	homePage = 0;
	difficultyPage = 0;
	difficultyPage2 = 0;
	gameoverPage = 0;
	startPage = 0;
	instructionsPage = 0;
}

void instructionsButtonClickHandler()
{
	homePage = 0;
	difficultyPage = 0;
	difficultyPage2 = 0;
	gameoverPage = 0;
	startPage = 0;
    startPage2 = 0;
	instructionsPage = 1;
    characterSelectionPage = 0;
    scorePage = 0;
}

void scoreButtonClickHandler()
{
    homePage = 0;
	difficultyPage = 0;
	difficultyPage2 = 0;
	gameoverPage = 0;
	startPage = 0;
    startPage2 = 0;
	instructionsPage = 0;
    characterSelectionPage = 0;
    scorePage = 1;
}

void characterSelection1Button()
{
    homePage = 0;
	difficultyPage = 0;
	difficultyPage2 = 0;
	gameoverPage = 0;
	startPage = 1;
    startPage2 = 0;
	instructionsPage = 0;
    characterSelectionPage = 0;
    scorePage = 0;
	
}

void characterSelection2Button()
{
    homePage = 0;
	difficultyPage = 0;
	difficultyPage2 = 0;
	gameoverPage = 0;
    startPage = 0;
	startPage2 = 1;
	instructionsPage = 0;
    characterSelectionPage = 0;
    scorePage = 0;
}

void backButtonClickHandler()
{
    homePage = 1;
	difficultyPage = 0;
	difficultyPage2 = 0;
	gameoverPage = 0;
	startPage = 0;
    startPage2 = 0;
	instructionsPage = 0;
    characterSelectionPage = 0;
    scorePage = 0;
}

void change()
{
	
	if (jump == false)
	{
		dinoIndex++;
	}
	if (dinoIndex >= 13)
	{
		dinoIndex = 0;
	}

	if (jump)
	{
		if (jumpUp)
		{
			dinoCordinateJump += 30;
			if (dinoCordinateJump >= JUMPLIMIT)
			{
				jumpUp = false;
			}
		}
		else
		{
			dinoCordinateJump -= 30;
			if (dinoCordinateJump < 0)
			{
				jump = false;
				dinoCordinateJump = 0;
			}
		}
	}
	
}

void change2()
{
	for (int i = 0; i < 20; i++)
	{
		BackGround[i].x -= backGroundSpeed;
		if (BackGround[i].x <= 0)
		{
			BackGround[i].x = screenWidth-60;
		}
	}
}

void collision()
{
	if((dinoCordinateX+26>=obstacle1x  && dinoCordinateX<=obstacle1x+26) && (dinoCordinateY+dinoCordinateJump+60>=obstacle1y && dinoCordinateY+dinoCordinateJump<=obstacle1y+60))
	{

        if(startPage == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 1;
			startPage_3 = 0;
			obstacleVariable();
		}
		else if(startPage_2 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 1;
			obstacleVariable();
		}
		else if(startPage_3 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 1;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			PlaySoundA("music\\gameover.wav", NULL, SND_LOOP | SND_ASYNC);
			obstacleVariable();
		}
		if(startPage2 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			startPage2_2 = 1;
			startPage2_3 = 0;
			obstacleVariable();
		}
		else if(startPage2_2 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			startPage2_2 = 0;
			startPage2_3 = 1;
			obstacleVariable();
		}
		else if(startPage2_3 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 1;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			startPage2_2 = 0;
			startPage2_3 = 0;
			obstacleVariable();
		}  
	}
	else if((dinoCordinateX+26>=obstacle2x  && dinoCordinateX<=obstacle2x+26) && (dinoCordinateY+dinoCordinateJump+60>=obstacle2y  && dinoCordinateY+dinoCordinateJump<=obstacle2y+60))
	{
		if(startPage == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 1;
			startPage_3 = 0;
			obstacleVariable();
		}
		else if(startPage_2 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 1;
			obstacleVariable();
		}
		else if(startPage_3 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 1;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			obstacleVariable();
		}
		if(startPage2 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			startPage2_2 = 1;
			startPage2_3 = 0;
			obstacleVariable();
		}
		else if(startPage2_2 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			startPage2_2 = 0;
			startPage2_3 = 1;
			obstacleVariable();
		}
		else if(startPage2_3 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 1;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			startPage2_2 = 0;
			startPage2_3 = 0;
			obstacleVariable();
		}
	}
	else if((dinoCordinateX+26>=obstacle3x  && dinoCordinateX<=obstacle3x+26) && (dinoCordinateY+dinoCordinateJump+60>=obstacle3y  && dinoCordinateY+dinoCordinateJump<=obstacle3y+60))
	{
		if(startPage == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 1;
			startPage_3 = 0;
			printf("huh");
			obstacleVariable();
		}
		else if(startPage_2 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 1;
			obstacleVariable();
		}
		else if(startPage_3 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 1;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			obstacleVariable();
		}
		if(startPage2 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			startPage2_2 = 1;
			startPage2_3 = 0;
			obstacleVariable();
		}
		else if(startPage2_2 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 0;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			startPage2_2 = 0;
			startPage2_3 = 1;
			obstacleVariable();
		}
		else if(startPage2_3 == 1){
			homePage = 0;
	    	difficultyPage = 0;
	    	difficultyPage2 = 0;
	    	gameoverPage = 1;
	    	startPage = 0;
        	startPage2 = 0;
	    	instructionsPage = 0;
			startPage_2 = 0;
			startPage_3 = 0;
			startPage2_2 = 0;
			startPage2_3 = 0;
			obstacleVariable();
		}
	}
	
}

void setAll()
{
	int sum = 0;
	for (int i = 0; i < 20; i++)
	{
		BackGround[i].y = 0;
		BackGround[i].x = sum;
		sum += 60;
	}
}

int main()
{
	setAll();
	iSetTimer(25,change2);
	iSetTimer(60, change);
	iSetTimer(1000,changeTimer);
    mode = 0;
    len = 0;
    str[0] = 0;
	if (musicOn)
	{
		PlaySound("music\\bgm.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	iInitialize(screenWidth, screenHeight, "Jurassic Jump");
	return 0;
}