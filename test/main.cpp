#include <iostream>
#include "DCLVLCPlayer/DCLVLCPlayerWrapper.h"
#include <thread>

uint8_t average(uint8_t* image)
{
  ulong accum = 0;
  int size = sizeof(image);
  for(int i = 0; i < size; ++i) {
    accum += (ulong)image[i];
  }
  return (uint8_t)(accum / (ulong)size);
}

int main(int argc, char **argv)
{
  dclvlc_init();

  dclvlc_id id = dclvlc_create("asd", "http://commondatastorage.googleapis.com/gtv-videos-bucket/sample/BigBuckBunny.mp4", false);

  for(int i = 0; i < 10; ++i) {
    void* image = nullptr;
    if (dclvlc_check_for_image_update(id, image)) {
      uint8_t* image8t = (uint8_t*)image;
      std::cout << "Average: " << (int)average(image8t) << std::endl;
    }
  }

  dclvlc_release(id);

  dclvlc_free();
  return 0;
}