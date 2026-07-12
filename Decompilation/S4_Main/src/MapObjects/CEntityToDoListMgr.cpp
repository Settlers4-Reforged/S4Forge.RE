#include "CEntityToDoListMgr.h"

#include "../../generated/CConfigManager/CConfigManagerPtr.h"
#include "CBB/CBBSupport.h"
#include "CConfigManager/CConfigManager.h"
#include "CEntityTask.h"
#include "Debug/CTrace.h"
#include "Defines/Job.h"
#include "Defines/Races.h"
#include "Defines/Settlers.h"
#include "Main/CDefineTranslator.h"
#include "XmlParser/AdvXMLParser.h"

// Definitions for class CEntityToDoListMgr

#define LOAD_INT(element, name, index) atoi(element(name, index).GetValue().c_str())
#define LOAD_CHILD_INT(element, base, child, index) atoi(element(base, 0)(child, index).GetValue().c_str())

// address=[0x154c610]
// Decompiled from CEntityToDoListMgr *__thiscall CEntityToDoListMgr::CEntityToDoListMgr(CEntityToDoListMgr *this)
CEntityToDoListMgr::CEntityToDoListMgr(void) {
    for(int i = RACE_FIRST; i < RACE_MAX; ++i) {
        for(int j = 0; j < JOB_MAX; ++j) {
            this->m_vSettlerJobsList[i][j] = nullptr;
        }
    }

    for(int i = RACE_FIRST; i < RACE_MAX; ++i) {
        for(int k = SETTLER_CARRIER; k < SETTLER_MAX; ++k) {
            int iFirstJobId = g_pGfxManager->GetSettlerFirstJob(i, k);
            if(!iFirstJobId || this->m_vSettlerJobsList[0][k]) {
                this->m_vSettlerJobsList[i][k] = this->m_vSettlerJobsList[0][k];
            } else {
                std::list<CEntityTask> *taskList = new std::list<CEntityTask>();
                this->m_vSettlerJobsList[i][k] = taskList;
                int frames = g_pGfxManager->GetSettlerJobFrameCount(i, iFirstJobId, 2u);

                BB_ASSERT(frames > 0)
                CEntityTask task(17, iFirstJobId, 0, 0, 1, frames, -1, 1, 1, 0, 0, 0, 0);
                taskList->push_back(task);
            }
        }
    }

    int iJobListAfterSettlerIter = SETTLER_MAX;
    for(int m = 1; m < 66; ++m) {
        for(int i = 0; i < RACE_MAX; ++i) {
            int iFirstJobId = g_pGfxManager->GetSettlerFirstJob(i, m);
            if(!iFirstJobId || this->m_vSettlerJobsList[0][iJobListAfterSettlerIter]) {
                this->m_vSettlerJobsList[i][iJobListAfterSettlerIter] = this->m_vSettlerJobsList[0][iJobListAfterSettlerIter];
            } else {
                std::list<CEntityTask> *taskList = new std::list<CEntityTask>();
                this->m_vSettlerJobsList[i][iJobListAfterSettlerIter] = taskList;
                taskList->clear(); // NOTE: why are we clearing an empty list?

                int iFrameCount = g_pGfxManager->GetSettlerJobFrameCount(i, iFirstJobId, 2u);
                CEntityTask task1(10, iFirstJobId, 0, 0, -1, iFrameCount, 1, 1, 1, 0, 0, 0, 0);
                taskList->push_back(task1);
                CEntityTask task2(24, iFirstJobId, 0, 0, -1, iFrameCount, 1, 0, 1, 0, 0, 0, 0);
                taskList->push_back(task2);
            }
        }

        ++iJobListAfterSettlerIter;
    }

    using namespace AdvXMLParser;
    long iXmlFileSize = 0;
    char *pXmlFile = Parser::OpenXMLFile(L"GameData\\JobInfo.xml", iXmlFileSize);

    std::unique_ptr<Document> pInfoDoc(Parser().Parse(pXmlFile, iXmlFileSize));

    CDefineTranslator *pDefineTranslator = g_pDefineTranslator;

    const Element &rInfoRoot = pInfoDoc->GetRoot();
    ConstIterator<Element> pInfoRaceIter = rInfoRoot.Begin();
    ConstIterator<Element> pInfoEnd = rInfoRoot.End();

    while(pInfoRaceIter < pInfoEnd) {
        const Element &rJobElement = *pInfoRaceIter;
        const Attribute &rIdAttr = rJobElement["id"];
        std::string sIdValue = rIdAttr.GetValue();

        int iRace = pDefineTranslator->GetValueOfDefine(sIdValue);
        if(iRace == -1) {
            CTrace::Print("This race define: %s used in JobInfo.xml but isn't part of S4_Defines.h", sIdValue.c_str());
        }

        ConstIterator<Element> pJobIter = rJobElement.Begin();
        ConstIterator<Element> pJobEnd = rJobElement.End();

        while(pJobIter < pJobEnd) {
            const Element &rJobInfoElement = *pJobIter;
            std::string sJobIdValue = rJobInfoElement["id"].GetValue();

            int iJobListIdx = pDefineTranslator->GetValueOfDefine(sJobIdValue);
            if(iJobListIdx == -1) {
                CTrace::Print("This job define: %s used in JobInfo.xml but isn't part of S4_AnimListDefines.h", sJobIdValue.c_str());
            }
            BB_ASSERT(iJobListIdx != -1)

            ConstIterator<Element> pNodeIter = rJobElement.Begin();
            ConstIterator<Element> pNodeEnd = rJobElement.End();
            while(pNodeIter < pNodeEnd) {
                const Element &rNodeElement = *pNodeIter;
                std::string sNodeJobPartValue = rNodeElement["jobPart"].GetValue();

                int iJobNr = pDefineTranslator->GetValueOfDefine(sNodeJobPartValue);
                if(iJobNr == -1) {
                    CTrace::Print("This job define: %s used in JobInfo.xml but isn't part of SettlerDefines.h", sNodeJobPartValue.c_str());
                }
                BB_ASSERT(iJobNr != -1)

                int iX = LOAD_INT(rNodeElement, "x", 0);
                int iY = LOAD_INT(rNodeElement, "y", 0);
                int iTask = pDefineTranslator->GetValueOfDefine(rNodeElement["task"].GetValue());
                int iDir = LOAD_INT(rNodeElement, "dir", 0);
                if(iDir == -1)
                    iDir = 0;

                int iTaskFrameCount = g_pGfxManager->GetSettlerJobFrameCount(iRace, iJobNr, iDir);
                if(iTaskFrameCount == 1) {
                    BB_REPORTF("WARNING: There is a problem in job %s of race %s with job part %s!", sJobIdValue.c_str(), sIdValue.c_str(), sNodeJobPartValue.c_str());
                }

                int iDuration = LOAD_INT(rNodeElement, "duration", 0);
                BB_ASSERT(iDuration < 128)
                if(!iDuration)
                    iDuration = iTaskFrameCount;

                int iEntity = pDefineTranslator->GetValueOfDefine(rNodeElement["entity"].GetValue());
                if(iEntity == -1)
                    iEntity = 0;

                // std::string sTask = rNodeElement["task"].GetValue();
                // int iTask = pDefineTranslator->GetValueOfDefine(sTask);
                // NOTE: this is done twice in the og...
                int iTrigger = pDefineTranslator->GetValueOfDefine(rNodeElement["trigger"].GetValue());

                if(!this->m_vSettlerJobsList[iRace][iJobListIdx]) {
                    std::list<CEntityTask> *taskList = new std::list<CEntityTask>();
                    this->m_vSettlerJobsList[iRace][iJobListIdx] = taskList;
                    this->m_vSettlerJobsList[iRace][iJobListIdx]->clear(); // NOTE: again, a clear on a new list...
                }

                bool bVisible = LOAD_INT(rNodeElement, "visible", 0) != 0;
                bool bForward = LOAD_INT(rNodeElement, "forward", 0) != 0;

                this->m_vSettlerJobsList[iRace][iJobListIdx]->emplace_back(iTask, iJobNr, iX, iY, iDuration, iTaskFrameCount, iDir, bForward, bVisible, iEntity, 0, 0, iTrigger);

                ++pNodeIter;
            }

            ++pJobIter;
        }

        ++pInfoRaceIter;
    }

    delete[] pXmlFile;

    memset(m_vJobSoundInfo, 0, sizeof(m_vJobSoundInfo));
    static_assert(sizeof(m_vJobSoundInfo) == 0x0B78, "must match with original binary");

    pXmlFile = Parser::OpenXMLFile(L"GameData\\JobSoundList.xml", iXmlFileSize);
    std::unique_ptr<Document> pSoundDoc(Parser().Parse(pXmlFile, iXmlFileSize));

    const Element &rSoundRoot = pSoundDoc->GetRoot();
    ConstIterator<Element> pSoundIter = rSoundRoot.Begin();
    ConstIterator<Element> pSoundEnd = rSoundRoot.End();

    while(pSoundIter < pSoundEnd) {
        const Element &rNodeElement = *pSoundIter;
        int index = CConfigManagerPtr::GetInstance()->GetDefineValue(rNodeElement["id"].GetValue().c_str());
        BB_ASSERT((index > 0) && (index < SIV_MAX_JOB))

        SJobSoundInfo &rSoundInfo = m_vJobSoundInfo[index];
        rSoundInfo.m_iId = LOAD_CHILD_INT(rNodeElement, "sound", "id", 0);
        if(rSoundInfo.m_iId == -1)
            rSoundInfo.m_iId = 0;
        rSoundInfo.m_iFrame = LOAD_CHILD_INT(rNodeElement, "sound", "frame", 0);
        rSoundInfo.m_iRandom = LOAD_CHILD_INT(rNodeElement, "sound", "random", 0);
        if(!rSoundInfo.m_iRandom)
            rSoundInfo.m_iRandom = 100;

        ++pSoundIter;
    }

    delete[] pXmlFile;
}

