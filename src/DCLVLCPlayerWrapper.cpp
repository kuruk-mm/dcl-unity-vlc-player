#include "DCLVLCPlayer/DCLVLCPlayerWrapper.h"
#include <map>
#include <memory>

#include "DCLVLCPlayer/VLCPlayerMock.h" // temp

struct Environment {
    std::map<std::string, std::unique_ptr<IVLCPlayer>> players;

    IVLCPlayer* get_by_id(std::string id)
    {
        auto it = players.find(id);

        if (it != players.end())
        {
            return it->second.get();
        }
        else
        {
            return nullptr;
        }
    }
};

static std::unique_ptr<Environment> environment = nullptr;

void dclvlc_init()
{
    environment = std::make_unique<Environment>();
}

void dclvlc_free()
{
    environment.release();
}

dclvlc_id dclvlc_create(dclvlc_id id, const char* url, bool use_hls)
{
    if (!environment) return "";

    auto it = environment->players.find(id);

    if (it != environment->players.end())
        return ""; // Already exists


    //auto vlcPlayerCtx = std::make_unique<VLCPlayerMock>(url, use_hls);
    
    // Initialize

    environment->players[id] = std::make_unique<VLCPlayerMock>(url, use_hls);

    return id;
}

void dclvlc_release(dclvlc_id id)
{
    if (!environment) return;

    auto it = environment->players.find(id);

    if (it == environment->players.end())
        return; // No exists
    
    environment->players.erase(it);
}

void dclvlc_play(dclvlc_id id, float start_time_seconds)
{
    if (!environment) return;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);

    if (vlcPlayerCtx == nullptr) return;

    vlcPlayerCtx->play(start_time_seconds);
}

void dclvlc_pause(dclvlc_id id)
{
    if (!environment) return;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return;

    vlcPlayerCtx->pause();
}

void dclvlc_set_volume(dclvlc_id id, float volume)
{
    if (!environment) return;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return;

    vlcPlayerCtx->set_volume(volume);
}

int dclvlc_get_width(dclvlc_id id)
{
    if (!environment) return -1;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return -1;

    return vlcPlayerCtx->get_width();
}

int dclvlc_get_height(dclvlc_id id)
{
    if (!environment) return -1;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return -1;

    return vlcPlayerCtx->get_height();
}

float dclvlc_get_time(dclvlc_id id)
{
    if (!environment) return -1.0f;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return -1.0f;

    return vlcPlayerCtx->get_time();
}

float dclvlc_get_duration(dclvlc_id id)
{
    if (!environment) return -1.0f;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return -1.0f;

    return vlcPlayerCtx->get_duration();
}

int dclvlc_get_state(dclvlc_id id)
{
    if (!environment) return -1;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return -1;

    return vlcPlayerCtx->get_state();
}

const char* dclvlc_get_error(dclvlc_id id)
{
    if (!environment) return "Environment no initialized";

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return "VLCPlayerContext id not found";

    return vlcPlayerCtx->get_error().c_str();
}

void dclvlc_set_time(dclvlc_id id, float second)
{
    if (!environment) return;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return;

    vlcPlayerCtx->set_time(second);
}

void dclvlc_set_loop(dclvlc_id id, bool loop)
{
    if (!environment) return;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return;

    vlcPlayerCtx->set_loop(loop);
}

void dclvlc_playback_rate(dclvlc_id id, float playbackRate)
{
    if (!environment) return;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return;

    vlcPlayerCtx->playback_rate(playbackRate);
}

bool dclvlc_check_for_image_update(dclvlc_id id, void*& img)
{
    if (!environment) return false;

    IVLCPlayer* vlcPlayerCtx = environment->get_by_id(id);
    
    if (vlcPlayerCtx == nullptr) return false;

    return vlcPlayerCtx->check_for_image_update(img);
}