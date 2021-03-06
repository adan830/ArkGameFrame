/*****************************************************************************
// * This source file is part of ArkGameFrame                                *
// * For the latest info, see https://github.com/ArkGame                     *
// *                                                                         *
// * Copyright(c) 2013 - 2017 ArkGame authors.                               *
// *                                                                         *
// * Licensed under the Apache License, Version 2.0 (the "License");         *
// * you may not use this file except in compliance with the License.        *
// * You may obtain a copy of the License at                                 *
// *                                                                         *
// *     http://www.apache.org/licenses/LICENSE-2.0                          *
// *                                                                         *
// * Unless required by applicable law or agreed to in writing, software     *
// * distributed under the License is distributed on an "AS IS" BASIS,       *
// * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
// * See the License for the specific language governing permissions and     *
// * limitations under the License.                                          *
// *                                                                         *
// *                                                                         *
// * @file  	AFCObject.cpp                                              *
// * @author    Ark Game Tech                                                *
// * @date      2015-12-15                                                   *
// * @brief     AFCObject                                                  *
*****************************************************************************/
#include "AFCObject.h"
#include "AFCRecordManager.h"
#include "AFCHeartBeatManager.h"
#include "AFCPropertyMgr.h"
#include "AFCEventManager.h"

AFCObject::AFCObject(const AFGUID& self, AFIPluginManager* pLuginManager)
    : AFIObject(self)
{
    mSelf = self;
    m_pPluginManager = pLuginManager;

    m_pPropertyManager = ARK_SHARE_PTR<AFCPropertyMgr>(ARK_NEW AFCPropertyMgr(mSelf));
    m_pRecordManager = ARK_SHARE_PTR<AFCRecordManager>(ARK_NEW AFCRecordManager(mSelf));
    m_pHeartBeatManager = ARK_SHARE_PTR<AFCHeartBeatManager>(ARK_NEW AFCHeartBeatManager(mSelf));
    m_pEventManager = ARK_SHARE_PTR<AFIEventManager>(ARK_NEW AFCEventManager(mSelf));
}

AFCObject::~AFCObject()
{

}

bool AFCObject::Init()
{
    return true;
}

bool AFCObject::Shut()
{
    return true;
}

bool AFCObject::Execute()
{
    GetHeartBeatManager()->Execute();
    GetEventManager()->Execute();

    return true;
}

bool AFCObject::AddHeartBeat(const std::string& strHeartBeatName, const HEART_BEAT_FUNCTOR_PTR& cb, const int64_t nTime, const int nCount)
{
    return GetHeartBeatManager()->AddHeartBeat(mSelf, strHeartBeatName, cb, nTime, nCount);
}

bool AFCObject::FindHeartBeat(const std::string& strHeartBeatName)
{
    return GetHeartBeatManager()->Exist(strHeartBeatName);
}

bool AFCObject::RemoveHeartBeat(const std::string& strHeartBeatName)
{
    return GetHeartBeatManager()->RemoveHeartBeat(strHeartBeatName);
}

bool AFCObject::AddRecordCallBack(const std::string& strRecordName, const RECORD_EVENT_FUNCTOR_PTR& cb)
{
    ARK_SHARE_PTR<AFIRecord> pRecord = GetRecordManager()->GetElement(strRecordName);
    if(nullptr != pRecord)
    {
        pRecord->AddRecordHook(cb);

        return true;
    }

    return false;
}

bool AFCObject::AddPropertyCallBack(const std::string& strCriticalName, const PROPERTY_EVENT_FUNCTOR_PTR& cb)
{
    return GetPropertyManager()->RegisterCallback(strCriticalName, cb);
}

bool AFCObject::FindProperty(const std::string& strPropertyName)
{
    return (NULL != GetPropertyManager()->GetProperty(strPropertyName.c_str()));
}

bool AFCObject::SetPropertyBool(const std::string& strPropertyName, const bool value)
{
    return GetPropertyManager()->SetPropertyBool(strPropertyName.c_str(), value);
}

bool AFCObject::SetPropertyInt(const std::string& strPropertyName, const int32_t value)
{
    return GetPropertyManager()->SetPropertyInt(strPropertyName.c_str(), value);
}

bool AFCObject::SetPropertyInt64(const std::string& strPropertyName, const int64_t value)
{
    return GetPropertyManager()->SetPropertyInt64(strPropertyName.c_str(), value);
}