// address=[0x154e090]
// Decompiled from void __thiscall CEntityToDoListMgr::~CEntityToDoListMgr(CEntityToDoListMgr *this)
CEntityToDoListMgr::~CEntityToDoListMgr(void) {
    for(int i = RACE_MAX - 1; i >= 0; --i) {
        for(int j = 0; j < JOB_MAX; ++j) {
            if(this->m_vSettlerJobsList[i][j] && this->m_vSettlerJobsList[i][j] != this->m_vSettlerJobsList[0][j]) {
                this->m_vSettlerJobsList[i][j]->clear(); // NOTE: clears, before check if not null...
                if(this->m_vSettlerJobsList[i][j])
                    delete this->m_vSettlerJobsList[i][j];
            }
        }
    }
    for(int k = 0; k < JOB_MAX; ++k) {
        if(this->m_vSettlerJobsList[0][k]) {
            this->m_vSettlerJobsList[0][k]->clear();
            if(this->m_vSettlerJobsList[0][k])
                delete this->m_vSettlerJobsList[0][k];
        }
    }
}

// address=[0x154e220]
// Decompiled from std::list *__thiscall CEntityToDoListMgr::SettlerJobList(  CEntityToDoListMgr *this,  unsigned int _iRace,  unsigned int _iJob)
class std::list<class CEntityTask, class std::allocator<class CEntityTask>> *CEntityToDoListMgr::SettlerJobList(int _iRace, int _iJob) {
    BB_ASSERT(_iRace >= 0 && _iRace < RACE_MAX)
    BB_ASSERT(_iJob >= 0 && _iJob < JOB_MAX)
    return this->m_vSettlerJobsList[_iRace][_iJob];
}

// address=[0x154e2a0]
// Decompiled from void __cdecl CEntityToDoListMgr::GetJobSoundInfo(int a1, struct SJobSoundInfo *a2)
void __cdecl CEntityToDoListMgr::GetJobSoundInfo(int _iJobId, struct SJobSoundInfo &rJobSoundInfo) {
    BB_ASSERT(0 < _iJobId && _iJobId < SIV_MAX_JOB)

    rJobSoundInfo.m_iId = m_vJobSoundInfo[_iJobId].m_iId;
    rJobSoundInfo.m_iFrame = m_vJobSoundInfo[_iJobId].m_iFrame;
    rJobSoundInfo.m_iRandom = m_vJobSoundInfo[_iJobId].m_iRandom;
}

// address=[0x40fe5b8]
// [Decompilation failed for static struct SJobSoundInfo * CEntityToDoListMgr::m_vJobSoundInfo]
