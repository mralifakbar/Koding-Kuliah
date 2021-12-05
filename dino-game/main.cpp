#include <ncurses.h>
#include <string>
#include <fstream>
using namespace std;

void play();
void floor(WINDOW *win);
void run(WINDOW *win, int type);
void jump(WINDOW *win);
void obstacle(WINDOW *win, int frame);
bool isOver(WINDOW *win, int obsFrame, int jumpFrame);
void currScore(WINDOW *win, int score);
void gameOver(WINDOW *win, int score);

int main()
{
    play();
}

void play()
{
    int action, dinoFrame = 0, jumpFrame = 0, obsFrame = 45, score = 0;
    initscr();
    noecho();
    curs_set(0);
    halfdelay(1);

    WINDOW *win = newwin(15, 50, 5, 10);
    refresh();
    box(win, 0, 0);
    wrefresh(win);

    while((action = wgetch(win)) != 'x')
    {
        //Run
        if (action == -1 && jumpFrame == 0)
        {
            run(win, dinoFrame % 2);
            dinoFrame++;
        }
        
        //Jump
        else if (action == ' ' || jumpFrame != 0)
        {
            jump(win);
            jumpFrame++;
            if (jumpFrame == 7)
            {
                jumpFrame = 0;
                mvwprintw(win, 4, 8, "   ");
                mvwprintw(win, 5, 8, "   ");
                mvwprintw(win, 6, 8, "   ");
                run(win, 0);   
            }
        }

        //Obstacle
        obstacle(win, obsFrame);
        obsFrame--;
        if (obsFrame == 1)
        {
            mvwprintw(win, 7, 1, "   ");
            mvwprintw(win, 8, 1, "   ");
            obsFrame = 45;
        }

        //Is Over
        if (isOver(win, obsFrame, jumpFrame))
        {
            break;
        }

        //Score
        currScore(win, score);
        score++;

        floor(win);
    }
    halfdelay(100);
    gameOver(win, score);
    getch();
    endwin();
}

void floor(WINDOW *win)
{
    for (int i = 0; i < 5; i++)
    {
        mvwprintw(win, 9 + i, 1, "%s", string(48, '^').c_str());
    }
}

void run(WINDOW *win, int type)
{
    switch(type)
    {
        case 0:
            mvwprintw(win, 6, 8, "  #");
            mvwprintw(win, 7, 8, "###");
            mvwprintw(win, 8, 8, "# # ");
            break;
        case 1:
            mvwprintw(win, 6, 8, "  #");
            mvwprintw(win, 7, 8, "###");
            mvwprintw(win, 8, 8, " # #");
            break;
    }
    wrefresh(win);
}

void jump(WINDOW *win)
{
    mvwprintw(win, 6, 8, "    ");
    mvwprintw(win, 7, 8, "    ");
    mvwprintw(win, 8, 8, "    ");
    mvwprintw(win, 4, 8, "  #");
    mvwprintw(win, 5, 8, "###");
    mvwprintw(win, 6, 8, "# # ");
    wrefresh(win);
}

void obstacle(WINDOW *win, int frame)
{
    mvwprintw(win, 7, frame, "@@  ");
    mvwprintw(win, 8, frame, "@@  ");
    wrefresh(win);
}

bool isOver(WINDOW *win, int obsFrame, int jumpFrame)
{
    if ((obsFrame == 10 || obsFrame == 9 || obsFrame == 8) && (jumpFrame < 2 || jumpFrame > 5))
    {
        return true;
    }
    return false;
}

void gameOver(WINDOW *win, int score)
{
    ifstream readData;
    readData.open("topscore.txt");
    int topScore;
    string _topScore;
    getline(readData, _topScore);
    topScore = stoi(_topScore);
    readData.close();

    if (score > topScore) 
    {
        topScore = score;

        ofstream writeData;
        writeData.open("topscore.txt", ios::trunc);
        writeData << topScore;
        writeData.close();
    }

    int playAgain = 0;

    for (int i = 0; i < 4; i++)
    {
        mvwprintw(win, 1 + i, 1, "%s", string(48, ' ').c_str());
    }

    mvwprintw(win, 6, 8, "     ");
    mvwprintw(win, 7, 8, "     ");
    mvwprintw(win, 8, 8, "     ");
    mvwprintw(win, 4, 8, "     ");
    mvwprintw(win, 5, 8, "     ");
    mvwprintw(win, 5, 13, "Game Over");
    mvwprintw(win, 6, 13, "Score: %d", score);
    mvwprintw(win, 7, 13, "Top Score: %d", score);
    mvwprintw(win, 8, 13, "Press Space to Continue");

    for (int i = 0; i < 5; i++)
    {
        mvwprintw(win, 9 + i, 1, "%s", string(48, ' ').c_str());
    }

    if((playAgain = wgetch(win)) == ' ')
    {
        play();
    }
    wrefresh(win);
}

void currScore(WINDOW *win, int score)
{
    mvwprintw(win, 1, 35, "Score: %d", score);
    wrefresh(win);
}