#pragma once

#include "frame_buffer_config.hpp"

struct PixelColor {
  uint8_t r, g, b;
};

class PixelWriter {
  public:
    // コンストラクタ（メモリ上に構築）
    PixelWriter(const FrameBufferConfig& config) : config_{config} {}
    // デストラクタ（インスタンスを破棄）
    virtual ~PixelWriter() = default;
    // インタフェースを指定
    virtual void Write(int x, int y, const PixelColor& c) = 0;

  protected:
    uint8_t* PixelAt(int x, int y) {
      return config_.frame_buffer + 4 * (config_.pixels_per_scan_line *y + x);
    };

  private:
    const FrameBufferConfig& config_;
};

class RGBResv8BitPerColorPixelWriter : public PixelWriter {
  public:
    using PixelWriter::PixelWriter;
  
  virtual void Write(int x, int y, const PixelColor& c) override;
};

class BGRResv8BitPerColorPixelWriter : public PixelWriter {
  public:
    using PixelWriter::PixelWriter;

  virtual void Write(int x, int y, const PixelColor& c) override;
};
