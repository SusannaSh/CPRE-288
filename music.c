/*
    @author Randolph Roman
    4/18/24

*/
#include "music.h"

void load_music(int song)
{
    if(song == FFVII)
    {
    unsigned char ffNumNotes = 10;
    unsigned char ffNotes[10]    = {72, 72, 72, 72, 68, 70, 72, 0 , 70, 72};
    unsigned char ffDuration[10] = {10, 10, 10, 30, 30, 30, 10, 10, 10, 89};

    oi_loadSong(FFVII, ffNumNotes, ffNotes, ffDuration);
    }
    else if(song == DRIFT1)
    {
        unsigned char drift1NumNotes = 16;
            unsigned char drift1Notes[16]    = {63, 70, 69, 68, 66, 61, 63, 73, 75, 0, 75, 0, 75, 0, 73, 75};
            unsigned char drift1Duration[16] = {14, 14, 14, 14, 14, 14, 14, 14, 7 , 7, 7 , 7, 7 , 7, 14, 14};

            oi_loadSong(DRIFT1, drift1NumNotes, drift1Notes, drift1Duration);
    }
    else if(song == DRIFT2)
    {
            unsigned char drift2NumNotes = 15;
            unsigned char drift2Notes[15]    = {70, 73, 70, 75, 78, 77, 78, 70, 73, 75, 73, 75, 70, 68, 70};
            unsigned char drift2Duration[15] = {14, 14, 14, 41, 14, 14, 14, 14, 14, 27, 14, 14, 21, 7 , 27};

            oi_loadSong(DRIFT2, drift2NumNotes, drift2Notes, drift2Duration);
    }
    else if(song == DRIFT3)
    {
         //   unsigned char drift3NumNotes = 16;
         //   unsigned char drift3Notes[16]    = {78, 77, 78, 80, 82, 75, 73, 75, 77, 78, 77, 75, 80, 82, 78, 75};
         //   unsigned char drift3Duration[16] = {14, 14, 14, 14, 14, 27, 14, 14, 14, 7 , 7 , 27, 41, 14, 27, 14};
        unsigned char drift3NumNotes = 1;
        unsigned char drift3Notes[1]    = {77};
        unsigned char drift3Duration[1] = {32};



            oi_loadSong(DRIFT3, drift3NumNotes, drift3Notes, drift3Duration);
    }
    else if(song == DRIFT4)
    {
            unsigned char drift4NumNotes = 16;
            unsigned char drift4Notes[16]    = {78, 80, 82, 78, 75, 78, 77,  0, 77,  0, 70, 73, 70, 73, 75, 73};
            unsigned char drift4Duration[16] = {14, 41, 14, 27, 14, 14, 14, 14, 14, 27, 14, 14, 14, 14, 82, 14};

            oi_loadSong(DRIFT4, drift4NumNotes, drift4Notes, drift4Duration);
    }
    else if(song == DRIFT5)
    {
            unsigned char drift5NumNotes = 6;
            unsigned char drift5Notes[6]    = {75, 0, 75, 0, 75, 0 };
            unsigned char drift5Duration[6] = {7 , 7, 7 , 7, 7 , 21};

            oi_loadSong(DRIFT5, drift5NumNotes, drift5Notes, drift5Duration);
    }



}

