#include <jni.h>


#ifdef __cplusplus
extern "C"
{
#endif

//ffmpeg 的头文件需要使用 extern "C" {} 包围
#include <libavcodec/avcodec.h>

JNIEXPORT jstring JNICALL
Java_com_ks_ndkdemo_MainActivity_getFFmpegConfiguration(JNIEnv *env, jobject job1) {
    return env->NewStringUTF(avcodec_configuration());
}


#ifdef __cplusplus
}
#endif