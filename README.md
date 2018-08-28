# JNI Helper
C++ Helper classes for JNI

Example:
```c++
#include <jni/JNIArray.h>
#include <jni/JNIArrayTypes.h>
#include <jni/JNIClass.h>
#include <jni/JNIField.h>
#include <jni/JNIFieldTypes.h>
#include <jni/JNIString.h>
#include <jni/JNIThrowable.h>
#include <jni/JNIThrowableTypes.h>

#define JNI_FUNC_NAME(name) Java_com_yebgi83_jni ## _ ## name

JNIEXPORT jlong JNICALL JNI_FUNC_NAME(initialize)(JNIEnv *env, jclass thisObj, jstring jniLabel, jstring jniConfigPath)
{
	try {
		string message;

		string label = JNIString(env, jniLabel).GetString();
		string configPath = JNIString(env, jniConfigPath).GetString();
		
		jlong result = reinterpret_cast<jlong>(InitContext(message, label, configPath));
		
		if (result) {
			return result;
		}
		else if (!message.empty()) {
			JNIRuntimeException(env, message).Throw();
		}
	} catch (const string& error) {
		JNIRuntimeException(env, error).Throw();
	}

	return -1;
}
```
