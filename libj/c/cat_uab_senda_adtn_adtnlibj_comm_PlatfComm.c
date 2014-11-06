#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include "adtn.h"
#include "cat_uab_senda_adtn_adtnlibj_comm_PlatfComm.h"

/* int adtnSocket(); */
JNIEXPORT jint JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnSocket__
(JNIEnv *env, jobject thisObj)
{
	int s = adtn_socket();

	if (s < 0)
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));

	return s;
}

/* int adtnSocket(String dataPath); */
JNIEXPORT jint JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnSocket__Ljava_lang_String_2
(JNIEnv *env, jobject thisObj, jstring path)
{
	const char *dataPath = (*env)->GetStringUTFChars(env, path, 0);

	int s = adtn_socket(dataPath);

	(*env)->ReleaseStringUTFChars(env, path, dataPath);

	return s;
}

/* void adtnBind(int s, SockAddrT addr); */
JNIEXPORT void JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnBind
(JNIEnv *env, jobject thisObj, jint s, jobject addr)
{

	jclass SockAddrT_cls = (*env)->GetObjectClass(env, addr);

	//Get ID
	jfieldID fid = (*env)->GetFieldID(env, SockAddrT_cls, "id", "Ljava/lang/String;");
	jstring jid = (*env)->GetObjectField(env, addr, fid);
	const char *id = (*env)->GetStringUTFChars(env, jid, 0);

	//Get port
	jfieldID fport = (*env)->GetFieldID(env, SockAddrT_cls, "port", "I");
	const int port = (*env)->GetIntField(env, addr, fport);

	sock_addr_t origin;
	origin.id = strdup(id);
	origin.adtn_port = port;

	int ret = adtn_bind(s, &origin);
	if (ret != 0) {
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));
	}
}

/* void adtnClose(int s); */
JNIEXPORT void JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnClose
(JNIEnv *env, jobject thisObj, jint s)
{
	int r = adtn_close(s);

	if (r != 0)
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));
}

/* void adtnShutdown(int s); */
JNIEXPORT void JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnShutdown
(JNIEnv *env, jobject thisObj, jint s)
{
	int r = adtn_shutdown(s);

	if (r != 0)
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));
}

/* void adtnSetCodeOption(int s, int codeOption, String code); */
JNIEXPORT void JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnSetCodeOption__IILjava_lang_String_2
(JNIEnv *env, jobject thisObj, jint s, jint codeType, jstring codeString)
{

	const char *code = (*env)->GetStringUTFChars(env, codeString, 0);
	int r = adtn_setcodopt(s, codeType, code, 0, 0);

	(*env)->ReleaseStringUTFChars(env, codeString, code);

	if (r != 0)
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));
}

/* void adtnSetCodeOption(int s, int codeOption, String code, int fromFile); */
JNIEXPORT void JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnSetCodeOption__IILjava_lang_String_2I
(JNIEnv *env, jobject thisObj, jint s, jint codeType, jstring codeString, jint isFile)
{
	const char *code = (*env)->GetStringUTFChars(env, codeString, 0);

	int r = adtn_setcodopt(s, codeType, code, isFile, 0);
	(*env)->ReleaseStringUTFChars(env, codeString, code);

	if (r != 0)
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));
}

/* void adtnSetCodeOption(int s, int codeOption, String code, int fromFile, int replace); */
JNIEXPORT void JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnSetCodeOption__IILjava_lang_String_2II
(JNIEnv *env, jobject thisObj, jint s, jint codeType, jstring codeString, jint isFile, jint replace)
{
	const char *code = (*env)->GetStringUTFChars(env, codeString, 0);

	int r = adtn_setcodopt(s, codeType, code, isFile, replace);
	(*env)->ReleaseStringUTFChars(env, codeString, code);

	if (r != 0)
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));
}

/* void adtnRemoveCodeOption(int s, int codeOption); */
JNIEXPORT void JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnRemoveCodeOption
(JNIEnv *env, jobject thisObj, jint s, jint opt)
{
	int r = adtn_rmcodopt(s, opt);

	if (r != 0)
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));
}

