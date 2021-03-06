/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "s3eNextpeer_autodefs.h"
#include "s3eEdk.h"
#include "s3eNextpeer.h"
//Declarations of Init and Term functions
extern s3eResult s3eNextpeerInit();
extern void s3eNextpeerTerminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static void s3eNextpeerLaunchDashboard_wrap()
{
    IwTrace(NEXTPEER_VERBOSE, ("calling s3eNextpeer func on main thread: s3eNextpeerLaunchDashboard"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eNextpeerLaunchDashboard, 0);
}

#define s3eNextpeerLaunchDashboard s3eNextpeerLaunchDashboard_wrap

#endif

s3eResult s3eNextpeerRegister(s3eNextpeerCallback cbid, s3eCallback fn, void* pData)
{
    return s3eEdkCallbacksRegister(S3E_EXT_NEXTPEER_HASH, S3E_NEXTPEER_CALLBACK_MAX, cbid, fn, pData, 0);
};

s3eResult s3eNextpeerUnRegister(s3eNextpeerCallback cbid, s3eCallback fn)
{
    return s3eEdkCallbacksUnRegister(S3E_EXT_NEXTPEER_HASH, S3E_NEXTPEER_CALLBACK_MAX, cbid, fn);
}

void s3eNextpeerRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[15];
    funcPtrs[0] = (void*)s3eNextpeerRegister;
    funcPtrs[1] = (void*)s3eNextpeerUnRegister;
    funcPtrs[2] = (void*)s3eNextpeerChangeCurrentPlayerAvatarUrl;
    funcPtrs[3] = (void*)s3eNextpeerChangeCurrentPlayerName;
    funcPtrs[4] = (void*)s3eNextpeerEnableRankingDisplay;
    funcPtrs[5] = (void*)s3eNextpeerGetCurrentPlayerDetails;
    funcPtrs[6] = (void*)s3eNextpeerGetNextpeerVersion;
    funcPtrs[7] = (void*)s3eNextpeerIsCurrentlyInTournament;
    funcPtrs[8] = (void*)s3eNextpeerLaunchDashboard;
    funcPtrs[9] = (void*)s3eNextpeerPushDataToOtherPlayers;
    funcPtrs[10] = (void*)s3eNextpeerReportControlledTournamentOverWithScore;
    funcPtrs[11] = (void*)s3eNextpeerReportForfeitForCurrentTournament;
    funcPtrs[12] = (void*)s3eNextpeerReportScoreForCurrentTournament;
    funcPtrs[13] = (void*)s3eNextpeerTimeLeftForTournament;
    funcPtrs[14] = (void*)s3eNextpeerUnreliablePushDataToOtherPlayers;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[15] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("s3eNextpeer", funcPtrs, sizeof(funcPtrs), flags, s3eNextpeerInit, s3eNextpeerTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int s3eNextpeerStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&s3eNextpeerRegisterExt;
    return 0;
}

int g_s3eNextpeerVal = s3eNextpeerStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    s3eNextpeerRegisterExt();
}
#endif

#endif
