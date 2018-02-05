//
//  KRBridgeGameServicesMobile.cpp

#include "KRBridgeGameServicesMobile.hpp"

using namespace sdkbox;

KRBridgeGameServicesMobile* KRBridgeGameServicesMobile::instance = 0;

KRBridgeGameServicesMobile* KRBridgeGameServicesMobile::getInstance()
{
    if (instance == 0)
    {
        instance = new KRBridgeGameServicesMobile();
    }
    
    return instance;
}

KRBridgeGameServicesMobile::KRBridgeGameServicesMobile()
{
    sdkbox::PluginSdkboxPlay::setListener(this);
    sdkbox::PluginSdkboxPlay::init();
}

KRBridgeGameServicesMobile::~KRBridgeGameServicesMobile()
{

}

bool KRBridgeGameServicesMobile::isSignedIn()
{
    return sdkbox::PluginSdkboxPlay::isSignedIn();
}

void KRBridgeGameServicesMobile::signin()
{
    sdkbox::PluginSdkboxPlay::signin();
}

// Cloud Save
void KRBridgeGameServicesMobile::saveDataToCloud(const std::string& data)
{
    sdkbox::PluginSdkboxPlay::saveGameDataBinary("slot_1", "", 0);
}

void KRBridgeGameServicesMobile::asyncGetDataFromCloud()
{
    sdkbox::PluginSdkboxPlay::loadAllGameData();
}

/**
 * Call method invoked when the Plugin connection changes its status.
 * Values are as follows:
 *   + GPS_CONNECTED:       successfully connected.
 *   + GPS_DISCONNECTED:    successfully disconnected.
 *   + GPS_CONNECTION_ERROR:error with google play services connection.
 */
void KRBridgeGameServicesMobile::onConnectionStatusChanged( int status ) {
    CCLOG("Connection Status: %d", status);
}

// Not used
void KRBridgeGameServicesMobile::onScoreSubmitted( const std::string& leaderboard_name, long score, bool maxScoreAllTime, bool maxScoreWeek, bool maxScoreToday )
{

}

/**
 * Callback method invoked when the request call to increment an achievement is succeessful and
 * that achievement gets unlocked. This happens when the incremental step count reaches its maximum value.
 * Maximum step count for an incremental achievement is defined in the google play developer console.
 */
void KRBridgeGameServicesMobile::onIncrementalAchievementUnlocked( const std::string& achievement_name )
{

}

/**
 * Callback method invoked when the request call to increment an achievement is successful.
 * If possible (Google play only) it notifies back with the current achievement step count.
 */
void KRBridgeGameServicesMobile::onIncrementalAchievementStep( const std::string& achievement_name, double step )
{

}

/**
 * Call method invoked when the request call to unlock a non-incremental achievement is successful.
 * If this is the first time the achievement is unlocked, newUnlocked will be true.
 */
void KRBridgeGameServicesMobile::onAchievementUnlocked( const std::string& achievement_name, bool newlyUnlocked )
{

}

void KRBridgeGameServicesMobile::onAchievementsLoaded ( bool reload_forced , const std::string & json_achievements_info )
{

}


void KRBridgeGameServicesMobile::onSaveGameData(bool success, const std::string& error)
{
    if (error.length() > 0) {
        // failed
        CCLOG("CLOUD SAVE:: game data failed:%s", error.c_str());
    } else {
        //success
        CCLOG("CLOUD SAVE:: save game data");
    }
    
    // Call Game Save to resolve this get data from cloud
}

void KRBridgeGameServicesMobile::onLoadGameData(const SavedGameData* savedData, const std::string& error)
{
    if (error.length() > 0) {
        // failed
        CCLOG("CLOUD SAVE:: game data failed:%s", error.c_str());
    } else {
        CCLOG("CLOUD SAVE:: load game data %s: %s", savedData->name.c_str(), savedData->data);
    }
    
    // Call Game Save to resolve this get data from cloud
}
