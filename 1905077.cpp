#include "iGraphics.h"
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>

double pi = 3.1415;

int screenWidth = 1400;
int screenHeight = 800;
int midheight = 450;

std::vector<double> amplitudes = {120, 70, 110};
std::vector<double> frequencies = {1, 6, 2};
std::vector<int> tracerShow = {1, 1, 1};
std::vector<double> phaseShifts = {0, 0, 0};
int resultanttracerShow = 1;
int showCurve = 1;
int showTracer = 1;

double ampfac = 1;
double freqfac = 1;
int tracerCount = 3;
int tracerX = 0;
int dir = 1;
int tracerVel = 1;

int firstpage = 1;



// Functions to handle adding and removing curves
void addCurve() {
    int randomAmplitude = rand() % 100 + 50;
    int randomFrequency = rand() % 5 + 1;
    amplitudes.push_back(randomAmplitude); // Initial amplitude for new curve
    frequencies.push_back(randomFrequency);  // Initial frequency for new curve
    tracerShow.push_back(1);    // Show new tracer by default
    ++tracerCount;
}

void removeCurve() {
    if (tracerCount > 0) {
        amplitudes.pop_back();
        frequencies.pop_back();
        tracerShow.pop_back();
        --tracerCount;
    }
}

double sum(double angle)
{
    double sum = 0;
    for (int i = 0; i < tracerCount; ++i)
    {
        sum += ampfac * amplitudes[i] * sin(freqfac * angle * frequencies[i]);
    }
    return sum;
}

void drawCurves() {
    for (int j = 0; j < tracerCount; ++j) {
        for (double x = 0; x <= screenWidth; ++x) {
            double angle = (x + phaseShifts[j]) * pi / 180;
            double y = ampfac * amplitudes[j] * sin(angle * frequencies[j] * freqfac);
            iPoint(x, y + midheight);
        }
    }
    for (int x = 0; x <= screenWidth; x++) {
        double angle = (x+phaseShifts[0]) * pi / 180;
        double y = sum(angle);
        iPoint(x, y + midheight);
    }
}



void phaseShift(double shift)
{
    for (int i = 0; i < tracerCount; ++i)
    {
        phaseShifts[i] += shift;
    }
}

void tracer()
{
    for (int j = 0; j < tracerCount; ++j)
    {
        double tracerY = 0;
        double angle = (tracerX + phaseShifts[j]) * pi / 180;

        iSetColor(255, 0, 0); // Change color for different tracers if needed
        tracerY = ampfac * amplitudes[j] * sin(angle * frequencies[j] * freqfac);
        if (tracerShow[j])
            iFilledCircle(tracerX, tracerY + midheight, 5);
    }
    if (resultanttracerShow)
    {
        iSetColor(0, 255, 0);
        double y = sum((tracerX + phaseShifts[0]) * pi / 180);
        iFilledCircle(tracerX, y + midheight, 5);
    }
}

void drawHelpPage()
{
    iSetColor(255, 255, 255);
    iText(10, 10, "press p to pause, press r to resume");
    iText(10, 30, "press 1, 2, 3 to toggle tracers");
    iText(10, 50, "press 4 to toggle resultant tracer");
    iText(10, 50, "press b to toggle tracer visibility");
    iText(10, 70, "press s to toggle curve visibility");
    iText(10, 90, "press f to increase frequency");
    iText(10, 110, "press F to decrease frequency");
    iText(10, 130, "press a to increase amplitude");
    iText(10, 150, "press A to decrease amplitude");
    iText(10, 170, "press + to increase tracer speed");
    iText(10, 190, "press - to decrease tracer speed");
    iText(10, 210, "press q to quit");
    iText(10, 230, "Press 0 to start");
}

void drawMainPage()
{
    iLine(0, midheight, screenWidth, midheight);
    if (showCurve)
        drawCurves();
    if (showTracer)
        tracer();
    iText(10, 230, "Press 0 to go back to help page");
    // Provision for any number of sin/cos curves. add button to add more curves




}

void iDraw()
{
    iClear();
    iSetColor(255, 255, 255);

    // if (showCurve)
    //     drawCurves();
    // if (showTracer)
    //     tracer();

    // iText(10, 10, "press p to pause, press r to resume");
    if (firstpage)
    {
        drawHelpPage();
    }
    else
    {
        drawMainPage();
    }
}

void tracerchange()
{

    tracerX += dir * tracerVel;

    if (tracerX > screenWidth)
        dir *= -1;
    if (tracerX < 0)
        dir *= -1;
}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button,int state, int x,int y){
}


void iKeyboard(unsigned char key)

{
    if (key == '0')
    {
        firstpage = 1 - firstpage;
    }
    if (key == 'p')
    {
        iPauseTimer(0);
    }
    if (key == 'r')
    {
        iResumeTimer(0);
    }
    if (key == 'q')
    {
        exit(0);
    }
    if (key == '1')
    {
        if (tracerShow[0] == 1)
        {
            tracerShow[0] = 0;
        }
        else
        {
            tracerShow[0] = 1;
        }
    }
    if (key == '2')
    {
        if (tracerShow[1] == 1)
        {
            tracerShow[1] = 0;
        }
        else
        {
            tracerShow[1] = 1;
        }
    }
    if (key == '3')
    {
        if (tracerShow[2] == 1)
        {
            tracerShow[2] = 0;
        }
        else
        {
            tracerShow[2] = 1;
        }
    }
    if (key == '4')
    {
        if (resultanttracerShow == 1)
        {
            resultanttracerShow = 0;
        }
        else
        {
            resultanttracerShow = 1;
        }
    }
    if (key == 'b' || key == 'B')
    {
        if (showTracer == 1)
        {
            showTracer = 0;
        }
        else
        {
            showTracer = 1;
        }
    }

    if (key == 'S' || key == 's')
    {
        if (showCurve == 1)
        {
            showCurve = 0;
        }
        else
        {
            showCurve = 1;
        }
    }
    if (key == 'f')
    {
        freqfac *= 1.05;
    }
    if (key == 'F')
    {
        freqfac /= 1.05;
    }

    if (key == 'a')
    {
        ampfac *= 1.25;
    }
    if (key == 'A')

    {
        ampfac /= 1.25;
    }

    if (key == '+')
    {
        tracerVel += 1;
    }
    if (key == '-')
    {
        tracerVel -= 1;
        if (tracerVel < 0)
            tracerVel = 0;
    }
    if(key=='j'){
        addCurve();

    }
    if(key=='k'){
        removeCurve();
    }
    if(key =='l'){
        phaseShift(10);
    }
}

void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
}

int main()
{
    iSetTimer(25, tracerchange);
    iInitialize(screenWidth, screenHeight, "Fun with curves!");
    return 0;
}
