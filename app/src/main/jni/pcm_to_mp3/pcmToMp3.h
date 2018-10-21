
#ifndef PCMTRANSCODEMP3DEMO01_PCMTOMP3_H
#define PCMTRANSCODEMP3DEMO01_PCMTOMP3_H

#include<app/src/main/jni/lame/include/lame/lame.h>
class PCMtoMp3{
private:
    File* pcmInputfilePath;
    File* mp3OutputfilePath;
    lame_t lameClient;
public:
    PCMtoMp3();
    ~PCMtoMp3();
    int Init(int audioChannels, int bitRate, int sampleRate);
    void PCMtranscodeMp3(const char* pcmFilePath,const char* mp3FilePath);
    void Destory();
};

#endif //PCMTRANSCODEMP3DEMO01_PCMTOMP3_H
