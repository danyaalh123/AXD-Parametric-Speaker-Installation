import pyaudio
import numpy as np
import serial
import time
from scipy.signal import resample_poly

# User-configurable settings
DEVICE_INDEX = 0              # integer device index for your input
SERIAL_PORT = ""              # e.g. "COM3" on Windows
BAUD_RATE = 1000000
TARGET_SR = 8000              # 8 kHz target sample rate
CHUNK_SIZE = 1024             # frames per chunk
CHANNELS = 1                  # 1 channel (mono)
AUDIO_FORMAT = pyaudio.paInt16
DEVICE_SR = 44100             # your mic capture rate (44.1 kHz typical)
VOLUME_SCALE = 4.0            # volume multiplier (adjust as needed)

def downsample_and_8bit(data, in_sr, out_sr):
    """
    data: 1D NumPy array of int16 audio samples
    in_sr: input sample rate (e.g. 44100)
    out_sr: output sample rate (e.g. 8000)

    Returns a NumPy array of uint8 samples (0..255) at out_sr,
    using a polyphase filter to reduce aliasing.
    """
    # Convert int16 -> float32 in [-1, +1]
    float_data = data.astype(np.float32) / 32768.0

    # Use resample_poly for better lowpass filtering + resampling
    # (up=out_sr, down=in_sr) => from in_sr -> out_sr
    resampled = resample_poly(float_data, out_sr, in_sr)

    # Apply volume scaling
    resampled *= VOLUME_SCALE
    np.clip(resampled, -1.0, 1.0, out=resampled)

    # Map [-1..1] => [0..255]
    out_8bit = ((resampled + 1.0) * 127.5).astype(np.uint8)

    return out_8bit

def main():
    # 1) Initialize PyAudio
    p = pyaudio.PyAudio()

    # 2) Open audio stream from the chosen device
    stream = p.open(format=AUDIO_FORMAT,
                    channels=CHANNELS,
                    rate=DEVICE_SR,
                    input=True,
                    frames_per_buffer=CHUNK_SIZE,
                    input_device_index=DEVICE_INDEX)

    # 3) Open serial
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE)
    time.sleep(2)  # brief pause for Arduino reset

    print("Starting audio capture... Press Ctrl+C to stop.")

    try:
        while True:
            # Read a chunk of int16 data from the mic
            audio_data = stream.read(CHUNK_SIZE, exception_on_overflow=False)
            
            # Convert bytes -> NumPy int16 array
            samples = np.frombuffer(audio_data, dtype=np.int16)

            # Downsample + convert to 8-bit
            out_samples = downsample_and_8bit(samples, DEVICE_SR, TARGET_SR)

            # Write the chunk to serial
            ser.write(out_samples.tobytes())


    except KeyboardInterrupt:
        print("Stopping...")

    # Cleanup
    stream.stop_stream()
    stream.close()
    p.terminate()
    ser.close()

if __name__ == "__main__":
    main()
