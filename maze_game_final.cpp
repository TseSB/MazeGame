
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <time.h>

int curPos[3]={0,1,1};
int level = 1;
int tempPos=-1;
int tick = 60;
int food = 0;
int screen = 1;
int intial_time = time(NULL);
int final_time;
int choice =1;
int life = 5;
int crash = 5;

int grid[32][32] ={
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,4,0,0,1,0,0,1,0,0,1,0,0,0,5,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,3},
    {1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0},
    {1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0},
    {1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0},
    {1,0,0,0,1,1,1,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,0,1,0},
    {1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,1,1,0,1,0,0,1,1,1,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,5,1,0,1,0},
    {1,0,1,0,1,0,0,1,5,0,1,1,1,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0},
    {1,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,0},
    {1,0,1,0,1,0,0,0,0,0,1,5,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,1,0,0,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
    {1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0},
    {1,0,0,0,0,0,0,1,0,0,1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,1,1,1,0},
    {1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,5,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,1,0},
    {1,0,0,0,1,1,1,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,1,0},
    {1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,1,0},
    {1,1,1,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
};

int grid1[32][32] ={
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,3,1,0,1,0,0,0,0,0,0,0,1,0,5,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,1},
    {1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,4},
    {1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,5,1,0,1,0},
    {1,0,1,0,1,0,1,1,5,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,0,5,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
    {1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0},
    {1,5,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,1,1,1,0,0},
    {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0},
    {1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,1,0,0},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0},
    {1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,1,1,0,1,1,1,1,0,0},
    {1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0},
    {1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,0,0},
    {1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
void reset(){
    level = 1;
    tempPos=-1;
    tick = 60;
    food = 0;
    intial_time = time(NULL);
    crash = 5;
    
    if(level == 1){
        curPos[1]={1};curPos[2]={1};
    }else if (level == 2){
        curPos[1]={2};curPos[2]={31};
    }
    screen = 1;
    
    grid[1][1]=4;
    grid[1][31]=3;
    grid[1][21]=5;
    grid[15][11]=5;
    
    grid1[1][1]=3;
    grid1[2][31]=4;
    grid1[1][21]=5;
    grid1[15][11]=5;
}

void drawBitmapText(std::string a,float x,float y,float z)
{
    glRasterPos3f(x, y, z);
    
    for (int i=0; i < a.length();i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, a[i]);
    }
}

//square drawer
void drawSquare(int x, int y,int LENGTH){
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    x = x + LENGTH;
    glVertex2f(x, y);
    y = y + LENGTH;
    glVertex2f(x, y);
    x = x - LENGTH;
    glVertex2f(x, y);
    
    glEnd();
}

void infoBox(int seconds)
{
    glColor3f(1.0,1.0,1.0);
    drawSquare(55,-10, 50);
    glColor3f(0.0,1.0,0.0);
    std::string b = "Life: " + std::to_string(crash) + " lives";
    std::string a = "Time: " + std::to_string(seconds) + " Sec\n";
    drawBitmapText( b, 70, 15,0);
    drawBitmapText( a, 70, 25,0);
    drawBitmapText("You have eaten " + std::to_string(food) + " foods", 70, 20, 0);
    drawBitmapText("By Tsega and Rakeb", 70, -5, 0);
    drawBitmapText("MazeGame\n",70,0,0);
    
}

void firstScreen(int choice){
    if(choice == 1 ){
        glColor3f(0.0, 1.0, 1.0);
        drawBitmapText("Start\n",0,0,0);
        glColor3f(1.0, 1.0, 1.0);
        drawBitmapText("Description\n",0,-5,0);
        drawBitmapText("Quit",0,-10,0);
    }else if(choice == 2){
        glColor3f(1.0, 1.0, 1.0);
        drawBitmapText("Start\n",0,0,0);
        glColor3f(0.0, 1.0, 1.0);
        drawBitmapText("Description\n",0,-5,0);
        glColor3f(1.0, 1.0, 1.0);
        drawBitmapText("Quit",0,-10,0);
    }else if(choice == 3){
        glColor3f(1.0, 1.0, 1.0);
        drawBitmapText("Start\n",0,0,0);
        glColor3f(1.0, 1.0, 1.0);
        drawBitmapText("Description\n",0,-5,0);
        glColor3f(0.0, 1.0, 1.0);
        drawBitmapText("Quit",0,-10,0);
    }
    
}
void descriptionScreen(){
    glColor3f(0.0, 1.0, 1.0);//for square
    drawSquare(-50,-50, 750);
    glColor3f(1.0, 0.0, 1.0);//for writing
    std::string descript="Simply we could understand the meaning of maze game from the word maze itself. Maze is a path typically from an entrance to a goal, \n so this game is actually kind ";
    drawBitmapText(descript,-45,45,0);
    descript="of fun cause in order for us to win the game we should find a way out by going through the obstacles. The \n game has actually two levels. \n";
    drawBitmapText(descript,-45,40,0);
    descript="When playing the game, the player should go through the maze to the exit point without touching the grass  cause if that happen the game will \n";
    drawBitmapText(descript,-45,35,0);
    descript="are wide and also the time given is enough to complete the level without any special effort. The second level on the other hand is kind of \n lead the";
    drawBitmapText(descript,-45,30,0);
    descript="player back to the start. There is also time limitation. The first level is simple because the grasses  hard, maze grass will become narrow and ";
    drawBitmapText(descript,-45,25,0);
    descript="it takes some concentration to go through the maze. In addition to that the time given in level two \n is short and to make it more difficult there ";
    drawBitmapText(descript,-45,20,0);
    descript="is a bee that you cannot touch or points will be deducted. As the fun part the user gets to eat food \n and gain points. And also the user got ";
    drawBitmapText(descript,-45,15,0);
    descript="only three lives since you might touch the grass and the things so that will decrease your score. After \n finishing the levels you will get an award.\n";
    drawBitmapText(descript,-45,10,0);
    
    descript="PRESS B to go back";
    drawBitmapText(descript,-45,-10,0);
}

void startScreen(){
    if(tick > 0){
        int LENGTH = 3;
        int gridValue = 0;
        int intial_k=-50;
        int intial_l=-50;
        for (int k = intial_k; k<41; k+=LENGTH){
            for (int l = intial_l; l<47; l+=LENGTH){
                if(level == 1 ){
                    gridValue = grid[int( (k - intial_k) / (LENGTH) ) ][ int( (l - intial_l) / (LENGTH) )];
                }else if (level == 2){
                    gridValue = grid1[int( (k - intial_k) / (LENGTH) ) ][ int( (l - intial_l) / (LENGTH) )];
                }
                if (gridValue == 0){
                    glColor3f(0.0, 1.0, 0.0);
                     drawSquare(l,k,LENGTH);
                }else if (gridValue == 1){
                    glColor3f(1.0, 1.0, 1.0);
                     drawSquare(l,k,1);
                }else if (gridValue == 4){
                    glColor3f(1.0, 0.0, 1.0);
                     drawSquare(l,k,LENGTH);
                }else if (gridValue == 3){
                    glColor3f(1.0, 1.0, 0.0);
                     drawSquare(l,k,LENGTH);
                }
                else if(gridValue == 5){
                    glColor3f(0.0,2.0,2.0);
                     drawSquare(l,k,LENGTH);
                }else{
                    glColor3f(1.0,0.0,2.0);
                     drawSquare(l,k,LENGTH);
                }
            }
        }
        infoBox(tick);
        if(level == 1){
            glColor3f(1.0,0.0,0.0);
            drawBitmapText("START",-48,-49,0);
            drawBitmapText("END",43,-46,0);
        }else if(level == 2){
            glColor3f(1.0,0.0,0.0);
            drawBitmapText("END",-48,-49,0);
            drawBitmapText("START",43,-46,0);
        }
        
    }else{
        screen=6;//game over screen
    }
    final_time = time(NULL);
    if (final_time - intial_time == 1){
        tick--;
        intial_time = time(NULL);
    }
}

void wonGameScreen(){
    glColor3f(1.0, 0.0, 1.0);
    std::string descript="YOU WON";
    drawBitmapText(descript,25,0,0);
    if(level == 1){
        glColor3f(1.0, 0.0, 1.0);
        descript="PRESS C TO CONTINUE TO LEVEL 2";
        drawBitmapText(descript,25,-5,0);
        descript="PRESS B to go back";
        drawBitmapText(descript,25,-10,0);
        curPos[1]={2};curPos[2]={31};
    }else if (level == 2){
        reset();
    }

    
}
void gameOverScreen(){
    glColor3f(1.0, 0.0, 1.0);
    std::string descript="GAME OVER!";
    drawBitmapText(descript,25,0,0);
    descript="PRESS B to go back";
    drawBitmapText(descript,25,5,0);
    if(level==2){
        reset();
    }
    grid[curPos[1]][curPos[2]]=0;
    grid1[curPos[1]][curPos[2]]=0;
    
}

/* Callback handler for window redraw event */
void display(){
    if (screen == 1){//the list
        glClear(GL_COLOR_BUFFER_BIT);
        reset();
        firstScreen(choice);
    }else if(screen == 2){//the maze
        glClear(GL_COLOR_BUFFER_BIT);
        startScreen();
    }else if(screen == 3){//description
        glClear(GL_COLOR_BUFFER_BIT);
        descriptionScreen();
    }else if(screen == 5){//won
        glClear(GL_COLOR_BUFFER_BIT);
        wonGameScreen();
    }else if(screen == 6){//gameover
        glClear(GL_COLOR_BUFFER_BIT);
        gameOverScreen();
    }
    glutSwapBuffers();
}
/* Callback handler for normal-key event */
void keyboard(unsigned char key, int x, int y) {
    if(level == 1){
        tempPos=grid[curPos[1]-1][curPos[2]];
    }else if(level == 2){
        tempPos=grid1[curPos[1]-1][curPos[2]];
    }
    switch (key) {
        case 27:     // ESC key
            exit(0);
            break;
        case 115:
        case 83:// s down key
            if(screen == 1)
            {
                if(choice == 1){
                    choice = 2;
                }else if(choice == 2){
                    choice = 3;
                }else if(choice == 3){
                    choice = 1;
                }
            }
            if(level == 1){
                tempPos=grid[curPos[1]-1][curPos[2]];
                if (tempPos == 1){
                    if(crash < 1){
                        screen = 6;//game over screen
                    }
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]={1};curPos[2]={1};
                    tempPos=-1;
                    grid[1][1]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]--;
                    grid[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]--;
                    grid[curPos[1]][curPos[2]]=4;
                    screen = 5;// you won screen
                }else if (tempPos == 5){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]--;
                    grid[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }else if(level == 2){
                tempPos=grid1[curPos[1]-1][curPos[2]];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]={2};curPos[2]={31};
                    tempPos=-1;
                    grid1[2][31]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]--;
                    grid1[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]--;
                    grid1[curPos[1]][curPos[2]]=4;
                    screen = 5;
                }else if (tempPos == 5){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]--;
                    grid1[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }
            break;
        case 97:
        case 65: // A left key
            if(level == 1){
                tempPos=grid[curPos[1]][curPos[2]-1];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]={1};curPos[2]={1};
                    tempPos=-1;
                    grid[1][1]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid[curPos[1]][curPos[2]]=4;
                    screen = 5;
                }else if (tempPos == 5){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }else if(level == 2){
                tempPos=grid1[curPos[1]][curPos[2]-1];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]={2};curPos[2]={31};
                    tempPos=-1;
                    grid1[2][31]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid1[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid1[curPos[1]][curPos[2]]=4;
                    screen = 5;
                }else if (tempPos == 5){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid1[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }
            
            break;
        case 100:
        case 68: // D right key
            if(level == 1){
                tempPos=grid[curPos[1]][curPos[2]+1];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]={1};curPos[2]={1};
                    tempPos=-1;
                    grid[1][1]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid[curPos[1]][curPos[2]]=4;
                    screen = 5;
                }else if (tempPos == 5){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }else if(level == 2){
                tempPos=grid1[curPos[1]][curPos[2]+1];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]={2};curPos[2]={31};
                    tempPos=-1;
                    grid1[2][31]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid1[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid1[curPos[1]][curPos[2]]=4;
                    screen = 5;
                }else if (tempPos == 5){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid1[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }
            break;
        case 119:
        case 87: // W up key
            if(screen == 1)
            {
                if(choice == 1){
                    choice = 3;
                }else if(choice == 2){
                    choice = 1;
                }else if(choice == 3){
                    choice = 2;
                }
            }
            if( level == 1){
                tempPos=grid[curPos[1]+1][curPos[2]];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]={1};curPos[2]={1};
                    tempPos=-1;
                    grid[1][1]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid[curPos[1]][curPos[2]]=4;
                    screen=5;
                }else if (tempPos == 5){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }else if( level == 2){
                tempPos=grid1[curPos[1]+1][curPos[2]];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]={2};curPos[2]={31};
                    tempPos=-1;
                    grid1[2][31]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid1[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid1[curPos[1]][curPos[2]]=4;
                    screen=5;
                }else if (tempPos == 5){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid1[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }
            
            break;
        case 99: // c continue
            if(screen == 5 and !(level == 2)){
                level=2;
                life=5;
                screen=2;
                tick=60;
                intial_time = time(NULL);
                food=0;
            }
            break;
        case 13:
            if(screen == 1)
            {
                if(choice == 1){
                    choice = 1;
                    screen = 2;//start screen
                }else if(choice == 2){
                    choice = 1;
                    screen = 3;//description
                }else if(choice == 3){
                    choice = 1;
                    exit(0);
                }
                tick = 60;
                intial_time = time(NULL);
            }
            break;
        case 8:
            if(screen != 1 and screen != 2)
            {
                choice = 1;
                screen = 1;
            }
            break;
        case 98:
            if(screen != 1 and screen != 2)
            {
                choice = 1;
                screen = 1;
            }
            break;
            
    }
}




