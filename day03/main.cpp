#include <cstdint>

extern "C" void KernelMain(
  // ブートローダからのフレームバッファの先頭アドレス
  uint64_t frame_buffer_base,
  // ブートローダからのフレームバッファのサイズ
  uint64_t frame_buffer_size
) {
  // frame_buffer_baseをuint8_tのポインタ型に変換
  uint8_t* frame_buffer = reinterpret_cast<uint8_t*>(frame_buffer_base);
  for (uint64_t i = 0; i < frame_buffer_size; ++i) {
    frame_buffer[i] = i % 256;
  }
  while (1) __asm__("hlt");
}