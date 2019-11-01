#include "mu_test.h"
#include "MusicPlayer.h"
#include "Singleton.h"
#include <string>

UNIT(MusicPlayer_one_player)

    MusicPlayerData mpd1={"Let It Be","Beatles"};
    MusicPlayer& mp1=Singleton<MusicPlayer>::instance(mpd1);
    ASSERT_EQUAL(mp1.getOne(),1);
    ASSERT_EQUAL(mp1.getAtomicCounter(),1);
    mp1.play();
    delete &mp1;

END_UNIT

UNIT(MusicPlayer_two_players)

    MusicPlayerData mpd1={"Let It Be","Beatles"};
    MusicPlayerData mpd2={"All You Need Is Love","Beatles"};
    MusicPlayer& mp1=Singleton<MusicPlayer>::instance(mpd1);
    mp1.setAtomicCounter(1);
    MusicPlayer& mp2=Singleton<MusicPlayer>::instance(mpd2);
    ASSERT_EQUAL(mp1.getOne(),1);
    ASSERT_EQUAL(mp1.getAtomicCounter(),2);
    ASSERT_EQUAL(mp2.getAtomicCounter(),2);
    delete &mp1;

END_UNIT

TEST_SUITE(MusicPlayer Tests)
    TEST(MusicPlayer_one_player)
    TEST(MusicPlayer_two_players)
END_SUITE

