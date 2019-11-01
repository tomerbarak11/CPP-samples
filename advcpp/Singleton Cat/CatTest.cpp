#include "mu_test.h"
#include "Cat.h"
#include "Singleton.h"

UNIT(MusicPlayer_one_player)
    CatData cd1={"Garfield",11};
    Cat& c1=Singleton<Cat>::instance(cd1);
    ASSERT_EQUAL(c1.getOne(),1);
    ASSERT_EQUAL(c1.getAtomicCounter(),1);
    delete &c1;

END_UNIT

UNIT(MusicPlayer_two_players)
    CatData cd1={"Mitzi",6};
    CatData cd2={"Pitzi",5};

    Cat& c1=Singleton<Cat>::instance(cd1);
    c1.setAtomicCounter(1);
    Cat& c2=Singleton<Cat>::instance(cd2);
    ASSERT_EQUAL(c1.getOne(),1);
    ASSERT_EQUAL(c1.getAtomicCounter(),2);
    ASSERT_EQUAL(c2.getAtomicCounter(),2);
    delete &c1;

END_UNIT


TEST_SUITE(MusicPlayer Tests)
    TEST(MusicPlayer_one_player)
    TEST(MusicPlayer_two_players)
END_SUITE