/* void adtnSetSocketOption(int s, SockOptT options); */
JNIEXPORT void JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnSetSocketOption
(JNIEnv *env, jobject thisObj, jint s, jobject opt)
{

	jclass SockOptT_cls = (*env)->GetObjectClass(env, opt);

	jfieldID flife = (*env)->GetFieldID(env, SockOptT_cls, "lifetime", "I");
	const int lifetime = (*env)->GetIntField(env, opt, flife);

	jfieldID fproc = (*env)->GetFieldID(env, SockOptT_cls, "procFlags", "I");
	const int procFlags = (*env)->GetIntField(env, opt, fproc);

	jfieldID fblock = (*env)->GetFieldID(env, SockOptT_cls, "blockFlags", "I");
	const int blockFlags = (*env)->GetIntField(env, opt, fblock);

	sock_opt_t sockOptions;

	sockOptions.lifetime = lifetime;
	sockOptions.proc_flags = procFlags;
	sockOptions.block_flags = blockFlags;

	int r = adtn_setsockopt(s, sockOptions);

	if (r != 0)
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));
}

/* int adtnSendTo(int s, SockAddrT addr, byte[] data); */
JNIEXPORT jint JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnSendTo
(JNIEnv *env, jobject thisObj, jint s, jobject addr, jbyteArray data)
{

	/*Conver SockAddrT java class to sock_addr_t struct*/
	jclass SockAddrT_cls = (*env)->GetObjectClass(env, addr);

	//Get ID
	jfieldID fid = (*env)->GetFieldID(env, SockAddrT_cls, "id", "Ljava/lang/String;");
	jstring jid = (*env)->GetObjectField(env, addr, fid);
	const char *id = (*env)->GetStringUTFChars(env, jid, 0);

	//Get port
	jfieldID fport = (*env)->GetFieldID(env, SockAddrT_cls, "port", "I");
	const int port = (*env)->GetIntField(env, addr, fport);

	sock_addr_t destination;
	destination.id = strdup(id);
	destination.adtn_port = port;

	/**/

	//Convert jbyteArray to char *
	jint buffer_l = (*env)->GetArrayLength(env, data);
	jbyte *buffer = (*env)->GetByteArrayElements(env, data, NULL);
	char *buffer_string = malloc(buffer_l + 1);
	memcpy(buffer_string, buffer, buffer_l);
	buffer_string[buffer_l] = '\0';

	int ret = adtn_sendto(s, destination, buffer_string);

	free(buffer_string);
	//Inform VM that buffer is no longer needed
	(*env)->ReleaseByteArrayElements(env, data, buffer, 0);

	if (ret < 0)
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));

	return ret;
}

/* int adtnRecv(int s, byte[] data, int data_len); */
JNIEXPORT jint JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnRecv
(JNIEnv *env, jobject thisObj, jint s, jbyteArray data, jint data_len)
{
	char *buffer = malloc(data_len);
	int ret = adtn_recv(s, buffer, data_len);

	if (ret >= 0) {
		//data = (*env)->NewByteArray(env, data_len);
		(*env)->SetByteArrayRegion(env, data, 0, data_len, buffer);
	}

	free(buffer);

	if (ret < 0)
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));

	return ret;
}

/* int adtnRecvFrom(int s, byte[] data, int data_len, SockAddrT addr); */
JNIEXPORT jint JNICALL Java_cat_uab_senda_adtn_adtnlibj_comm_PlatfComm_adtnRecvFrom
(JNIEnv *env, jobject thisObj, jint s, jbyteArray data, jint data_len, jobject addr)
{
	char *buffer = malloc(data_len);
	sock_addr_t origin;

	int ret = adtn_recvfrom(s, buffer, data_len, &origin);

	if (ret >= 0) {
		//Copy buffer to data
		//data = (*env)->NewByteArray(env, data_len);
		(*env)->SetByteArrayRegion(env, data, 0, data_len, buffer);
		free(buffer);

		//Copy origin to addr
		jclass SockAddrT_cls = (*env)->GetObjectClass(env, addr);

		jfieldID fport = (*env)->GetFieldID(env, SockAddrT_cls, "port", "I");
		(*env)->SetIntField(env, addr, fport, origin.adtn_port);

		jfieldID fid = (*env)->GetFieldID(env, SockAddrT_cls, "id", "Ljava/lang/String;");
		jstring sid = (*env)->NewStringUTF(env, origin.id);
		(*env)->SetObjectField(env, addr, fid, sid);

	}

	if (ret < 0)
		(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/Exception"), strerror(errno));

	return ret;
}