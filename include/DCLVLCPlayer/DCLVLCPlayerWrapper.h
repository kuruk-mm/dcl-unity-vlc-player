#if defined(_MSC_VER)
    //  Microsoft 
    #define export __declspec(dllexport)
    #define import __declspec(dllimport)
#elif defined(__GNUC__)
    //  GCC
    #define export __attribute__((visibility("default")))
    #define import
#else
    //  do nothing and hope for the best?
    #define export
    #define import
    #pragma warning Unknown dynamic link import/export semantics.
#endif

typedef const char* dclvlc_id;

extern "C" {
    export void dclvlc_init();

    export void dclvlc_free();

    export dclvlc_id dclvlc_create(dclvlc_id id, const char* url, bool use_hls);

    export void dclvlc_release(dclvlc_id id);

    export void dclvlc_play(dclvlc_id id, float start_time_second);

    export void dclvlc_pause(dclvlc_id id);

    export void dclvlc_set_volume(dclvlc_id id, float volume);

    export int dclvlc_get_width(dclvlc_id id);

    export int dclvlc_get_height(dclvlc_id id);

    export float dclvlc_get_time(dclvlc_id id);

    export float dclvlc_get_duration(dclvlc_id id);

    export int dclvlc_get_state(dclvlc_id id);

    export const char* dclvlc_get_error(dclvlc_id id);

    export void dclvlc_set_time(dclvlc_id id, float second);

    export void dclvlc_playback_rate(dclvlc_id id, float playback_rate);

    export void dclvlc_set_loop(dclvlc_id id, bool loop);

    export bool dclvlc_check_for_image_update(dclvlc_id id, void*& img);
}