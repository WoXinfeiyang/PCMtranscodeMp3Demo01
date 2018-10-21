package com.fxj.pcmtranscodemp3demo01;

public class LameUtils {
    static{
        System.loadLibrary("LameUtils");
    }

    public static native void init(int audioChannels, int bitRate, int sampleRate);
    public static native void pcmToMp3(String pcmInputfilePath,String mp3OutputfilePath);
    public static native void destory();
}
