#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "movie.h"

// Function: Parameterized Constructor
// Purpose: Sets member variables to input, clears list, and calls loader
// Input: None
// Returns: Nothing
MoviePlayer::MoviePlayer(std::string filmName)
{
    //set appropriate member variables
    mFilmName = filmName;
    //ensure tape is empty
    mFilm.clear();
    //call member function loadTape
    loadTape();
}

// Function: Destructor
// Purpose: Empties the list
// Input: None
// Returns: Nothing
MoviePlayer::~MoviePlayer()
{
    //ensure tape is empty
    mFilm.clear();
}

// Function: goFwrd
// Purpose: Moves the current "frame" forward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goFwrd()
{
    if(pos->mNext != nullptr)
    {
        //move tape forward 1 frame
        pos++;
        //increment currFrameNum counter
        currFrameNum++;
    }
}

// Function: goBack
// Purpose: Moves the current "frame" backward by 1 frame
// Also keeps track of how many frames have been viewed
// Shouldn't go past the end of the movie
// Input: None
// Returns: Nothing
void MoviePlayer::goBack()
{
    if(pos->mPrev != nullptr)
    {
        //move tape back 1 fram
        pos--;
        //decrement currFrameNum counter
        currFrameNum--;
    }
}

// Function: rewind
// Purpose: Moves the current "frame" to the movie's beginning again
// Input: None
// Returns: Nothing
void MoviePlayer::rewind()
{
    //start tape over again, move current frame to begin
    pos = mFilm.begin();
    //keep track of currFrameNum
    currFrameNum = 1;
}

// Function: getCurrFrame
// Purpose: Gets the string that contains the current "frame" as stored
// in the list "mFilm"
// Input: None
// Returns: String with the current "frame"
std::string MoviePlayer::getCurrFrame()
{
    return *pos;
}

// Function: delCurrFrame
// Purpose: Deletes the current frame, moves forward to the next one
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::delCurrFrame()
{
    //delete current frame
    //move tape forward by 1 frame
    if(pos->mNext != nullptr)
    {
        //erase returns an iterator to after, so store this back in pos
        pos = mFilm.erase(pos);
    }
}

// Function: copyCurrFrame
// Purpose: Copies current frame and places the copy BEFORE the current frame
// Also keeps track of how many frames have been viewed
// Input: None
// Returns: Nothing
void MoviePlayer::copyCurrFrame()
{
	//copy current frame, place before current fram
    //move tape to newly added frame
    //insert returns an iterator pointing to the inserted value
    pos = mFilm.insert(pos, *pos);
}

// Function: getCurrFrameNum
// Purpose: Gets the "index" that corresponds to the current frame
// Input: None
// Returns: Number of frames that have been viewed
unsigned MoviePlayer::getCurrFrameNum() const
{
    return currFrameNum;
}

// Function: getNumFrames
// Purpose: Gets the total number of frames in the movie
// Input: None
// Returns: The overall number of frames in the movie
unsigned int MoviePlayer::getNumFrames() const
{
    return mFilm.size();
}

// Function: getFrameSize
// Purpose: Gives the number of lines in a frame
// For how big the "screen" for the film should be
// Input: None
// Returns: The value stored in FRAMESIZE
unsigned int MoviePlayer::getFrameSize() const
{
    return FRAMESIZE;
}

// Function: loadTape
// Purpose: Uses mFilmName (set by constructor) to fill
// mFilm with strings that make up the movie to display
// Input: None
// Returns: Nothing
void MoviePlayer::loadTape()
{
    //open inputted text file
    std::ifstream ifile(mFilmName);
    if(!ifile.is_open())
    {
        throw std::invalid_argument("File not found");
    }
    else
    {
        //parse out text file
        while(!ifile.eof())
        {
            std::string curr;
            //each frame begins with separator line
            //get line with number that indicates how long frame should be shown
            std::getline(ifile, curr);
            //convert that to an int
            int displayTime = atoi(curr.c_str());
            //the following 13 lines makes up image to display
            std::string frames = "";
            for(int i = 0; i < FRAMESIZE; i++)
            {
                //get each line of frame
                std::getline(ifile, curr);
                //add each line to frames
                frames += (curr + " \n");
            }
            //num = how many times to insert frame into list
            for(int i = 0; i < displayTime; i++)
            {
                //fill ITPDoubleList with images
                mFilm.push_back(frames);;
            }
        }
    }
}

