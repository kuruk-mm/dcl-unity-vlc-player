#ifndef VLCPLAYER_H
#define VLCPLAYER_H

#include "DCLVLCPlayer/IVLCPlayer.h"

#include "vlc/libvlc.h"
#include "vlc/libvlc_media.h"
#include "vlc/libvlc_media_player.h"
#include "vlc/libvlc_media_list.h"
#include "vlc/libvlc_media_list_player.h"

class VLCPlayer : public IVLCPlayer
{
    VLCPlayer(std::string url, bool use_hls);

    ~VLCPlayer();

    void play(float start_time_second);

    void pause();

    void set_volume(float volume);

    int get_width();

    int get_height();

    float get_time();

    float get_duration();

    int get_state();

    std::string get_error();

    void set_time(float second);

    void playback_rate(float playback_rate);

    void set_loop(bool loop);

    bool check_for_image_update(void*& image_pointer);
private:

};

#endif