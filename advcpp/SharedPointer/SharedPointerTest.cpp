#include "mu_test.h"
#include "SharedPointer.h"
#include "Cat.h"
#include "RedheadCat.h"

UNIT(SharedPointer_test1)
    SharedPointer<Cat> p1;
    ASSERT_THAT(p1.getMCounter()==2);

    SharedPointer<Cat> p2(p1);
    ASSERT_THAT(p2.getMCounter()==3);

    SharedPointer<Cat> p(new Cat("Garfield"));

    ASSERT_THAT(p.getMCounter()==1);

    SharedPointer<Cat> q=p;
    ASSERT_THAT(q.getMCounter()==2);

    SharedPointer<Cat> w(q);
    ASSERT_THAT(w.getMCounter()==3);

    SharedPointer<Cat> r(new Cat("Hello Kitty"));
    ASSERT_THAT(r.getMCounter()==1);

    r=p;

    SharedPointer<Cat> pRet=p;
    ASSERT_THAT(r==p);
    ASSERT_EQUAL("Garfield",p->getName());
    ASSERT_EQUAL("Garfield",q->getName());
    ASSERT_EQUAL("Garfield",w->getName());
    ASSERT_EQUAL("Garfield",pRet->getName());
    
END_UNIT

UNIT(SharedPointer_base_derived_test1)

    SharedPointer<Cat> b(new Cat("Hello1"));
    SharedPointer<Cat> d(new RedHeadCat("Kitty1"));
    ASSERT_EQUAL("Hello1",b->getName());
    ASSERT_EQUAL("Kitty1",d->getName());

    ASSERT_EQUAL(static_cast<bool>(b)  , true) ;
    ASSERT_THAT(b!=d);
    b=d;
    ASSERT_THAT(b==d);
    ASSERT_EQUAL("Kitty1",b->getName());
    ASSERT_EQUAL("Kitty1",d->getName());
END_UNIT

UNIT(SharedPointer_base_derived_test2)
    SharedPointer<Cat> b(new Cat("Cat"));
    SharedPointer<RedHeadCat> d(new RedHeadCat("Red"));
    b=d;
    ASSERT_THAT(b==d);
END_UNIT

UNIT(SharedPointer_bool_op)
    SharedPointer<Cat> q;
    if(q){
        ASSERT_THAT(false);
    }

    SharedPointer<Cat> p(new Cat("Garfield"));    
    if(p)
    {
        ASSERT_THAT(true);
    }
    else
    {
        ASSERT_THAT(false);
    }
    q = p;
    if(q)
    {
        ASSERT_THAT(true);
    }

    SharedPointer<Cat> r(new Cat("Hello Kitty"));
    r=p;
    ASSERT_THAT(r == p);        
    
END_UNIT

UNIT(SharedPointer_reset_test)
    SharedPointer<Cat> b(new Cat("Hello1"));
    ASSERT_THAT(b!=0);
    ASSERT_EQUAL("Hello1",b->getName());
    SharedPointer<Cat> d(new Cat("Kitty1"));
    ASSERT_THAT(b!=d);

    b.reset(d);
    ASSERT_THAT(b!=0);
    ASSERT_THAT(b==d);

END_UNIT

UNIT(SharedPointer_swap_test)
    SharedPointer<Cat> b(new Cat("Hello1"));
    SharedPointer<Cat> d(new RedHeadCat("Kitty1"));

    ASSERT_EQUAL("Hello1",b->getName());    
    ASSERT_EQUAL("Kitty1",d->getName());   

    b.swap(d);
    ASSERT_THAT(b!=0);
    ASSERT_THAT(d!=0);
    ASSERT_THAT(b!=d);

    ASSERT_EQUAL("Kitty1",b->getName());    
    ASSERT_EQUAL("Hello1",d->getName());    

END_UNIT

TEST_SUITE(SharedPointer Tests)
    
    TEST(SharedPointer_test1)
    TEST(SharedPointer_base_derived_test1)
    TEST(SharedPointer_base_derived_test2)    
    TEST(SharedPointer_reset_test)
    TEST(SharedPointer_bool_op)
    TEST(SharedPointer_swap_test)


END_SUITE

