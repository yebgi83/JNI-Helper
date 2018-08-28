#pragma once
#include "../JNIArrayList.h"
#include "../JNIString.h"

using namespace std;

class JNIStringArrayList : public JNIArrayList<jstring>
{
public:
	JNIStringArrayList(JNIEnv *pEnv, jobjectArray javaObject) : JNIArrayList(pEnv, javaObject)
	{
		return;
	}

	void Add(string value)
	{
		JNIArrayList<jstring>::Add(JNIString::ToJavaString(GetEnv(), value));
	}

	string Get(int index)
	{
		return JNIString(GetEnv(), JNIArrayList<jstring>::Get(index)).GetString();
	}

	vector<string> ToVector()
	{
		vector<string> result;
		{
			result.reserve(GetSize());
		}

		for (int index = 0; index < static_cast<int>(result.size()); index++) {
			result.push_back(Get(index));
		}

		return result;
	}
};