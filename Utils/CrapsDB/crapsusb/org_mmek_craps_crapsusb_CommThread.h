/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_mmek_craps_crapsusb_CommThread */

#ifndef _Included_org_mmek_craps_crapsusb_CommThread
#define _Included_org_mmek_craps_crapsusb_CommThread
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_mmek_craps_crapsusb_CommThread
 * Method:    init
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_mmek_craps_crapsusb_CommThread_init
  (JNIEnv *, jclass);

/*
 * Class:     org_mmek_craps_crapsusb_CommThread
 * Method:    getDeviceAliases
 * Signature: ()Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_org_mmek_craps_crapsusb_CommThread_getDeviceAliases
  (JNIEnv *, jclass);

/*
 * Class:     org_mmek_craps_crapsusb_CommThread
 * Method:    openData
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_org_mmek_craps_crapsusb_CommThread_openData
  (JNIEnv *, jclass, jstring);

/*
 * Class:     org_mmek_craps_crapsusb_CommThread
 * Method:    closeData
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_mmek_craps_crapsusb_CommThread_closeData
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_mmek_craps_crapsusb_CommThread
 * Method:    writeByte
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_org_mmek_craps_crapsusb_CommThread_writeByte
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     org_mmek_craps_crapsusb_CommThread
 * Method:    readByte
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_org_mmek_craps_crapsusb_CommThread_readByte
  (JNIEnv *, jclass, jlong, jint);

#ifdef __cplusplus
}
#endif
#endif
