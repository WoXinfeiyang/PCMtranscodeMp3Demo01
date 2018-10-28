#include"pcmToMp3.h"
PCMtoMp3::PCMtoMp3(){
}

PCMtoMp3::~PCMtoMp3(){
}

PCMtoMp3::void Init(int audioChannels, int bitRate, int sampleRate){
    lameClient=lame_init();
    lame_set_in_samplerate(lameClient, sampleRate);
    lame_set_out_samplerate(lameClient, sampleRate);
    lame_set_num_channels(lameClient, audioChannels);
    lame_set_brate(lameClient, bitRate / 1000);
    lame_init_params(lameClient);
}


PCMtoMp3::void PCMtranscodeMp3(const char* pcmFilePath,const char* mp3FilePath){
    pcmInputfilePath=fopen(pcmFilePath,"rb");
    if(pcmInputfilePath){
        mp3OutputfilePath=fopen(mp3FilePath, "wb");
        if(mp3OutputfilePath){
            int bufferSize = 1024 * 256;
            short* buffer = new short[bufferSize / 2];
            short* leftBuffer = new short[bufferSize / 4];
            short* rightBuffer = new short[bufferSize / 4];
            uint8_t* mp3_buffer = new uint8_t[bufferSize];
            int readBufferSize = 0;
            while ((readBufferSize = fread(buffer, 2, bufferSize / 2, pcmInputfilePath)) > 0) {
                for (int i = 0; i < readBufferSize; i++) {
                    if (i % 2 == 0) {
                        leftBuffer[i / 2] = buffer[i];
                    } else {
                        rightBuffer[i / 2] = buffer[i];
                    }
                }
                int wroteSize = lame_encode_buffer(lameClient, (short int *) leftBuffer, (short int *) rightBuffer, readBufferSize / 2, mp3_buffer, bufferSize);
                fwrite(mp3_buffer, 1, wroteSize, mp3OutputfilePath);
            }
        }
    }
}

PCMtoMp3::void Destory(){

}
