#include <jni.h>
#include <string.h>

JNIEXPORT jstring JNICALL Java_B_1recs_returnHello(JNIEnv *env, jobject obj,
                                                   jstring string)
{
    const char *str = (*env)->GetStringUTFChars(env, string, 0);
    char cap[128];
    char fullstring[256];
    strcpy(cap, str);

    snprintf(fullstring, 250, "Hello from %s", cap);

    (*env)->ReleaseStringUTFChars(env, string, str);

    return (*env)->NewStringUTF(env, fullstring);
}
