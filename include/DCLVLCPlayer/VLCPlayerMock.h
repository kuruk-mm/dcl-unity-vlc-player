#ifndef VLCPLAYERMOCK_H
#define VLCPLAYERMOCK_H

#include "DCLVLCPlayer/IVLCPlayer.h"
#include <stdio.h>
#include <string.h>

#include <iostream>

class VLCPlayerMock : public IVLCPlayer
{
public:
    VLCPlayerMock(std::string url, bool use_hls)
    {
        std::cout << "VLCPlayerMock [url=" << url << "] [use_hls=" << use_hls << "]\n";

        const int size = get_width() * get_height() * 4;
        image = malloc(size);
    }

    ~VLCPlayerMock() {
        free(image);
    }

    void play(float start_time_second) {
        std::cout << "VLCPlayerMock::play [start_time_seconds=" << start_time_second << "]\n";
    }

    void pause() {
        std::cout << "VLCPlayerMock::pause\n";
    };

    void set_volume(float volume) {
        std::cout << "VLCPlayerMock::set_volume [volume=" << volume << "]\n";
    };

    int get_width() {
        std::cout << "VLCPlayerMock::get_width\n";
        return 192;
    }

    int get_height() {
        std::cout << "VLCPlayerMock::get_height\n";
        return 108;
    }

    float get_time() {
        std::cout << "VLCPlayerMock::get_time\n";
        return 2.0;
    }

    float get_duration() {
        std::cout << "VLCPlayerMock::get_duration\n";
        return 4.0;
    }

    int get_state() {
        std::cout << "VLCPlayerMock::get_state\n";
        return 0;
    }

    std::string get_error() {
        std::cout << "VLCPlayerMock::get_error\n";
        return "";
    }

    void set_time(float second) {
        std::cout << "VLCPlayerMock::set_time [second=" << second << "]\n";
    }

    void playback_rate(float playback_rate) {
        std::cout << "VLCPlayerMock::playback_rate [playback_rate=" << playback_rate << "]\n";
    }

    void set_loop(bool loop) {
        std::cout << "VLCPlayerMock::loop [loop=" << loop << "]\n";
    }

    bool check_for_image_update(void*& image_pointer) {
        const int size = get_width() * get_height() * 4;
        if (white_image) {
            memset(image, 255, size);
        } else {
            memset(image, 0, size);
        }

        image_pointer = image;

        white_image = !white_image;
        return true;
    }
private:
    void* image = nullptr;
    bool white_image = false;
};

#endif