bool AFCObject::SetPropertyFloat(const std::string& strPropertyName, const float value)
{
    return GetPropertyManager()->SetPropertyFloat(strPropertyName.c_str(), value);
}

bool AFCObject::SetPropertyDouble(const std::string& strPropertyName, const double value)
{
    return GetPropertyManager()->SetPropertyDouble(strPropertyName.c_str(), value);
}

bool AFCObject::SetPropertyString(const std::string& strPropertyName, const std::string& value)
{
    return GetPropertyManager()->SetPropertyString(strPropertyName.c_str(), value);
}

bool AFCObject::SetPropertyObject(const std::string& strPropertyName, const AFGUID& value)
{
    return GetPropertyManager()->SetPropertyObject(strPropertyName.c_str(), value);
}

bool AFCObject::GetPropertyBool(const std::string& strPropertyName)
{
    return GetPropertyManager()->GetPropertyBool(strPropertyName.c_str());
}

int32_t AFCObject::GetPropertyInt(const std::string& strPropertyName)
{
    return GetPropertyManager()->GetPropertyInt(strPropertyName.c_str());
}

int64_t AFCObject::GetPropertyInt64(const std::string& strPropertyName)
{
    return GetPropertyManager()->GetPropertyInt64(strPropertyName.c_str());
}

float AFCObject::GetPropertyFloat(const std::string& strPropertyName)
{
    return GetPropertyManager()->GetPropertyFloat(strPropertyName.c_str());
}

double AFCObject::GetPropertyDouble(const std::string& strPropertyName)
{
    return GetPropertyManager()->GetPropertyDouble(strPropertyName.c_str());
}

const char* AFCObject::GetPropertyString(const std::string& strPropertyName)
{
    return GetPropertyManager()->GetPropertyString(strPropertyName.c_str());
}

const AFGUID& AFCObject::GetPropertyObject(const std::string& strPropertyName)
{
    return GetPropertyManager()->GetPropertyObject(strPropertyName.c_str());
}

bool AFCObject::FindRecord(const std::string& strRecordName)
{
    ARK_SHARE_PTR<AFIRecord> pRecord = GetRecordManager()->GetElement(strRecordName);
    return (nullptr != pRecord);
}

bool AFCObject::SetRecordBool(const std::string& strRecordName, const int nRow, const int nCol, const bool value)
{
    return GetRecordManager()->SetRecordBool(strRecordName, nRow, nCol, value);
}

bool AFCObject::SetRecordBool(const std::string& strRecordName, const int nRow, const std::string& strColTag, const bool value)
{
    return GetRecordManager()->SetRecordBool(strRecordName, nRow, strColTag, value);
}

bool AFCObject::SetRecordInt(const std::string& strRecordName, const int nRow, const int nCol, const int32_t value)
{
    return GetRecordManager()->SetRecordInt(strRecordName, nRow, nCol, value);
}

bool AFCObject::SetRecordInt(const std::string& strRecordName, const int nRow, const std::string& strColTag, const int32_t value)
{
    return GetRecordManager()->SetRecordInt(strRecordName, nRow, strColTag, value);
}

bool AFCObject::SetRecordInt64(const std::string& strRecordName, const int nRow, const int nCol, const int64_t value)
{
    return GetRecordManager()->SetRecordInt64(strRecordName, nRow, nCol, value);
}

bool AFCObject::SetRecordInt64(const std::string& strRecordName, const int nRow, const std::string& strColTag, const int64_t value)
{
    return GetRecordManager()->SetRecordInt64(strRecordName, nRow, strColTag, value);
}

bool AFCObject::SetRecordFloat(const std::string& strRecordName, const int nRow, const int nCol, const float value)
{
    return GetRecordManager()->SetRecordFloat(strRecordName, nRow, nCol, value);
}

bool AFCObject::SetRecordFloat(const std::string& strRecordName, const int nRow, const std::string& strColTag, const float value)
{
    return GetRecordManager()->SetRecordFloat(strRecordName, nRow, strColTag, value);
}

bool AFCObject::SetRecordDouble(const std::string& strRecordName, const int nRow, const int nCol, const double value)
{
    return GetRecordManager()->SetRecordDouble(strRecordName, nRow, nCol, value);
}

bool AFCObject::SetRecordDouble(const std::string& strRecordName, const int nRow, const std::string& strColTag, const double value)
{
    return GetRecordManager()->SetRecordDouble(strRecordName, nRow, strColTag, value);
}

