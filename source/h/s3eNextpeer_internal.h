/*
 * Internal header for the s3eNextpeer extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef S3ENEXTPEER_INTERNAL_H
#define S3ENEXTPEER_INTERNAL_H

#include "s3eTypes.h"
#include "s3eNextpeer.h"
#include "s3eNextpeer_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult s3eNextpeerInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult s3eNextpeerInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void s3eNextpeerTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void s3eNextpeerTerminate_platform();
void s3eNextpeerChangeCurrentPlayerAvatarUrl_platform(char* Url);

void s3eNextpeerChangeCurrentPlayerName_platform(char* name);

void s3eNextpeerEnableRankingDisplay_platform(bool enableRankingDisplay);

char* s3eNextpeerGetCurrentPlayerDetails_platform();

char* s3eNextpeerGetNextpeerVersion_platform();

bool s3eNextpeerIsCurrentlyInTournament_platform();

bool s3eNextpeerIsNextpeerInitialised_platform();

bool s3eNextpeerIsNextpeerSupported_platform();

void s3eNextpeerLaunchDashboard_platform();

void s3eNextpeerPushDataToOtherPlayers_platform(void* data, uint32 length);

void s3eNextpeerReportControlledTournamentOverWithScore_platform(uint32 score);

void s3eNextpeerReportForfeitForCurrentTournament_platform();

void s3eNextpeerReportScoreForCurrentTournament_platform(uint32 score);

uint32 s3eNextpeerTimeLeftForTournament_platform();

void s3eNextpeerUnreliablePushDataToOtherPlayers_platform(void* data, uint32 length);


#endif /* !S3ENEXTPEER_INTERNAL_H */