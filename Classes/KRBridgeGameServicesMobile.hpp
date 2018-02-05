//
//  KRBridgeGameServicesMobile.hpp


#ifndef KRBridgeGameServicesMobile_hpp
#define KRBridgeGameServicesMobile_hpp

#include "PluginSdkboxPlay/PluginSdkboxPlay.h"

#include "cocos2d.h"

class KRBridgeGameServicesMobile : public sdkbox::SdkboxPlayListener
{
public:
    static KRBridgeGameServicesMobile* getInstance();
    
    bool isSignedIn();
    void signin();

    // Cloud
    void saveDataToCloud(const std::string& data);
    void asyncGetDataFromCloud();
protected:
    static KRBridgeGameServicesMobile* instance;
    
    KRBridgeGameServicesMobile();
    ~KRBridgeGameServicesMobile();

    /**
 * Call method invoked when the Plugin connection changes its status.
 * Values are as follows:
 *   + GPS_CONNECTED:       successfully connected.
 *   + GPS_DISCONNECTED:    successfully disconnected.
 *   + GPS_CONNECTION_ERROR:error with google play services connection.
 */
    virtual void onConnectionStatusChanged( int status );

    /**
     * Callback method invoked when an score has been successfully submitted to a leaderboard.
     * It notifies back with the leaderboard_name (not id, see the sdkbox_config.json file) and the
     * subbmited score, as well as whether the score is the daily, weekly, or all time best score.
     * Since Game center can't determine if submitted score is maximum, it will send the max score flags as false.
     */
    virtual void onScoreSubmitted( const std::string& leaderboard_name, long score, bool maxScoreAllTime, bool maxScoreWeek, bool maxScoreToday );

    /**
     * Callback method invoked when the request call to increment an achievement is succeessful and
     * that achievement gets unlocked. This happens when the incremental step count reaches its maximum value.
     * Maximum step count for an incremental achievement is defined in the google play developer console.
     */
    virtual void onIncrementalAchievementUnlocked( const std::string& achievement_name );

    /**
     * Callback method invoked when the request call to increment an achievement is successful.
     * If possible (Google play only) it notifies back with the current achievement step count.
     */
    virtual void onIncrementalAchievementStep( const std::string& achievement_name, double step );

    /**
     * Call method invoked when the request call to unlock a non-incremental achievement is successful.
     * If this is the first time the achievement is unlocked, newUnlocked will be true.
     */
    virtual void onAchievementUnlocked( const std::string& achievement_name, bool newlyUnlocked );

    // Callback for load achievements
    virtual void onAchievementsLoaded( bool reload_forced, const std::string& json_achievements_info );
    
    // Load Game Data callback
    virtual void onSaveGameData(bool success, const std::string& error);
    
    virtual void onLoadGameData(const sdkbox::SavedGameData* savedData, const std::string& error);
};

#endif /* KRBridgeGameServicesMobile_hpp */