bool AFCObject::SetRecordString(const std::string& strRecordName, const int nRow, const int nCol, const std::string& value)
{
    return GetRecordManager()->SetRecordString(strRecordName, nRow, nCol, value);
}

bool AFCObject::SetRecordString(const std::string& strRecordName, const int nRow, const std::string& strColTag, const std::string& value)
{
    return GetRecordManager()->SetRecordString(strRecordName, nRow, strColTag, value);
}

bool AFCObject::SetRecordObject(const std::string & strRecordName, const int nRow, const int nCol, const AFGUID & value)
{
    return GetRecordManager()->SetRecordObject(strRecordName, nRow, nCol, value);
}

bool AFCObject::SetRecordObject(const std::string & strRecordName, const int nRow, const std::string & strColTag, const AFGUID & value)
{
    return GetRecordManager()->SetRecordObject(strRecordName, nRow, strColTag, value);
}

bool AFCObject::GetRecordBool(const std::string& strRecordName, const int nRow, const int nCol)
{
    return GetRecordManager()->GetRecordBool(strRecordName, nRow, nCol);
}

bool AFCObject::GetRecordBool(const std::string& strRecordName, const int nRow, const std::string& strColTag)
{
    return GetRecordManager()->GetRecordBool(strRecordName, nRow, strColTag);
}

int32_t AFCObject::GetRecordInt(const std::string & strRecordName, const int nRow, const int nCol)
{
    return GetRecordManager()->GetRecordInt(strRecordName, nRow, nCol);
}

int32_t AFCObject::GetRecordInt(const std::string & strRecordName, const int nRow, const std::string & strColTag)
{
    return GetRecordManager()->GetRecordInt(strRecordName, nRow, strColTag);
}

int64_t AFCObject::GetRecordInt64(const std::string& strRecordName, const int nRow, const int nCol)
{
    return GetRecordManager()->GetRecordInt64(strRecordName, nRow, nCol);
}

int64_t AFCObject::GetRecordInt64(const std::string& strRecordName, const int nRow, const std::string& strColTag)
{
    return GetRecordManager()->GetRecordInt64(strRecordName, nRow, strColTag);
}

float AFCObject::GetRecordFloat(const std::string& strRecordName, const int nRow, const int nCol)
{
    return GetRecordManager()->GetRecordFloat(strRecordName, nRow, nCol);
}

float AFCObject::GetRecordFloat(const std::string& strRecordName, const int nRow, const std::string& strColTag)
{
    return GetRecordManager()->GetRecordFloat(strRecordName, nRow, strColTag);
}

double AFCObject::GetRecordDouble(const std::string & strRecordName, const int nRow, const int nCol)
{
    return GetRecordManager()->GetRecordDouble(strRecordName, nRow, nCol);
}

double AFCObject::GetRecordDouble(const std::string & strRecordName, const int nRow, const std::string & strColTag)
{
    return GetRecordManager()->GetRecordDouble(strRecordName, nRow, strColTag);
}

const std::string& AFCObject::GetRecordString(const std::string & strRecordName, const int nRow, const int nCol)
{
    return GetRecordManager()->GetRecordString(strRecordName, nRow, nCol);
}

const std::string& AFCObject::GetRecordString(const std::string & strRecordName, const int nRow, const std::string & strColTag)
{
    return GetRecordManager()->GetRecordString(strRecordName, nRow, strColTag);
}

const AFGUID& AFCObject::GetRecordObject(const std::string & strRecordName, const int nRow, const int nCol)
{
    return GetRecordManager()->GetRecordObject(strRecordName, nRow, nCol);
}

const AFGUID& AFCObject::GetRecordObject(const std::string & strRecordName, const int nRow, const std::string & strColTag)
{
    return GetRecordManager()->GetRecordObject(strRecordName, nRow, strColTag);
}

ARK_SHARE_PTR<AFIRecordManager> AFCObject::GetRecordManager()
{
    return m_pRecordManager;
}

ARK_SHARE_PTR<AFIHeartBeatManager> AFCObject::GetHeartBeatManager()
{
    return m_pHeartBeatManager;
}

ARK_SHARE_PTR<AFIPropertyMgr> AFCObject::GetPropertyManager()
{
    return m_pPropertyManager;
}

const AFGUID& AFCObject::Self()
{
    return mSelf;
}

ARK_SHARE_PTR<AFIEventManager> AFCObject::GetEventManager()
{
    return m_pEventManager;
}

