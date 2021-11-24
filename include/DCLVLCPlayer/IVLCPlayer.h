#ifndef IVLCPLAYER_H
#define IVLCPLAYER_H

#include <string>

class IVLCPlayer
{
public:
    virtual void play(float start_time_second) = 0;

    virtual void pause() = 0;

    virtual void set_volume(float volume) = 0;

    virtual int get_width() = 0;

    virtual int get_height() = 0;

    virtual float get_time() = 0;

    virtual float get_duration() = 0;

    virtual int get_state() = 0;

    virtual std::string get_error() = 0;

    virtual void set_time(float second) = 0;

    virtual void playback_rate(float playback_rate) = 0;

    virtual void set_loop(bool loop) = 0;

    virtual bool check_for_image_update(void*& image_pointer) = 0;
};

#endif