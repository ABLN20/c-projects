//
//  CarObserver.cpp
//  
//
//  Created by Yufeng Wu on 12/1/22.
//

#include "CarObserver.h"
#include <sstream>
#include <iostream>
#include <chrono>
#include <thread>

//************************************************************

ECCarObserver :: ECCarObserver( ECGraphicViewImp &viewIn ) : view(viewIn), fIsSpaceBarPressed(false), fIsRightArrowPressed(false), fIsLeftArrowPressed(false), 
                                                            x1(150), y1(400), r1(25), // wheel 1 
                                                            x2(350), y2(400), r2(25), // wheel 2
                                                            x3(50), y3(375), x4(500), y4(250), // lower body of car
                                                            x5(75), y5(250), x6(375), y6(150)  // upper body of car
{
}

void ECCarObserver :: Update()
{
    ECGVEventType evt = view.GetCurrEvent();
    // is an arrow key released?

    if( evt == ECGV_EV_KEY_UP_SPACE)
    {
        fIsSpaceBarPressed = true;
        
        // set the view to redraw
        // Note: call SetRedraw(true) once there is something changed in the view
        view.SetRedraw(true);
    }

    if( evt == ECGV_EV_KEY_UP_RIGHT)
    {
        fIsRightArrowPressed = true;
        
        // set the view to redraw
        view.SetRedraw(true);
    }

    if( evt == ECGV_EV_KEY_UP_LEFT)
    {
        fIsLeftArrowPressed = true;
        
        // set the view to redraw
        view.SetRedraw(true);
    }

    // if this is the timer event
    if( evt == ECGV_EV_TIMER ) // Note: you need to draw on the timer event; otherwise you won't see the anything
    {
        // if space bar pressed, draw a car
        if( fIsSpaceBarPressed )
        {
            int level = 1;
            int x1 = 50;
            int y1 = view.GetHeight() - 50 - 100 * (level-1);
            int x2 = view.GetWidth() - 100;
            int y2 = view.GetHeight() - 150 - 100 * (level-1);
            view.DrawRectangle(x1, y1, x2, y2);
            view.DrawFilledCircle(x2 + 25, y2 + 31, 15, ECGV_GREEN);
            view.DrawCircle(x2 + 25, y2 + 31, 15);
            view.DrawCircle(x2 + 25, y1 - 31, 15);
            view.DrawText(x1-20, y1 - 65, std::to_string(level).c_str(), ECGV_BLACK);
            
            level = 2;
             x1 = 50;
             y1 = view.GetHeight() - 50 - 100 * (level - 1);
             x2 = view.GetWidth() - 100;
             y2 = view.GetHeight() - 150 - 100 * (level-1);
            view.DrawRectangle(x1, y1, x2, y2);
            view.DrawCircle(x2 + 25, y2 + 31, 15);
            view.DrawCircle(x2 + 25, y1 - 31, 15);
            view.DrawLine(0, 425, view.GetWidth(), 425);
            view.DrawText(x1 - 20, y1 - 65, std::to_string(level).c_str(), ECGV_BLACK);
            
            // reset this boolean
            fIsSpaceBarPressed = false;
        }

        if( fIsRightArrowPressed )
        {
            x1 += 10;
            x2 += 10;
            x3 += 10;
            x4 += 10;
            x5 += 10;
            x6 += 10;

            view.DrawFilledRectangle(x3, y3, x4, y4);
            view.DrawFilledRectangle(x5, y5, x6, y6);
            view.DrawFilledCircle(x1, y1, r1);
            view.DrawFilledCircle(x2, y2, r2);
            // reset this boolean
            fIsRightArrowPressed = false;
        }

        if( fIsLeftArrowPressed )
        {
            x1 -= 10;
            x2 -= 10;
            x3 -= 10;
            x4 -= 10;
            x5 -= 10;
            x6 -= 10;

            view.DrawFilledRectangle(x3, y3, x4, y4);
            view.DrawFilledRectangle(x5, y5, x6, y6);
            view.DrawFilledCircle(x1, y1, r1);
            view.DrawFilledCircle(x2, y2, r2);
            view.DrawLine(0, 425, view.GetWidth(), 425);
            // reset this boolean
            fIsLeftArrowPressed = false;
        }
    }
}