/* Callback handler for special-key event */
void specialKeys(int key, int x, int y) {
    
    switch (key) {
        case GLUT_KEY_DOWN:
            if(screen == 1)
            {
                if(choice == 1){
                    choice = 2;
                }else if(choice == 2){
                    choice = 3;
                }else if(choice == 3){
                    choice = 1;
                }
            }
            if(level == 1){
                 tempPos=grid[curPos[1]-1][curPos[2]];
                 if (tempPos == 1){
                     if(crash == 0){
                         screen = 6;
                     }
                     grid[curPos[1]][curPos[2]]=0;
                     curPos[1]={1};curPos[2]={1};
                     tempPos=-1;
                     grid[1][1]=4;
                     crash--;
                 }else if (tempPos == 0){
                     grid[curPos[1]][curPos[2]]=0;
                     curPos[1]--;
                     grid[curPos[1]][curPos[2]]=4;
                 }else if (tempPos == 3){
                     grid[curPos[1]][curPos[2]]=0;
                     curPos[1]--;
                     grid[curPos[1]][curPos[2]]=4;
                     screen = 5;
                 }else if (tempPos == 5){
                     grid[curPos[1]][curPos[2]]=0;
                     curPos[1]--;
                     grid[curPos[1]][curPos[2]]=4;
                     food++;
                 }
            }else if(level == 2){
                tempPos=grid1[curPos[1]-1][curPos[2]];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]={2};curPos[2]={31};
                    tempPos=-1;
                    grid1[2][31]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]--;
                    grid1[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]--;
                    grid1[curPos[1]][curPos[2]]=4;
                    screen = 5;
                }else if (tempPos == 5){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]--;
                    grid1[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }
            break;
        case GLUT_KEY_UP:
            if(screen == 1)
            {
                if(choice == 1){
                    choice = 3;
                }else if(choice == 2){
                    choice = 1;
                }else if(choice == 3){
                    choice = 2;
                }
            }
            if( level == 1){
                tempPos=grid[curPos[1]+1][curPos[2]];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]={1};curPos[2]={1};
                    tempPos=-1;
                    grid[1][1]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid[curPos[1]][curPos[2]]=4;
                    screen=5;
                }else if (tempPos == 5){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }else if( level == 2){
                tempPos=grid1[curPos[1]+1][curPos[2]];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]={2};curPos[2]={31};
                    tempPos=-1;
                    grid1[2][31]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid1[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid1[curPos[1]][curPos[2]]=4;
                    screen=5;
                }else if (tempPos == 5){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]++;
                    grid1[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }
            
            break;
        case GLUT_KEY_LEFT:
            if(level == 1){
                tempPos=grid[curPos[1]][curPos[2]-1];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]={1};curPos[2]={1};
                    tempPos=-1;
                    grid[1][1]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid[curPos[1]][curPos[2]]=4;
                    screen = 5;
                }else if (tempPos == 5){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }else if(level == 2){
                tempPos=grid1[curPos[1]][curPos[2]-1];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]={2};curPos[2]={31};
                    tempPos=-1;
                    grid1[2][31]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid1[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid1[curPos[1]][curPos[2]]=4;
                    screen = 5;
                }else if (tempPos == 5){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]--;
                    grid1[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }
            
             break;
        case GLUT_KEY_RIGHT:
            if(level == 1){
                tempPos=grid[curPos[1]][curPos[2]+1];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[1]={1};curPos[2]={1};
                    tempPos=-1;
                    grid[1][1]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid[curPos[1]][curPos[2]]=4;
                    screen = 5;
                }else if (tempPos == 5){
                    grid[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }else if(level == 2){
                tempPos=grid1[curPos[1]][curPos[2]+1];
                if (tempPos == 1){
                    if(crash == 0){
                        screen = 6;
                    }
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[1]={2};curPos[2]={31};
                    tempPos=-1;
                    grid1[2][31]=4;
                    crash--;
                }else if (tempPos == 0){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid1[curPos[1]][curPos[2]]=4;
                }else if (tempPos == 3){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid1[curPos[1]][curPos[2]]=4;
                    screen = 5;
                }else if (tempPos == 5){
                    grid1[curPos[1]][curPos[2]]=0;
                    curPos[2]++;
                    grid1[curPos[1]][curPos[2]]=4;
                    food++;
                }
            }
             break;
    }
}
void idle(int){
    glutPostRedisplay();
    glutTimerFunc(1000/20,idle, 0);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1380,700);
    glutCreateWindow ("MAZE");
    gluOrtho2D(-50,100,-50,50);
    glutDisplayFunc(display);
    glutTimerFunc(1000/20,idle, 0);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
